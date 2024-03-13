#include <iostream>
#include <queue>
#include <map>
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
node *kancestor(node *root, int k, int n)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n)
    {
        return root;
    }
    node *leftans = kancestor(root->left, k, n);
    node *rightans = kancestor(root->right, k, n);

    if (leftans != NULL && rightans == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT64_MAX;
            return root;
        }
        return leftans;
    }
    if (leftans == NULL && rightans != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT64_MAX;
            return root;
        }
        return rightans;
    }
    return NULL;
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelorder(root);
    cout << endl;
    node *ans = kancestor(root, 2, 4);
    cout << "2nd ancestor of 4 is " << ans->data << endl;
    return 0;
}