// subset using recursion
#include<iostream>
#include<vector>
using namespace std;
void solve(int *arr, int i, vector<int> output, vector<vector<int> > &ans, int n)
{
    /// base case
    if (i >= n)
    {
        ans.push_back(output);
        return;
    }
    // exclude
    solve(arr, i + 1, output, ans, n);
    // include
    output.push_back(arr[i]);
    solve(arr, i + 1, output, ans, n);
}
vector<vector<int> > subsets(int *arr, int n)
{
    vector<int> output;
    vector<vector<int> > ans;
    int index = 0;
    solve(arr, index, output, ans, n);
    return ans;
}

using namespace std;
int main()
{
    int arr[] = {1, 2, 3};
    vector<vector<int> > v = subsets(arr, 3);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout<<endl;
    }
}