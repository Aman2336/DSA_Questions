// boundary traversal
#include <iostream>
#include <queue>
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
void leftpart(node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left != NULL)
    {
        leftpart(root->left, ans);
    }
    else
    {
        leftpart(root->right, ans);
    }
}
void leaves(node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    leaves(root->left, ans);
    leaves(root->right, ans);
}
void rightpart(node *root, vector<int> &ans)
{
    if (root == NULL || (root->right == NULL && root->left == NULL))
    {
        return;
    }
    if (root->right)
    {
        rightpart(root->right, ans);
    }
    else
    {
        rightpart(root->left, ans);
    }
    ans.push_back(root->data);
}
vector<int> boundary(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    ans.push_back(root->data);
    leftpart(root->left, ans);
    leaves(root->left, ans);
    leaves(root->right, ans);
    rightpart(root->right, ans);
    return ans;
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelorder(root);
    cout << endl;
    vector<int> v = boundary(root);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}