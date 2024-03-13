#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
node *buildtree(node *root)
{
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    root->left = buildtree(root->left);
    root->right = buildtree(root->right);
    return root;
}
void levelorder(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
node *solve(node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    node *left = solve(root->left);
    node *right = solve(root->right);
    root->left = NULL;
    root->right = left;
    left->right = right;
    return root;
}
void flatten(node *root)
{
    node *head = solve(root);
    root = head;
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelorder(root);
    cout << endl;
    flatten(root);
    levelorder(root);
    return 0;
}