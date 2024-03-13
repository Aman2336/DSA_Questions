#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

public:
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
    cout << "enter data" << endl;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter the data inserting in left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "enter the data inserting in right of " << data << endl;
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
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void rlevelorder(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL); // seperator

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
            if (temp->right)
            {
                q.push(temp->right);
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
        }
    }
}
// approach 1
int countleaves(node *root)
{
    int count = 0;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp->left == NULL && temp->right == NULL)
        {
            count++;
        }
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
    return count;
}
void inorder1(node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    inorder1(root->left, count);
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    inorder1(root->right, count);
}
int countleaves1(node *root)
{
    int count = 0;
    inorder1(root, count);
    return count;
}
int main()
{
    node *root = NULL;
    // 1 2 3 4 -1 -1 5 -1 -1 6 7 -1 -1 -1 8 9 -1 -1 -1
    root = buildtree(root);
    rlevelorder(root);
    cout << endl;
    // inorder(root);
    // cout << endl;
    // preorder(root);
    // cout << endl;
    // postorder(root);
    // cout << "no. of leaves are " << countleaves1(root);
    return 0;
}