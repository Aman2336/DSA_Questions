#include <iostream>
#include <queue>
#include <map>
using namespace std;
class node
{
public:
    int data;
    node *right;
    node *left;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
int find(int *in, int k, int n)
{

    for (int i = 0; i < n; i++)
    {
        if (in[i] == k)
        {
            return i;
        }
    }
    return -1;
}
void levelorder(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *frontnode = q.front();
        q.pop();
        if (frontnode == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << frontnode->data << " ";
            if (frontnode->left)
            {
                q.push(frontnode->left);
            }
            if (frontnode->right)
            {
                q.push(frontnode->right);
            }
        }
    }
}
node *solve(int *pre, int *in, int ins, int ine, int &preindex, int n)
{
    if (preindex >= n || ins > ine)
    {
        return NULL;
    }
    int element = pre[preindex++];
    node *root = new node(element);
    int pos = find(in, element, n);
    root->left = solve(pre, in, ins, pos - 1, preindex, n);
    root->right = solve(pre, in, pos + 1, ine, preindex, n);
    return root;
}
node *buildtree1(int *pre, int *in, int n)
{
    int preindex = 0;
    node *root = solve(pre, in, 0, n - 1, preindex, n);
    return root;
}
void createmap(int *in, int n, map<int, int> &nodestoindex)
{
    for (int i = 0; i < n; i++)
    {
        nodestoindex[in[i]] = i;
    }
}
node *solve(int *post, int *in, int ins, int ine, int &postindex, int n, map<int, int> &nodestoindex)
{
    if (postindex < 0 || ins > ine)
    {
        return NULL;
    }
    int element = post[postindex--];
    int pos = nodestoindex[element];
    node *root = new node(element);
    root->right = solve(post,in,pos+1,ine,postindex,n,nodestoindex);
    root->left = solve(post,in,ins,pos-1,postindex,n,nodestoindex);
    
return root;
}
node *buildtree2(int *post, int *in, int n)
{
    int postindex = n - 1;
    map<int, int> nodestoindex;
    createmap(in, n, nodestoindex);
    node *root = solve(post, in, 0, n - 1, postindex, n, nodestoindex);
    return root;
}
int main()
{
    int pre[] = {0, 1, 3, 4, 2, 5};
    int in[] = {3, 1, 4, 0, 5, 2};
    int post[] = {3, 4, 1, 5, 2, 0};
    node *root = buildtree1(pre, in, 6);
    node *root1 = buildtree2(post, in, 6);
    levelorder(root1);
    cout << endl;
    return 0;
}