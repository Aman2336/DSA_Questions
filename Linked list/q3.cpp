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
node *reverseink(node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    int cnt = 0;
    node* temp = head;
    node* forw = NULL;
    node* prev = NULL;
    while(temp!=NULL && cnt < k)
    {
        forw = temp->next;
        temp->next = prev;
        prev= temp;
        temp = forw;
        cnt++;
    }
    if(forw!= NULL)
    {
        head->next = reverseink(forw,k);
    }
    return prev;
}
int main()
{
    node *head = takeinput();
    cout << "print ll  - " << endl;
    print(head);
    cout<<endl;

    int k;
    cin>>k;

    node* h2 = reverseink(head,k);
    print(h2);
}