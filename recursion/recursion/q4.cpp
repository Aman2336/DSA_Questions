//find first and last index of an element in an array using recursion
#include <iostream>
using namespace std;
/*normal program
int firstindex(int *arr, int n, int k)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == k)
        {
            ans = mid;
            e = mid - 1;
        }
        if (arr[mid] > k)
        {
            e = mid - 1;
        }
        if (arr[mid] < k)
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int lastindex(int *arr, int n, int k)
{

    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == k)
        {
            ans = mid;
            s = mid + 1;
        }
        if (arr[mid] > k)
        {
            e = mid - 1;
        }
        if (arr[mid] < k)
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}*/
int firstindex(int*arr,int n,int k)
{
    if(n==0)
    {
        return -1;
    }
    if(k == arr[0])
    {
        return 0;
    }
    int ans = firstindex(arr+1,n-1,k);
    if(ans==-1)
    {
        return ans;
    }
    else{
        return ans;
    }
}

int main()
{
    int arr[] = { 2,3,4,5,2,6,7};
    cout<<firstindex(arr,8,2)<<" ";//<<//lastindex(arr,8,2);
}