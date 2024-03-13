// left and right view
#include <iostream>
#include <queue>
#include <map>
#include<vector>
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
void solve(node* root,int lvl,vector<int> & ans){
    if( root == NULL){
        return;
    }
    if(lvl == ans.size())
    {
        ans.push_back(root->data);
    }
    solve(root->left,lvl+1,ans);
    solve(root->right,lvl+1,ans);
}
vector<int> leftview(node* root){
    vector<int> ans;
    int lvl = 0;
    solve(root,lvl,ans);
    return ans;
}
int main(){
    node* root = NULL;
    root = buildtree(root);
    levelorder(root);
    cout<<endl;
     vector<int> v = leftview(root);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}