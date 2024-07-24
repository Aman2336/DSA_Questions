#include <iostream>
#include <stack>
using namespace std;
int countforvalid(string str)
{
    if (str.length() % 2 != 0)
    {
        return -1;
    }
    else
    {
        stack<int> s;
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];
            if (ch == '{')
            {
                s.push(ch);
            }
            else
            {
                if (!s.empty() && s.top() == '{')
                {
                    s.pop();
                }
                else{
                    s.push(ch);
                }
            }
        }
        int a = 0;
        int b = 0;
        while (!s.empty()){
            if(s.top() == '{'){
                a++;
            }
            if(s.top() == '}'){
                b++;
            }
            s.pop();
        }
        int ans = (a+1)/2 + (b+1)/2;
        return ans;
    }
    stack<int> s;
}
int main()
{
    string s;
    cin >> s;
    cout << countforvalid(s);
}