#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int arr1[] = {1, 2, 3, 4}; // 1234
    int arr2[] = {6};          // 6 addition should give 1240
    vector<int> v;
    int carry = 0;
    int i = 3;
    int j = 0;
    while (i >= 0 && j >= 0)
    {
        int ans1 = arr1[i];
        int ans2 = arr2[j];
        int sum = ans1 + ans2 + carry;
        carry = sum / 10;
        sum = sum % 10;

        v.push_back(sum);
        i--;
        j--;
    }
    while (i >= 0)
    {
        int sum = arr1[i] + carry;
        carry = sum / 10;
        sum = sum % 10;

        v.push_back(sum);
        i--;
    }
    while (j >= 0)
    {
        int sum = arr2[j] + carry;
        carry = sum / 10;
        sum = sum % 10;

        v.push_back(sum);
        j--;
    }
    while (carry!=0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;

        v.push_back(sum);
    }
    for(int i = v.size()-1;i>=0;i--)
    {
        cout<<v[i]<<" ";
    }
}