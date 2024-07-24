#include <iostream>
#include <queue>
using namespace std;
void reverse(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int num = q.front();
    q.pop();
    reverse(q);
    q.push(num);
}
int main()
{
    queue<int> q;
    q.push(3);
    q.push(2);
    q.push(2);
    q.push(5);
    q.push(6);
    q.push(7);

    reverse(q);
    for (int i = 0; i < q.size(); i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}