//duplicate element
#include<iostream>
using namespace std;
int main()
{
    int arr[] = {2,3,4,5,6,3};
    
    for(int i = 0;i<6;i++)
    {
        int element = arr[i];
      for(int j = i+1;j<6;j++)
      {
        if(arr[j] == element)
        {
            cout<<element;
        }
      }
    }
    
    return 0;
}