// vertical order
#include <iostream>
#include <queue>
#include <vector>
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
vector<int> vertical(node *root)
{
    map<int, map<int, vector<int> > >  nodes;
    queue<pair<node *, pair<int, int> > > q;
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<node *, pair<int, int> > temp = q.front();
        q.pop();
        node *frontnode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        nodes[hd][level].push_back(frontnode->data);

        if (frontnode->left)
        {
            q.push(make_pair(frontnode->left, make_pair(hd - 1, level + 1)));
        }
        if (frontnode->right)
        {
            q.push(make_pair(frontnode->right, make_pair(hd + 1, level + 1)));
        }
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }

    return ans;
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelorder(root);
    cout << endl;
    vector<int> v = vertical(root);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}