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
void inorder(node *r1, node *r2, vector<int> &a1, vector<int> &a2)
{
    if (r1 == NULL || r2 == NULL)
    {
        return;
    }
    inorder(r1->left, r2->left, a1, a2);
    a1.push_back(r1->data);
    a2.push_back(r2->data);
    inorder(r1->right, r2->right, a1, a2);
}
void mergearray(vector<int> a1, vector<int> a2, vector<int> &ans)
{
    int i = 0;
    int j = 0;
    while (j < a2.size() && i < a1.size())
    {
        if (a1[i] < a2[j])
        {
            ans.push_back(a1[i]);
            i++;
        }
        else
        {
            ans.push_back(a2[j]);
            j++;
        }
    }
    while (i < a1.size())
    {

        ans.push_back(a1[i]);
        i++;
    }
     while (j < a2.size())
    {

        ans.push_back(a2[j]);
        j++;
    }
}
node* inordertobst(int s,int e,vector<int> ans){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    node* newroot = new node(ans[mid]);
    newroot->left = inordertobst(s,mid-1,ans);
    newroot->right = inordertobst(mid+1,e,ans);
    return newroot;
}
node *merge(node *r1, node *r2)
{
    vector<int> a1;
    vector<int> a2;
    inorder(r1, r2, a1, a2);
    vector<int> ans;
    mergearray(a1, a2, ans);
    node* temp = inordertobst(0,ans.size()-1,ans);
    return temp;
    
}
int main()
{
    node *root1 = NULL;
    node *root2 = NULL;
    takeinput(root1);
    takeinput(root2);
    levelorder(root1);
    cout << endl;
    levelorder(root2);
    cout << endl;
    node* ans = merge(root1,root2);
    levelorder(ans);
    cout<<endl;
    return 0;
}
// 2 4 5 7 10 11 15 21