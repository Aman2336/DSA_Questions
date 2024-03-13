// sum of longest bloodline
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
pair<int, int> sumheight(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<int, int> p = make_pair(0, root->data);
        return p;
    }
    pair<int, int> left = sumheight(root->left);
    pair<int, int> right = sumheight(root->right);

    int lh = left.first;
    int rh = right.first;
    int sum = lh > rh ? left.second : right.second;
    pair<int, int> ans;
    if (sum >= 0)
    {
        ans.first = max(lh, rh) + 1;
        ans.second = sum;
    }
    else
    {
        ans.first = max(lh, rh) + 1;
    }
    return ans;
}
void solve(node* root ,int len,int &maxlen,int sum,int &maxsum){

if(root == NULL){
    if(len > maxlen){
        maxlen = len;
        maxsum = sum;
    }
    else if(len == maxlen){
        maxsum = max(sum,maxsum);
    }
    return;
}
sum = sum + root->data;
solve(root->left,len+1,maxlen,sum,maxsum);
solve(root->right,len+1,maxlen,sum,maxsum);
}
int sum(node *root)
{
    // return sumheight(root).second;
    int sum=0;
    int maxsum = INT64_MIN;
    int len = 0;
    int maxlen = 0;

    solve(root,len,maxlen,sum,maxsum);
    return maxsum;
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelorder(root);
    cout<<endl;
    cout<<"longest bloodline : "<<sum(root);
        return 0;
}