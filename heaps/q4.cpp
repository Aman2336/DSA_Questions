#include <iostream>
#include <vector>
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
void inorder(node *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
void fillpreorder(node *&root, vector<int> in, int &index)
{
    if (root == NULL)
    {
        return;
    }
    root->data = in[index++];
    fillpreorder(root->left, in, index);
    fillpreorder(root->right, in, index);
}
node *treetoheap(node *root)
{
    vector<int> in;
    inorder(root, in);
    int index = 0;
    fillpreorder(root, in, index);
    return root;
}
int main()
{
    node *root = NULL;
    takeinput(root);
    levelorder(root);
    cout << endl;

    return 0;
}