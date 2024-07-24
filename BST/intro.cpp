// binary search tree
// intro
// search in bst
// insertion
// deletion
// min/max value in bst
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
bool search(node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }
    if (root->data > data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}
pair<node *, node *> minmax(node *root)
{
    pair<node *, node *> p;
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    p.first = temp;
    temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    p.second = temp;
    return p;
}
node *deletenode(node *root, int target)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == target)
    {
        // 0child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1child
        // left
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        // right
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        // 2child
        if(root->left != NULL && root->right != NULL){
            node* min = minmax(root->right).first; //inorder successor
            root->data = min->data;
            root->right = deletenode(root->right,min->data);
            return root;
        }
    }
    else if (root->data > target)
    {
        root->left = deletenode(root->left, target);
        return root;
    }
    else
    {
        root->right = deletenode(root->right, target);
        return root;
    }
}
int main()
{
    node *root = NULL;
    takeinput(root);
    levelorder(root);
    cout << endl;
    // if (search(root, 1))
    // {
    //     cout << "found";
    // }
    // else
    // {
    //     cout << "not found";
    // }
    // pair<node *, node *> ans = minmax(root);
    // cout << ans.first->data << " " << ans.second->data << " ";
    node* root1 = deletenode(root,5);
    levelorder(root1);
    cout<<endl;
    return 0;
}