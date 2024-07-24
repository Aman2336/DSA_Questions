#include <iostream>
#include <queue>
#include <stack>
using namespace std;
// queue<int> interleaved(queue<int> q)
// {
//     queue<int> first;
//     int size = q.size() / 2;
//     for (int i = 0; i < size; i++)
//     {
//         int val = q.front();
//         q.pop();
//         first.push(val);
//     }
//     queue<int> newq;
//     while (!first.empty())
//     {
//         newq.push(first.front());
//         first.pop();
//         newq.push(q.front());
//         q.pop();
//     }

//     return newq;
// }
void interleaved(queue<int> &q)
{
    queue<int> first;
    int size = q.size() / 2;
    for (int i = 0; i < size; i++)
    {
        int val = q.front();
        q.pop();
        first.push(val);
    }
    while (!first.empty())
    {
        int val = first.front();
        first.pop();
        q.push(val);
        val = q.front();
        q.pop();
        q.push(val);
    }
}
// approach 2
void interleaved2(queue<int> &q)
{
    stack<int> s;
    for (int i = 0; i < 4; i++)
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
    for (int i = 0; i < 4; i++)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    for (int i = 0; i < 4; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
        val = q.front();
        q.pop();
        q.push(val);
    }
}
int main()
{
    queue<int> q;
    for (int i = 11; i <= 18; i++)
    {
        q.push(i);
    }
    interleaved(q);
    for (int i = 11; i <=18; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}