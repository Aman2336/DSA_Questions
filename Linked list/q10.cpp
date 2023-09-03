// add 2 no.'s represented by lls
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
node *reverse(node *head)
{
    node *curr = head;
    node *prev = NULL;
    node *forw = NULL;

    while (curr != NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}
void insertatend(node* &head,int val)
{
    node* n = new node(val);
    if(head == NULL)
    {
        head = n;
    }
    else{
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    }
}
node *add(node *head1, node *head2)
{
    node *reverse1 = reverse(head1);
    node *reverse2 = reverse(head2);

    node *temp1 = reverse1;
    node *temp2 = reverse2;

    int carry = 0;

    node *temp3 = NULL;
    while (temp1 != NULL && temp2 != NULL)
    {
        int sum = temp1->data + temp2->data + carry;
        int digit = sum % 10;
        carry = sum/ 10;
        insertatend(temp3,digit);
        temp1 = temp1->next;
        temp2 = temp2->next;
        
    }
    while (temp1 != NULL)
    {
        int sum = temp1->data + carry;
        int digit= sum % 10;
        carry = sum/ 10;
        
        insertatend(temp3,digit);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        int sum = temp2->data + carry;
        int digit = sum % 10;
        carry = sum/ 10;
      
       insertatend(temp3,digit);
        temp2 = temp2->next;
    }
    while (carry != 0)
    {
        int sum = carry;
        int digit= sum % 10;
        carry = sum/ 10;
        node *n = new node(digit);
        insertatend(temp3,sum);
       
    }
    node *temp4 = reverse(temp3);
    return temp4;
}
int main()
{
    cout << "enter ll 1 - " << endl;
    node *h1 = takeinput();
    cout << "enter ll 2 - " << endl;
    node *h2 = takeinput();
    node *h3 = add(h1, h2);
    cout << "adding given lls - " << endl;
    print(h3);
}