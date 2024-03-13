#include <iostream>
#include <queue>
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
        right = NULL;
        left = NULL;
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
bool identical(node* r1,node* r2){
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if(r1 != NULL && r2 == NULL){
        return false;
    }
    if(r1 == NULL && r2 != NULL){
        return false;
    }
    if(r1->data != r2->data){
        return false;
    }
    else{
        bool leftans = identical(r1->left,r2->left);
        bool rightans = identical(r1->right,r2->right);
        if(leftans && rightans){
            return true;
        }
        else{
            return false;
        }
    }
}
int main()
{
    // 1 2 -1 -1 3 -1 -1
    // 1 2 -1 -1 3 4 -1 -1 -1
    node *root1 = NULL;
    root1 = buildtree(root1);
    node *root2 = NULL;
    root2 = buildtree(root2);
    cout << endl;
    levelorder(root1);
    cout << endl;
    levelorder(root2);
    cout << endl;
    if(identical(root1,root2)){
        cout<<"identical";
    }
    else{
        cout<<"not identical";
    }
}