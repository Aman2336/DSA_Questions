#include<iostream>
#include<queue>
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
pair<int,int> solve(node* root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);

    pair<int,int> res;
    res.first = root->data + left.second + right.second;
    res.second = max(left.first,left.second) + max(right.first,right.second);
    return res;
}
int maxsum(node* root){
    pair<int,int> ans = solve(root);
    return max(ans.first,ans.second);
}
int main(){
    node *root = NULL;
    root = buildtree(root);
    levelorder(root);
    cout<<endl;
    cout<<"max sum of non adj nodes is - "<<maxsum(root);
    return 0;
}