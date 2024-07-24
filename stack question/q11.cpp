#include <iostream>
#include <stack>
using namespace std;
void insertatbottom(stack<int> &s, int k)
{
    if (s.empty())
    {
        s.push(k);
        return;
    }
    int num = s.top();
    s.pop();
    insertatbottom(s, k);
    s.push(num);
}
void reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int num = s.top();
    s.pop();
    reverse(s);
    insertatbottom(s, num);
}
int main()
{
    stack<int> s;
    for (int i = 1; i <= 5; i++)
    {
        s.push(i);
    }
    reverse(s);
    for (int i = s.size() - 1; i >= 0; i--)
    {
        cout << s.top() << endl;
        s.pop();
    }
}