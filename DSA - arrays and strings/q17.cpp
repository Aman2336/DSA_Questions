// max occuring character in a string
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int arr[26] = {0};
    int n = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch >= 'a' && ch <= 'z')
        {
            n = ch - 'a';
        }
        else
        {
            n = ch - 'A';
        }
        arr[n]++;
    }
    int max = -1;
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (max < arr[i])
        {
            ans = i;
            max = arr[i];
        }
    }
    char c = ans + 'a';
    cout << c << " ";
}
