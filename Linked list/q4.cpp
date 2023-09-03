//detect cycle in linked list and floyd cycle algo
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
bool detectcycle(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    map<node *, bool> visited;
    node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return 1;
        }
        visited[temp] = 1;
        temp = temp->next;
    }
    return 0;
}
node *floydcycle(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *slow = head;
    node *fast = head;
    node *temp = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}
node *startnode(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *intersection = floydcycle(head);
    node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}
int main()
{
    node *n1 = new node(10);
    node *n2 = new node(20);
    node *n3 = new node(30);
    node *n4 = new node(40);
    node *n5 = new node(50);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n3;
    node *head = n1;
    node *a  = startnode(head);
    cout<<a->data<<endl;
}