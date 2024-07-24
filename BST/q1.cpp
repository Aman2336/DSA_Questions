// validate bst
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
// bool validate(node *root)
// {
//     if (root == NULL || (root->left == NULL && root->right == NULL))
//     {
//         return true;
//     }
//     if (root->left->data < root->data && root->right->data > root->data)
//     {
//         bool ans1 = validate(root->left);
//         bool ans2 = validate(root->right);
//         if (ans1 && ans2)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     else{
//         return false;
//     }
// }
bool isbst(node *root, long long int min, long long int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= min && root->data <= max)
    {
        bool left = isbst(root->left, min, root->data);
        bool right = isbst(root->right, root->data, max);
        return left && right;
    }
    else{
        return false;
    }
}
bool validate(node *root)
{
    return isbst(root, -12345674567, 123456784567);
}
int main()
{
    node *root = NULL;
    takeinput(root);
    // root = buildtree(root);
    levelorder(root);
    cout << endl;
    if (validate(root))
    {
        cout << "yes it is bst";
    }
    else
    {
        cout << "it is not";
    }
}