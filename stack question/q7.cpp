// largest area in histogram
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
vector<int> nextsmallerelement(int *arr, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevsmallerelement(int *arr, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int maxarea(int *arr, int n)
{
    vector<int> next(n);
    next = nextsmallerelement(arr, n);
    vector<int> prev(n);
    prev = prevsmallerelement(arr, n);

    int area = -123456789;
    for (int i = 0; i < n; i++)
    {
        int l = arr[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newarea = l * b;
        area = max(area, newarea);
    }
    return area;
}
int main()
{
    int arr[] = {2, 1, 5, 6, 2, 3};
    cout << maxarea(arr, 6);
  
    return 0;
}