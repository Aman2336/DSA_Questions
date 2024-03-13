// topview and bottomview 
#include <iostream>
#include <queue>
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
vector<int> topview(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> nodes;
    queue<pair<node *, int> > q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        node *frontnode = temp.first;
        int hd = temp.second;
        if (nodes.find(hd) == nodes.end())
        {
            nodes[hd] = frontnode->data;
        }

        if (frontnode->left)
        {
            q.push(make_pair(frontnode->left, hd - 1));
        }
        if (frontnode->right)
        {
            q.push(make_pair(frontnode->right, hd + 1));
        }
    }
    for (auto i : nodes)
    {
        ans.push_back(i.second);
    }
    return ans;
}
vector<int> bottomview(node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int,int> nodes;
    queue<pair<node*,int> > q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();
        node* frontnode = temp.first;
        int hd = temp.second;

        nodes[hd] = frontnode->data;
        if(frontnode->left){
            q.push(make_pair(frontnode->left,hd-1));
        }
        if(frontnode->right){
            q.push(make_pair(frontnode->right,hd+1));
        }
    }
    for(auto i : nodes){
        ans.push_back(i.second);
    }
    return ans;
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelorder(root);
    cout << endl;
    // vector<int> v = topview(root);
    vector<int> v = bottomview(root);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
// 1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1