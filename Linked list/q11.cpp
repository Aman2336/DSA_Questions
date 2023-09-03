// clone a linked list
#include <iostream>
#include <map>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *random;
    node(int data)
    {
        this->data = data;
        next = NULL;
        random = NULL;
    }
};
node *takeinput()
{
    int data;
    cin >> data;
    node *head = NULL;
    while (data != -1)
    {
        node *n = new node(data);
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
        cin >> data;
    }
    return head;
}
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void insertatend(node *&head, int data)
{
    node *n = new node(data);
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}
// this method TC - O(n^2) and SC - O(n)
node *clone(node *head)
{
    // step 1 create a clone linked list without random
    node *c = NULL;
    node *temp = head;
    while (temp != NULL)
    {
        insertatend(c, temp->data);
        temp = temp->next;
    }

    // step2 now code for setting random pointer int clone linked list
    map<node *, node *> mapping;
    node *temp2 = c;
    temp = head;
    while (temp != NULL && temp2 != NULL)
    {
        mapping[temp] = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }
    temp = head;
    temp2 = c;
    while (temp != NULL)
    {
        temp2->random = mapping[temp->random];
        temp = temp->next;
    }
    return c;
}
node *clone1(node *head)
{
    // step1 clone ll
    node *temp = head;
    node *c = NULL;
    while (temp != NULL)
    {
        insertatend(c, temp->data);
        temp = temp->next;
    }

    // step2 physical mapping between clone and original
    temp = head;
    node *temp1 = c;

    while (temp != NULL && temp1 != NULL)
    {
        // setting pointer for original list for mapping
        node *next1 = temp->next;
        temp->next = temp1;
        temp = next1;

        // just opposite of original list
        next1 = temp1->next;
        temp1->next = temp;
        temp1 = next1;
    }
    // step3 copy random pointer
    temp = head;
    temp1 = c;
    while (temp != NULL)
    {
        // important
        if (temp->next != NULL)
        {
                temp->next->random = temp->random ? temp->random->next : temp->random;   
        }
        if(temp->next!=NULL)
        {
        temp = temp->next->next;
        }
    }

    // step4 revert back changes
    temp = head;
    temp1 = c;

    while (temp != NULL && temp1 != NULL)
    {
        // original ll
        temp->next = temp1->next;
        temp = temp->next;

        // clone ll(just opp)
        if(temp!=NULL)
        {
        temp1->next = temp->next;
        }
    
        temp1 = temp1->next;
    }
    return c;
}
int main()
{
    node *n1 = new node(10);
    node *n2 = new node(20);
    node *n3 = new node(30);
    node *n4 = new node(40);
    node *n5 = new node(50);
    n1->next = n2;
    n1->random = n3;
    n2->next = n3;
    n2->random = n1;
    n3->next = n4;
    n3->random = n5;
    n4->next = n5;
    n4->random = n2;
    n5->random = n4;
    node *head = n1;
    cout<<"original ll -"<<endl;
    print(head);
    cout<<endl;
    node* h = clone1(head);
    cout<<"cloned ll -"<<endl;
    print(h);
}