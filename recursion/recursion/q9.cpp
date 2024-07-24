//is sorted or not
#include<iostream>
using namespace std;
bool issorted(int*arr,int n)
{
    if(n==1 || n==0)
    {
        return 1;
    }
 
 if(arr[0] < arr[1])
{
    return issorted(arr+1,n-1);
}
else{
    return 0;
}


}
int main()
{int arr[] ={1,2,3,4,5};
cout<<issorted(arr,5);
}