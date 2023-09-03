#include<iostream>
using namespace std;
bool search(int matrix[][3] ,int row,int col,int target)
{
   
        int s = 0;
        int e = (row*col) - 1;
        int mid= s + (e-s)/2;
        while(s<=e)
        {
            int e = matrix[mid/col][mid%col];
            if(e == target)
            {
                return 1;
            }
             if(e > target)
            {
                e = mid -1;;
            }
            if(e < target)
            {       
                s= mid+1;
            }
            mid = s+(e-s)/2;
        }
        return 0;
}
int main()
{
    int arr[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout<<"enter element to be searched"<<endl;
    int x;
    cin>>x;
    if(search(arr,3,3,x))
    {
        cout<<"found";
    }
    else{
        cout<<"not found";
    }
    
}