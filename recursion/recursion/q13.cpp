// merge sort recusrsively
#include <iostream>
using namespace std;
void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    int n1 = mid - s + 1;
    int n2 = e - mid;

    // making two arrays
    int *first = new int [n1];
    int *second = new int [n2];
    int arrindex = s;
    //copying values of main array into these two arrays
    for(int i = 0;i<n1;i++)
    {
       first[i] = arr[arrindex];
       arrindex++;
    }
    arrindex = mid+1;
    for(int i = 0;i<n2;i++)
    {
       second[i] = arr[arrindex];
       arrindex++;
    }

    //merging two arrays
    int i = 0;
    int j = 0;
    arrindex = s;

    while(i <n1 && j<n2)
    {
        if(first[i] < second[j])
        {
            arr[arrindex] = first[i];
            i++;
            arrindex++;
        }
        else{
            arr[arrindex] = second[j];
            j++;
            arrindex++;
        }
    }
    while(i<n1)
    {
        arr[arrindex] = first[i];
         i++;
            arrindex++;
    }
    while(j<n2)
    {
          arr[arrindex] = second[j];
            j++;
            arrindex++;
    }

}
void mergesort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    // left part mergesort
    mergesort(arr, s, mid);

    // right part mergesort
    mergesort(arr, mid + 1, e);

    // merge left and right
    merge(arr, s, e);
}
int main()
{
    int arr[] = {3,5,2,5,3};
    mergesort(arr, 0, 4);
    for(int i = 0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
}