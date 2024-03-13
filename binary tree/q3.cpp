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
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    int ans = max(rh, lh) + 1;
    return ans;
}
pair<bool, int> balancedfast(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> right = balancedfast(root->right);
    pair<bool, int> left = balancedfast(root->left);
    bool leftans = left.first;
    bool rightans = right.first;
    bool diff = abs(left.second - right.second) <= 1;
    pair<bool,int> ans;
    if (rightans && leftans && diff)
    {
        ans.first = true;
        ans.second = max(left.second , right.second )+1;
    }
    else
    {
        ans.first = false;
        ans.second = max(left.second , right.second )+1;
    }
    return ans;
}
bool balanced(node *root)
{
//     if (root == NULL)
//     {
//         return true;
//     }
//     bool rightans = balanced(root->right);
//     bool leftans = balanced(root->left);
//     bool diff = abs(height(root->left) - height(root->right)) <= 1;

//     if (rightans && leftans && diff)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
return balancedfast(root).first;
}
int main()
{
    // 1 2 3 4 -1 -1 5 -1 -1 6 7 -1 -1 -1 8 9 -1 -1 -1
    // 1 2 3 4 -1 -1 -1 -1 8 -1 -1
    node *root = NULL;
    root = buildtree(root);
    levelorder(root);
    cout << endl;
    if (balanced(root))
    {
        cout << "yess";
    }
    else
    {
        cout << "no";
    }
}