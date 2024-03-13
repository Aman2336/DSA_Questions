#include <iostream>
using namespace std;
class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int pindex = index / 2;
            if (arr[pindex] < arr[index])
            {
                swap(arr[pindex], arr[index]);
                index = pindex;
            }
            else
            {
                return;
            }
        }
    }
    void deletefromheap()
    {
        arr[1] = arr[size];
        size--;
        int index = 1;
        while (index <= size)
        {
            int lindex = 2 * index;
            int rindex = 2 * index + 1;

            if (arr[index] < arr[lindex])
            {
                swap(arr[index], arr[lindex]);
                index = lindex;
            }
            else if (arr[index] < arr[rindex])
            {
                swap(arr[index], arr[rindex]);
                index = rindex;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left < n && arr[left] > arr[i])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[i])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
int main()
{
    // heap h;
    // h.insert(10);
    // h.insert(20);
    // h.insert(50);
    // h.insert(40);
    // h.insert(30);
    // cout << endl;
    // h.print();
    // h.deletefromheap();
    // cout << endl;
    // h.print();
    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = 1; i <=5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}