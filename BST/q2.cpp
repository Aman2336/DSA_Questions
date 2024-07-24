//kth smalllest node in bst
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
int solve(node* root,int &i,int k){
    if(root == NULL){
        return -1;
    }
    int left = solve(root->left,i,k);
    if(left != -1){
        return left;
    }
    i++;
    if (i == k){
        return root->data;
    }
    int right = solve(root->right,i,k);
    if(right != -1){
        return right;
    }
}
int kthsmallestelement(node* root,int k){
    int i = 0;
    int ans = solve(root,i,k);
    return ans;
}
int main()
{
    node *root = NULL;
    takeinput(root);
    levelorder(root);
    cout << endl;
    cout<<kthsmallestelement(root,3);
}