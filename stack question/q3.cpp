#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string str = "naman";
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        s.push(str[i]);
    }
    string temp = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        temp.push_back(s.top());
        s.pop();
    }
    cout << str << endl;
    cout << temp << endl;
}