// BST to Sorted LL
#include <iostream>
#include <queue>
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
node *insertintobst(node *root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }
    if (root->data > data)
    {
        root->left = insertintobst(root->left, data);
    }
    else
    {
        root->right = insertintobst(root->right, data);
    }
    return root;
}
void takeinput(node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertintobst(root, data);
        cin >> data;
    }
}
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
void inorder(node *root, vector<node *> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root);
    inorder(root->right, ans);
}
node *flatten(node *root)
{
    vector<node *> ans;
    inorder(root, ans);
    node *curr = ans[0];
    node *curr1 = curr;
    int n = ans.size();
    for (int i = 1; i < n; i++)
    {
        node *temp = ans[i];
        curr1->left = NULL;
        curr1->right = temp;
        curr1 = temp;
    }
    curr1->left = NULL;
    curr1->right = NULL;
    return curr;
}
node *printll(node *root)
{
    node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
}
int main()
{
    node *root = NULL;
    takeinput(root);
    levelorder(root);
    cout << endl;
    node *ans = flatten(root);
    printll(ans);
}