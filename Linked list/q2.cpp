//middle element of ll
#include<iostream>
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
int getlength(node* head)
{
int count =0;
node* temp = head;
while(temp->next!=NULL)
{
    temp = temp->next;
    count++;
}
return count;
}
int middlell(node* head)
{
int l = getlength(head);
int ans = l/2;
int count = 0;
node* temp = head;
while(count < ans)
{
   temp =temp -> next; 
   count++;
}
return temp->data;
}
int main()
{
node* head = takeinput();
print(head);
cout<<endl;
int h1 = middlell(head);
cout<<h1<<endl;
}