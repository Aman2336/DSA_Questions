// kth smallest element

// and is tree a heap

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

int kthsmall(int *arr, int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int totalnodes(node *root)
{
    int cnt = 0;
    if (root == NULL)
    {
        return 0;
    }
    int leftans = totalnodes(root->left);
    int rightans = totalnodes(root->right);
    return 1 + leftans + rightans;
}
bool isCBT(node *root, int i, int cnt)
{
    if (root == NULL)
    {
        return true;
    }
    if (i >= cnt)
    {
        return false;
    }
    bool leftans = isCBT(root->left, 2 * i + 1, cnt);
    bool rightans = isCBT(root->right, 2 * i + 2, cnt);
    return leftans && rightans;
}
bool maxheap(node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    if (root->left != NULL && root->right == NULL)
    {
        return root->data > root->left->data;
    }
    bool left = maxheap(root->left);
    bool right = maxheap(root->right);
    return left && right && (root->data > root->left->data && root->data > root->right->data);
}
bool istreeheap(node *root)
{
    int index = 0;
    int n = totalnodes(root);
    if (isCBT(root, index, n) && maxheap(root))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    // int arr[] = {10, 12, 34, 1, 5};
    // cout << kthsmall(arr, 5, 4);
    node *root = NULL;
    root = buildtree(root);
    if(istreeheap(root))
    {
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
}