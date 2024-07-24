#include <iostream>
using namespace std;
// reverse string recursively
void reverse(string &s1, int start, int end)
{

    if (start >= end || s1[start] == '\0')
    {
        return;
    }
    swap(s1[start], s1[end]);
    start++;
    end--;
    reverse(s1, start, end);
}
// PALINDROME RECURSIVELY
bool palindrome(string s, int start, int end)
{
    if (start > end || s[start] == '\0')
    {
        return 1;
    }
    if (s[start] == s[end])
    {
        return palindrome(s, start+1, end-1);
    }
    else{
        return 0;
    }
}
int main()
{
    string s = "naman";
   /* reverse(s, 0, 3);
    cout << s << endl;*/
    cout << palindrome(s, 0, 4) << endl;
}