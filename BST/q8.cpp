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
void bsttosorteddll(node *root, node *&head)
{
    if (root == NULL)
    {
        return;
    }
    bsttosorteddll(root->right, head);
    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }
    head = root;
    bsttosorteddll(root->left, head);
}
node *mergetwosortedll(node *head1, node *head2)
{
    // if (h1 == NULL)
    // {
    //     return h2;
    // }
    // if (h2 == NULL)
    // {
    //     return h1;
    // }
    // node *curr1 = h1;
    // node *next1 = curr1->right;
    // node *curr2 = h2;
    // node *next2 = curr2->right;
    // while (curr2 != NULL && next1 != NULL)
    // {
    //     if (curr1->data <= next1->data && curr2->data >= curr1->data)
    //     {
    //         curr1->right = curr2;
    //         next2 = curr2->right;
    //         curr2->right = next1;

    //         curr1 = curr2;
    //         curr2 = next2;
    //     }
    //     else
    //     {
    //         curr1 = curr1->right;
    //         next1 = next1->right;

    //         if (next1 == NULL)
    //         {
    //             curr1->right = curr2;
    //             return h1;
    //         }
    //     }
    // }
    // return h1;
    node *head = NULL;
    node *tail = NULL;

    while (head != NULL && tail != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}
int count(node *head)
{
    int cnt = 0;
    node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}
node *lltobst(node *&head, int n)
{

    if (n <= 0 || head == NULL)
    {
        return NULL;
    }
    node *left1 = lltobst(head, n / 2);

    node *root = head;
    root->left = left1;

    head = head->right;
    
    node *right1 = lltobst(head, (n - n / 2 - 1));
    return root;
}
node *merge(node *r1, node *r2)
{
    // step 1 : covert both bst into sorted dll
    node *head1 = NULL;
    bsttosorteddll(r1, head1);
    head1->left = NULL;

    node *head2 = NULL;
    bsttosorteddll(r2, head2);
    head2->left = NULL;

    // merge ll

    node *head = mergetwosortedll(head1, head2);

    // ll to bst
    node *ans = lltobst(head, count(head));
    return ans;
}
int main()
{
    node *root1 = NULL;
    takeinput(root1);
    node *root2 = NULL;
    takeinput(root2);
    levelorder(root1);
    cout << endl;
    levelorder(root2);
    cout << endl;
    node *ans = merge(root1, root2);
    levelorder(ans);
    cout << endl;
    return 0;
}