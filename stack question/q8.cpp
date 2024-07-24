#include <iostream>
#include <stack>
using namespace std;
bool redundant(string s)
{
    stack<char>st;
    for(int i = 0;i<s.size();i++){
        char ch = s[i];
        if(ch == '{' || ch == '(' || ch == '[' || ch == '+' || ch == '-' || ch == '*' ||ch == '/'){
            st.push(ch);
        }
        else{
            if(ch == '}' || ch == ')' || ch == ']'){
                bool isred = true;
                while(st.top()!='('){
                    if(st.top() == '+' || st.top() == '-' || st.top() == '*' ||st.top() == '/'){
                        isred = false;
                    }
                    st.pop();
                }
                if(isred){
                    return 1;
                }
                st.pop(); 
            }
        }
    }
}
int main()
{
    string s;
    cin >> s;
    if (redundant(s))
    {
        cout << "yes";
    }
    else
    {
        cout << "false";
    }
}