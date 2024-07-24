#include <iostream>
#include <stack>
using namespace std;
bool knows(int arr[][3], int a, int b)
{
    if (arr[a][b] == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int celebrity(int arr[][3], int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    while (s.size() != 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (knows(arr, a, b))
        {
            s.push(b);
        }
        if (knows(arr, b, a))
        {
            s.push(a);
        }
    }
    int ans = s.top();
    int zerocount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[ans][i] == 0)
        {
            zerocount++;
        }
    }
    int onecount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][ans] == 1)
        {
            onecount++;
        }
    }
    if (zerocount != n)
    {
        return -1;
    }
    if (onecount != n - 1)
    {
        return -1;
    }
    return ans;
}
int main()
{
    int arr[3][3] = {{0, 1, 0},
                     {0, 0, 0},
                     {0, 1, 0}};
    cout << celebrity(arr, 3);
    return 0;
}