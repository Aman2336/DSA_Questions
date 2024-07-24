//2 sum
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
void inorder(vector<int> &ans, node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(ans, root->left);
    ans.push_back(root->data);
    inorder(ans, root->right);
}
bool twosum(node *root, int target)
{
    // if (root == NULL)
    // {
    //     return true;
    // }
    // if (root->data + root->left->data == target && root->data + root->right->data == target)
    // {
    //     return true;
    // }
    // bool ans1 = twosum(root->left, target);
    // bool ans2 = twosum(root->right, target);
    // return ans1 || ans2;
    vector<int> ans;
    inorder(ans, root);
    int i = 0;
    int j = ans.size() - 1;
    int sum = 0;
    while (i <= j)
    {
        sum = ans[i] + ans[j];
        if (sum == target)
        {
            return 1;
        }
        else if (sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return 0;
}
int main()
{
    node *root = NULL;
    takeinput(root);
    levelorder(root);
    cout << endl;
    if (twosum(root, 40))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}