#include <iostream>
#include <stack>
using namespace std;
void sortedinsert(stack<int> &s, int k)
{
    if (s.empty() || (!s.empty() && s.top() < k))
    {
        s.push(k);
        return;
    }
    int num = s.top();
    s.pop();
    sortedinsert(s, k);
    s.push(num);
}
void sort(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int num = s.top();
    s.pop();
    sort(s);
    sortedinsert(s, num);
}
int main()
{
    stack<int> s;
    s.push(2);
    s.push(1);
    s.push(-1);
    s.push(9);
    s.push(3);
    sort(s);
    for (int i = s.size() - 1; i >= 0; i--)
    {
        cout << s.top() << endl;
        s.pop();
    }
}