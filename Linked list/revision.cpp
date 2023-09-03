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
// we have created this function with return type as node*
// because we will take input in this func and return head or address of first node
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
// print function that take head as argument and prints LL
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
node *insertatfirst(node *head, int data)
{
    node *n1 = new node(data);
    // LL is empty
    if (head == NULL)
    {
        head = n1;
    }
    else
    {
        n1->next = head;
        head = n1;
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
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    return head;
}
node *insertati(node *head, int data, int i)
{
    int count = 0;
    node *n = new node(data);
    if (i == 0)
    {
        if (head == NULL)
        {
            head = n;
            return head;
        }
        else
        {
            n->next = head;
            head = n;
            return head;
        }
    }
    node *temp = head;
    while (temp->next != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    n->next = temp->next;
    temp->next = n;
    return head;
}
node *deleteatfirst(node *head)
{
    if (head == NULL)
    {
        return head;
    }
    else
    {
        node *ptr = head;
        head = head->next;
        delete ptr;
        return head;
    }
}
node *deleteatend(node *head)
{
    if (head == NULL)
    {
        return head;
    }
    else
    {
        node *temp = head;
        node *ptr = temp->next;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            temp = temp->next;
        }
        temp->next = NULL;
        return head;
    }
}
node *deleteati(node *head, int i)
{
    int count = 0;
    if (i == 0)
    {
            node *ptr = head;
            head = head->next;
            delete ptr;
            return head;
        
    }
    node *temp = head;
    while (temp->next!= NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    node *a = temp->next;
    node *b = a->next;
    temp->next = b;
    delete a;
    return head;
}
int main()
{
    node *head = takeinput();
    cout << "printing  ll : " << endl;
    print(head);

    /*node *h = insertatfirst(head, 0);
        cout << endl;
        cout << "printing  ll after insertion : " << endl;
        print(h);

        node *h1 = insertatend(head, 7);
        cout << endl;
        cout << "printing  ll after insertion : " << endl;
        print(h1);*/

    /*node *h2 = insertati(head, 8, 2);
    cout << endl;
    cout << "printing  ll after insertion : " << endl;
    print(h2);*/

    /*node *h3 = deleteatfirst(head);
    cout << endl;
    cout << "printing  ll after deletion : " << endl;
    print(h3);

    node *h4 = deleteatend(head);
    cout << endl;
    cout << "printing  ll after deletion : " << endl;
    print(h4);*/

    node *h5 = deleteati(head, 3);
    cout << endl;
    cout << "printing  ll after deletion : " << endl;
    print(h5);
}