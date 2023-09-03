//merge 2 sorted ll
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
node *mergesort(node *head1, node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    node *curr1 = head1->next;
    node *curr2 = head2->next;
    node *prev1 = head1;
    node *prev2 = head2;

    while (prev2 != NULL && curr1 != NULL)
    {
        if (prev2->data >= prev1->data && prev2->data <= curr1->data)
        {
            prev1->next = prev2;
            curr2 = prev2->next;
            prev2->next = curr1;

            prev1 = prev2;
            prev2 = curr2;
        }
        else
        {
            prev1 = prev1->next;
            curr1 = curr1->next;

//important

            if(curr1 == NULL)
            {
                prev1->next = prev2;
                return head1;
            }
        }
    }
    return head1;
}
int main()
{
    cout << "enter ll 1 -" << endl;
    node *head1 = takeinput();
    cout << "enter ll 2 -" << endl;
    node *head2 = takeinput();
    cout << "ll 1 -" << endl;
    print(head1);
    cout << "ll 2 -" << endl;
    print(head2);
    cout << endl;
    node *h3 = mergesort(head1, head2);
    print(h3);
}