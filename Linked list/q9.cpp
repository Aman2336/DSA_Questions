//check whether ll is palindrome or not
#include <iostream>
#include <vector>
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
void reverse1(node *&head, node *curr, node *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    node *forw = curr->next;
    reverse1(head, forw, curr);
    curr->next = prev;
}
node *reversell(node *head)
{
    //   node* curr = head;
    // node* prev = NULL;
    // reverse1(head,curr,prev);
    if (head == NULL || head->next == NULL)
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
    // return head;
}
bool ispalindrome(node *head)
{
    node *reverse = reversell(head);
    node *temp1 = head;
    node *temp2 = reverse;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            return 0;
        }
        else{
        temp1 = temp1->next;
        temp2 = temp2->next;
        }
    }
    return 1;
}
bool palindrome(node *head)
{
    vector<int> arr;
    node *temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    int s = 0;
    int e = arr.size() - 1;
    while (s <= e)
    {
        if (arr[s] != arr[e]) //imp
        {
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}
int main()
{
    node *head = takeinput();
    print(head);
    if (ispalindrome(head))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}
