// reverse a linked list
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
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
void reverse1(node* &head,node* curr,node* prev)
{
    if(curr == NULL)
    {
       head = prev;
       return;
    }
    node* forw = curr->next;
    reverse1(head,forw,curr);
    curr->next = prev;
}
node *reverse(node *head)
{
 //   node* curr = head;
   // node* prev = NULL;
    //reverse1(head,curr,prev);
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    node *prev = NULL;
    node *curr = head;
    node *forw = NULL; 
    while (curr != NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
    //return head;
}
int main()
{
    node *head = takeinput();
    print(head);
    node *h1 = reverse(head);
    cout << endl;
    print(h1);
}