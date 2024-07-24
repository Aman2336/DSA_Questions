#include <iostream>
#include <queue>
#include <stack>
using namespace std;
queue<int> reversek(queue<int> q, int k)
{

    stack<int> s;
    for (int i = 0; i < k; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }
    int t = q.size() - k;
    while (t--)
    {
        int a = q.front();
        q.pop();
        q.push(a);
    }
    return q;
}
int main()
{
    queue<int> q;
    int k;
    cin >> k;
    for (int i = 1; i <= 5; i++)
    {
        q.push(i);
    }
    queue<int> nq = reversek(q, k);
    while(!nq.empty())
    {
        cout << nq.front() << " ";
        nq.pop();
    }
}