// merge two heaps
#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int> &arr, int i, int n)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, largest, n);
    }
}
vector<int> merge2heaps(int *arr1, int *arr2, int n1, int n2)
{
    // step1 merge 2 heaps into a new arr
    vector<int> ans;
    for (int i = 0; i < n1; i++)
    {
        ans.push_back(arr1[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        ans.push_back(arr2[i]);
    }
    int n = ans.size();
    // step2 heapify the new arr
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(ans, i, n);
    }
    return ans;
}
int main()
{
    int arr1[] = {10, 5, 6, 2};
    int arr2[] = {12, 7, 9};
    vector<int> ans = merge2heaps(arr1, arr2, 4, 3);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}