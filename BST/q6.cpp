// normal to balanced bst
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

void inorder(node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
node *inordertobst(int s, int e, vector<int> ans)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s+e)/2;
    node *newroot = new node(ans[mid]);
    newroot->left = inordertobst(s, mid - 1, ans);
    newroot->right = inordertobst(mid + 1, e, ans);
    return newroot;
}
node *balanced(node *root)
{
    vector<int> ans;
    inorder(root, ans);
    node *ans1 = inordertobst(0, ans.size() - 1, ans);
    return ans1;
}
int main()
{
    node *root = NULL;
    takeinput(root);
    levelorder(root);
    cout << endl;
    node *ans = balanced(root);
    levelorder(ans);
    cout << endl;
}