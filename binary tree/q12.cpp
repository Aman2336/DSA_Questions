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
node *lca(node *root, int n1, int n2)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *leftans = lca(root->left, n1, n2);
    node *rightans = lca(root->right, n1, n2);

    if (leftans != NULL && rightans != NULL)
    {
        return root;
    }
    else if (leftans != NULL && rightans == NULL)
    {
        return leftans;
    }
    else if (leftans == NULL && rightans != NULL)
    {
        return rightans;
    }
    else{
        return NULL;
    }
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelorder(root);
    cout<<endl;
    node* ans = lca(root,3,6);
    cout<<ans->data<<" ";
}
