//merge sort
#include <iostream>
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
node *findmid(node *head)
{
    node *fast = head->next;
    node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
node *merge(node *head1, node *head2)
{
    //just like arrays
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    node *temp1 = head1;
    node *next1 = temp1->next;
    node *temp2 = head2;
    node *next2 = temp2->next;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp2->data >= temp1->data && temp2->data <= next1->data)
        {
            temp1->next = temp2;
            next2 = temp2->next;
            temp2->next = next1;

            temp1 = temp2;
            temp2 = next2;
        }
        else
        {
            temp1 = temp1->next;
            next1 = next1->next;
            if (next1 == NULL)
        {
            temp1->next = temp2;
            return head1;
        }
        } 
    }
    return head1;
}
node* merge1(node* head1,node* head2)
{
    if(head1 == NULL)
    {
        return head2;
    }
    if(head2 == NULL)
    {
        return head1;
    }
    node* ans = new node(-1);

    node* temp = ans;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data < head2->data)
        {
            temp->next = head1;
            temp = head1;
            head1 = head1->next;
        }
        else{
             temp->next = head2;
            temp = head2;
            head2 = head2->next;
        }
    }
    while(head1!=NULL)
    {
        temp->next = head1;
            temp = head1;
            head1 = head1->next;
    }
     while(head2!=NULL)
    {
        temp->next = head2;
            temp = head2;
            head2 = head2->next;
    }
    ans = ans->next;
    return ans;
}

node *mergesort(node *head)
{
    if (head == NULL || head->next == NULL) // list is empty
    {
        return head;
    }
    node *mid = findmid(head);

    // 2 halves created;
    node *left = head;
    node *right = mid->next;
    mid->next = NULL;

    // sorting two halves using recursive calls
    left = mergesort(left);
    right = mergesort(right);

    // merge both ll
    node *result = merge1(left, right);

    return result;
}
int main()
{
    node *head = takeinput();
    print(head);
    cout << endl;
    node *h = mergesort(head);
    print(h);
}