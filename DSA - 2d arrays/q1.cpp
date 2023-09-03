#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int arr[3][3];
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    vector<int> v;
    int row = 0;
    
    while(row < 3)
    {
        int sum = 0;
        for(int j = 0;j<3;j++)
        {
            
           sum = sum +  arr[row][j];
        }
        v.push_back(sum);
        row++;
    }
    for(int i = 0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}