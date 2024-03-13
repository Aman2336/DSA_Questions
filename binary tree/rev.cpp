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
void print(node *root)
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
pair<int, int> solve(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;

    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}
pair<int, int> dnh(node *root)
{
    return solve(root);
}
pair<bool, int> solve1(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }
    pair<bool, int> left = solve1(root->left);
    pair<bool, int> right = solve1(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = root->data == left.second + right.second;

    pair<int,int> ans;

    if(op1 && op2 && op3){
        ans.first = 1;
        ans.second = left.second + right.second;
    }
    else{
        ans.first = 0;
    }
    return ans;
}
bool checksum(node *root)
{
    return solve1(root).first;
}
int main()
{
    node *root1 = NULL;
    root1 = buildtree(root1);
    print(root1);
    cout << endl;

    // node *root2 = NULL;
    // root2 = buildtree(root2);
    // print(root2);
    // cout << endl;

    // pair<int, int> p = dnh(root1);
    // cout << p.first << " " << p.second << " ";

    if(checksum(root1)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no";
    }
}