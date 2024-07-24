//quick sort recursively
#include<iostream>
using namespace std;
int partition(int*arr,int s,int e)
{
    int pivot = arr[s];
    int count = 0;
    for(int i = s+1;i<=e;i++)
    {
        if(pivot >= arr[i])
        {
            count++;
        }
    }
    int pivotindex = s + count;
    swap(arr[s],arr[pivotindex]);
    
    int i = s;
    int j = e;
    while(i < pivotindex && j > pivotindex)
     {
        while(arr[i] < arr[pivotindex])
        {
            i++;
        }
        while(arr[j] > arr[pivotindex])
        {
            j--;
        }
        if(i < pivotindex && j > pivotindex)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
return pivotindex;
}
void quicksort(int* arr,int s,int e)
{
    if(s>=e)
    {
        return;
    }

     int p = partition(arr,s,e);
     quicksort(arr,s,p-1);
     quicksort(arr,p+1,e);
}
int main()
{
    int arr[] ={3,1,2,5,4};
    quicksort(arr,0,4);
    for(int i = 0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
}