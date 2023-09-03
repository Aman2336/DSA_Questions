//permutation of string
#include <iostream>
using namespace std;
bool checkequal(int *arr1, int *arr2)
{
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    string s1; // ab
    string s2; // cfcgh'ab'jdm
    cin >> s1 >> s2;
    // character count for s1 is done
    int arr1[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        arr1[index]++;
    }
    int arr2[26] = {0};
    int i = 0;
    int window = s1.length();
    while (i < window && i < s2.length())
    {
        int n = s2[i] - 'a';
        arr2[n]++;
        i++;
    }
    if (checkequal(arr1, arr2))
    {
        cout << true;
    }
    // moving to next block
    while (i < s2.length())
    {
        int index = s2[i] - 'a';
        arr2[index]++;

        index = s2[i - window] - 'a';
        arr2[index]--;

        i++;
    if (checkequal(arr1, arr2))
    {
        cout << true;
    }

    }
    
}