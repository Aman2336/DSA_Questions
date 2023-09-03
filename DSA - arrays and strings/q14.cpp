#include <iostream>
#include<vector>
using namespace std;
string tolow(string ch)
{
    for(int i  =0;ch[i]!='\0';i++)
    {
    if (ch[i] >= 'a' && ch[i] <= 'z')
    {
        return ch;
    }
    else
    {
        
        char temp = ch[i] - 'A' + 'a';//ascii values so basically , ch = 'A' - 'A(cancelled out)  + 'a' = 'a';
        ch[i] = temp;
        return ch;
    }
    }
}
int length(char *arr)
{
    int length = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}
bool checkpalindrome(char *arr)
{
    string arr1 = tolow(arr);
    int n = length(arr);
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        if (arr1[s] == arr1[e])
        {
            s++;
            e--;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char ch[10];
    cin >> ch;
    bool ans = checkpalindrome(ch);
    if (ans)
    {
        cout << "palindrome" << endl;
    }
    else
    {
        cout << "not" << endl;
    }

cout<<
}