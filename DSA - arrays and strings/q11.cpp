//push 0's to end
#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 0, 3, 0, 0, 12};
    int j = 0;
    for (int i = 0; i < 6; i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[j],arr[i]);
            j++;
        }
    }
    for(int i = 0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
}