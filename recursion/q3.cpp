//sum of array recursively
#include <iostream>
using namespace std;
int sum(int *arr, int n)
{
    if (n == 0)
    {
        return 0;
    }
    int ans1 = arr[0];
    int ans = sum(arr + 1, n - 1);
    return ans1 + ans;
}
int main()
{
    int arr[] = {0, 1, 1, 1, 1};
    cout << "sum of array is :" << sum(arr, 5);
}