#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    string s = "this is aman";
    
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            s[i] = 'x';
        }
    }
    cout << s;
}