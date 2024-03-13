#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *right;
    node *left;
    node(int data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
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
pair<bool, int> fast(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }
    pair<bool, int> left = fast(root->left);
    pair<bool, int> right = fast(root->right);

    bool ans1 = left.first;
    bool ans2 = right.first;

    bool ans3 = root->data == (left.second + right.second);

    pair<bool, int> ans;
    if (ans1 && ans2 && ans3)
    {
        ans.first = true;
        ans.second = 2*root->data;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}
bool checksumtree(node *root)
{
    return fast(root).first;
}
int main()
{
    // 3 2 -1 -1 1 -1 -1
    node *root = NULL;
    root = buildtree(root);
    levelorder(root);
    cout << endl;
    if (checksumtree(root))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}