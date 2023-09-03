//binary search
#include <iostream>
using namespace std;
int binarysearch(int *arr, int n, int x)
{
    int s = 0;
    int e = n - 1;
    int mid = 0;

    while (s <= e)
    {
        if (arr[mid] == x)
        {
            return mid;
        }

        if (arr[mid] < x)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = (s + e) / 2;
   }
    return -1;
}
int main()
{
    int arr[] = {2, 3, 45, 56, 67};
    int i = binarysearch(arr, 6, 67);
    cout << i << endl;
    return 0;
}