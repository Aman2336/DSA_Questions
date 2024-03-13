#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

public:
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int hleft = height(root->left);
    int hright = height(root->right);
    int ans = max(hleft, hright);
    return ans + 1;
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
pair<int,int> diameterfast(node* root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> left = diameterfast(root->left);
    pair<int,int> right = diameterfast(root->right);

    int one = left.first;
    int two = right.first;
    int three = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(one,max(two,three));
    ans.second = max(left.second,right.second) + 1;

    return ans;
}
int diameter(node *root)
{
    // if (root == NULL)
    // {
    //     return 0;
    // }
    // int one = diameter(root->left);
    // int two = diameter(root->right);
    // int third = height(root->left) + height(root->right) + 1;
    // int ans = max(one, two);
    // int ans2 = max(ans,third);
    // return ans2;
    return diameterfast(root).first;
}
int main()
{
    // 1 2 3 4 -1 -1 5 -1 -1 6 7 -1 -1 -1 8 9 -1 -1 -1
    node *root = NULL;
    root = buildtree(root);
    levelorder(root);
    cout << endl;
    // cout<<"height of tree : "<<height(root);
    cout << "diameter of tree : " << diameter(root);
}