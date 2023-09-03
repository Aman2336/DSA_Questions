//rotate array
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int arr[] = {1,7,9,11};
    int k;
    cin>>k;
    vector<int> v(4);
    for(int i = 0;i<4;i++)
    {
       (v[(i+k)%4]) = arr[i];
    }
    for(int i = 0;i<4;i++)
    {
        arr[i] = v[i];
    }
    for(int i = 0;i<4;i++)
    {
       cout<<arr[i]<<" ";
    }
}
