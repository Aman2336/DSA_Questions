//pivot and search in rotated array
#include <iostream>
using namespace std;
int findpivot(int *arr, int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - 2) / 2;
    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - 2) / 2;
    }
    return s;
}
int binarysearch(int *arr, int n, int x, int s, int e)
{
    ;
    int mid = s + (e - s) / 2;

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
        mid = s + (e - s) / 2;
    }
    return -1;
}
int searchrotated(int *arr, int n, int target)
{
    int pivot = findpivot(arr, n);
    if (arr[pivot] <= target && target <= arr[n - 1])
    {
        int i = binarysearch(arr, n, target, pivot, n - 1);
        return i;
    }
    else
    {
        int i = binarysearch(arr, n, target, 0, pivot - 1);
        return i;
    }
}
bool issortandrotated(int*arr,int n)
{
    int count = 0;
    for(int i = 1;i<n;i++)
    {
        if(arr[i-1]>arr[i])
        {
            count++;
        }
    }
    if(arr[n-1]>arr[0])
    {
        count++;
    }
   return count<=1;
}
int main()
{
    int arr[] = {1,1,1,1,1};
    /*int i = searchrotated(arr, 5, 2);
    cout << i << " ";*/
    bool ans = issortandrotated(arr,5);
    cout<<ans<<endl;
}
