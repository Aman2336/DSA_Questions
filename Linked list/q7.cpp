//sort 0s,1s,2s in a ll
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

public:
    node()
    {
        next = NULL;
    }
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
node *insertatend(node *head, int data)
{
    node *n = new node(data);
    if (head == NULL)
    {
        head = n;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    return head;
}
node *sort012(node *head)
{
    // approach 1
    /*int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data == 0)
        {
            count0++;
        }
        if(temp->data == 1)
        {
            count1++;
        }
        if(temp->data == 2)
        {
            count2++;
        }
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL)
    {
        if(count0!=0)
        {
            temp->data = 0;
            count0--;
        }
        else if(count1!=0)
        {
            temp->data = 1;
            count1--;
        }
        else if(count2!=0)
        {
            temp->data = 2;
            count2--;
        }
        temp = temp->next;
    }
return head;*/
    // approach 2
    node *temp = head;
    node *zero = new node(-1);
    node *one = new node(-1);
    node *two = new node(-1);
    node *temp0 = zero;     //tail of 0
    node *temp1 = one;      //tail of 1
    node *temp2 = two;      //tail of 2
    while (temp != NULL)
    {
        if (temp->data == 0 && temp0 != NULL)
        {
            insertatend(zero, temp->data);
            temp0 = temp0->next;
        }
        else if (temp->data == 1 && temp1 != NULL)
        {
            insertatend(one, temp->data);
            temp1 = temp1->next;
        }
        else if (temp->data == 2 && temp2 != NULL)
        {
            insertatend(two, temp->data);
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    // merge 3 ll
    // 0 ke liye handle kr lia
    if(one->next!=NULL)
    {
        temp0->next = one->next;
    }
    else{
        temp0->next = two->next;
    }
    temp1 -> next = two->next;
    temp2->next =NULL;
    head = zero->next;

    //delete dummy nodes
    delete zero;
    delete one;
    delete two;

    return head;
}
int main()
{
    node *head = takeinput();
    print(head);
    node *h = sort012(head);
    cout << endl;
    cout << "sorted 0,1,2" << endl;
    print(h);
}