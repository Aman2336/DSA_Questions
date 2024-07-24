#include <iostream>
#include <stack>
using namespace std;
bool valid(string str)
{
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch == '}' || ch == ']' || ch == ')')
        {
            s.pop();
        }
        else{
            s.push(ch);
        }
    }
    if(s.empty()){
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{
    string exp = "{{}";
    if (valid(exp))
    {
        cout << "valid";
    }
    else
    {
        cout << "not valid";
    }
}