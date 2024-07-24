#include <iostream>
using namespace std;
// sum of array recursively
int sum(int *arr, int n)
{
    if (n == 0)
    {
        return 0;
    }
    return arr[0] + sum(arr + 1, n - 1);
}
//linear search recursively
bool linearsearch(int *arr, int n, int k)
{
    if(n==0)
    {
        return 0;
    }
    if(arr[0] == k)
    {
        return true;
    }
    return linearsearch(arr+1,n-1,k);
}
//binary search recursively
bool binarysearch(int* arr,int s ,int e,int k)
{
    if(s>e)
    {
        return 0;
    }
    int mid = s+(e-s)/2;
    if(arr[mid] == k)
    {
        return 1;
    }
    if(arr[mid] > k)
    {
        return binarysearch(arr,s,mid-1,k);
    }
    if(arr[mid] < k)
    {
        return binarysearch(arr,mid+1,e,k);
    }
}
int main()
{
    int arr[] = {1, 2, 4, 5, 6};
    cout << sum(arr, 5)<<endl;
    cout << binarysearch(arr,0,4,6);
}