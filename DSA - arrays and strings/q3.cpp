#include <iostream>
#include<vector>
using namespace std;
int firstindex(vector<int> &arr, int n, int k)
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
        if (arr[mid] < k)
        {
            s = mid + 1;
        }
        if (arr[mid] > k)
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int lastindex(vector<int> &arr, int n, int k)
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
        if (arr[mid] < k)
        {
            s = mid + 1;
        }
        if (arr[mid] > k)
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
    pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    int a = firstindex(arr,n,k);
    int b = lastindex(arr,n,k);
    pair<int,int> p;
    p.first = a;
    p.second = b;
    return p;
}
int main()
{
    vector<int>arr ;
    int j ;
    for(int i = 0;i<8;i++)
    {
        
        cin>>j;
        arr.push_back(j);
    }
pair<int,int> p;
p = firstAndLastPosition(arr,8,2);
cout<<p.first<<" "<<p.second;


}