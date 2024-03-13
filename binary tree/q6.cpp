// zig zag traversal
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
vector<int> zigzag(node *root)
{
    vector<int> ans;
    bool islr = true;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);
        for (int i = 0; i < size; i++)
        {
            node *frontnode = q.front();
            q.pop();
            int index = islr ? i : size - i - 1;
            temp[index] = frontnode->data;

            if (frontnode->left)
            {
                q.push(frontnode->left);
            }
            if (frontnode->right)
            {
                q.push(frontnode->right);
            }
        }
        islr = !islr;
        for (auto i : temp)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
int main()
{
    // 1 2 -1 -1 3 4 -1 -1 5 -1 -1
    node *root = NULL;
    root = buildtree(root);
    levelorder(root);
    cout << endl;
    vector<int> order = zigzag(root);
    for (int i = 0; i < order.size(); i++)
    {
        cout << order[i] << " ";
    }
}