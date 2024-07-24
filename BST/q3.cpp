// inorder pred/suc.
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
node *inpred(node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            node *suc = minmax(temp->left).second;
            return suc;
            break;
        }
        if (temp->data > key)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->left;
        }
    }
}
node *insuc(node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            node *suc = minmax(temp->right).first;
            return suc;
            break;
        }
        if (root->data > key)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->left;
        }
    }
}
int main()
{
    node *root = NULL;
    takeinput(root);
    levelorder(root);
    cout << endl;
    node *ans1 = inpred(root, 4);
    node *ans2 = insuc(root, 4);
    cout << ans1->data << " " << ans2->data << endl;
}