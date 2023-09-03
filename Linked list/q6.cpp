// remove duplicates from sorted and unsorted ll
#include <iostream>
#include <map>
using namespace std;
class node
{
public:
    int data;
    node *next;

public:
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
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
node *removeduplicates(node *head)
{
    if (head == NULL)
    {
        return head;
    }
    node *temp = head;
    while (temp != NULL)
    {
        // temp->next isliye check kr rhe h
        // kyuki hm temp->next->next kr rhe h agr ye null hua to segmentation fault
        if (temp->next != NULL && temp->data == temp->next->data)
        {
            node *n = temp->next;
            node *next_next = temp->next->next;
            delete n;
            temp->next = next_next;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}
node *removeduplicates2(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        node *temp = curr->next;
        node *prev = curr;
        while (temp != NULL)
        {

            if (temp->data == curr->data)
            {

                node *n = temp;
                node *n2 = temp->next;
                delete n;
                prev->next = n2;
            }
            else{
            temp = temp->next;
            prev = prev->next;
            }
        }
        curr = curr->next;
    }
    return head;
}
node *removeduplicates3(node *head)
{
    if (head == NULL)
    {
        return head;
    }
    map<node *, bool> visited;
    node *temp = head->next;
    node *prev = head;
    while(temp!=NULL)
    {
        if(visited[temp])
        {
            node* n = temp;
            prev->next = temp->next->next;
            delete n;
        }
        visited[temp] =1;
        prev = temp;
        temp = temp->next;
    }
    return head;
}
int main()
{
    /*node *n1 = new node(1);
     node *n2 = new node(2);
    node *n3 = new node(2);
    node *n4 = new node(3);
    node *n5 = new node(4);
    node *n6 = new node(4);
    node *n7 = new node(4);
    node *n8 = new node(4);
    node *n9 = new node(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;*/
    node *head = takeinput();
    print(head);
    cout << endl;
    node *d = removeduplicates2(head);
    print(d);
}