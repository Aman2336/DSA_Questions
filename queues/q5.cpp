#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// approach 1
vector<int> firstnegative(int *arr, int k, int n)
{
    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int count = 0;
        while (count < k && j <= n)
        {
            q.push(arr[j]);
            j++;
            count++;
        }
        if (q.front() > 0)
        {
            while (q.front() > 0)
            {
                q.pop();
            }
            ans.push_back(q.front());
        }
        else if (q.front() < 0)
        {
            ans.push_back(q.front());
        }
        else
        {
            ans.push_back(0);
        }
        q.pop();
    }

    return ans;
}
// approach 2
vector<int> firstnegative_2(int *arr, int k, int n)
{
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }
    if (dq.size() > 0)
    {
        ans.push_back(arr[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    for (int i = k; i < n; i++)
    {
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
        if (dq.size() > 0)
        {
            ans.push_back(arr[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }

    return ans;
}
int main()
{
    int arr[] = {-8, 2, 3, -6, 10};
    int k;
    cin >> k;
    vector<int> v = firstnegative_2(arr, k, 5);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}