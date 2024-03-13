#include <iostream>
using namespace std;
void heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right <= n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void heapsort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        // 1. swap largest
        swap(arr[1], arr[size]);
        size--;

        // 2.heapify swapped element
        heapify(arr, size, 1);
    }
}
int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = 1; i <= 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    heapsort(arr, n);
    for (int i = 1; i <= 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}