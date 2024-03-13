#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
void merge(vector<int> arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int n1 = mid - s;
    int n2 = e - mid + 1;
    int *a1 = new int[n1];
    int *a2 = new int[n2];
    int arrindex = s;
    for (int i = 0; i < n1; i++)
    {
        a1[i] = arr[i];
        arrindex++;
    }
    arrindex = mid + 1;
    for (int i = 0; i < n2; i++)
    {
        a1[i] = arr[i];
        arrindex++;
    }
    int i = 0;
    int j = 0;
    arrindex = s;
    while (i < n1 && j < 2)
    {
        if (a1[i] > a2[j])
        {
            arr[arrindex] = a2[j];
            j++;
            arrindex++;
        }
        else
        {
            arr[arrindex] = a1[i];
            i++;
            arrindex++;
        }
    }
    while (i < n1)
    {
        arr[arrindex] = a1[i];
        i++;
        arrindex++;
    }
    while (j < n2)
    {
        arr[arrindex] = a2[j];
        j++;
        arrindex++;
    }
}
void mergesort(vector<int> arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    merge(arr, s, e);
}
int getkthsum1(vector<int> arr, int k)
{
    vector<int> sumarr;

    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            sumarr.push_back(sum);
        }
    }

    sort(sumarr.begin(), sumarr.end());
    return sumarr[sumarr.size() - k];
}
int getkthsum2(vector<int> arr, int k)
{
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
        }
        if (pq.size() < k)
        {
            pq.push(sum);
        }
        else
        {
            if (sum > pq.top())
            {
                pq.pop();
                pq.push(sum);
            }
        }
    }
    return pq.top();
}
int main()
{
    vector<int> arr;
    for (int i = 0; i < 5; i++)
    {
        arr.push_back(i);
    }
    int ans = getkthsum2(arr, 1);
    cout << ans;
}