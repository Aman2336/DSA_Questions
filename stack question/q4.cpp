#include <iostream>
#include <stack>
using namespace std;
void newstack(stack<int> &s, int count, int size)
{
    if (count == size / 2)
    {
        s.pop();
        return;
    }
    int num = s.top();
    s.pop();
    newstack(s, count + 1, size);
    s.push(num);
}
int main()
{
    stack<int> s;
    for (int i = 1; i <= 4; i++)
    {
        s.push(i);
    }
    int count = 0;
    newstack(s, count, s.size());
    for(int i = s.size()-1;i>=0;i--){
        cout<<s.top()<<endl;
        s.pop();
    }
}