//burn tree question
#include <iostream>
#include <queue>
#include <map>
#include <vector>
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
node* createmap(node* root,map<node*,node*> &m,int target){
    node* res = NULL;
    queue<node*>q;
    q.push(root);
    m[root] = NULL;
    while(!q.empty()){
        node* front = q.front();
        q.pop();
        if(target == front->data){
            res = front;
        }
        if(front->left){
            q.push(front->left);
            m[front->left] = front;
        }
        if(front->right){
            q.push(front->right);
            m[front->right] = front;
        }
    }
    return res;
}
void solve(node* root,map<node*,node*> &m,int &ans){
    map<node*,bool> visited;
    queue<node*> q;
    q.push(root);
    visited[root] = 1;
    while(!q.empty()){
        bool flag = 0;
        int size = q.size();
        for(int i = 0;i<size;i++){
            node* front = q.front();
            q.pop();
            if(front->left && !visited[front->left]){
                q.push(front->left);
                visited[front->left] = 1;
                flag = 1;
            }
            if(front->right && !visited[front->right]){
                q.push(front->right);
                visited[front->right] = 1;
                flag = 1;
            }
            if(m[front] && !visited[m[front]]){
                 q.push(m[front]);
                visited[m[front]] = 1;
                flag = 1;
            }
        }
        if(flag == 1){
            ans++;
        }
    }
}
int time(node* root,int target){
    map<node*,node*> nodetoparent;
    int ans = 0;
    node* targetnode = createmap(root,nodetoparent,target);
    solve(targetnode,nodetoparent,ans);
    return ans;
}
int main(){
    node* root = NULL;
    root = buildtree(root);
    levelorder(root);
    cout<<endl;
    cout<<time(root,7);
    return 0;
}