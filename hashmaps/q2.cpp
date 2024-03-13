#include <iostream>
#include <map>
using namespace std;
// void solve(int *arr1, int n, int index, vector<vector<int> > &ans, vector<int> &output)
// {
//     if (index >= n){
//         ans.push_back(output);
//         return;
//     }
//     solve(arr1,n,index+1,ans,output);

//     output.push_back(arr1[index]);
//     solve(arr1,n,index+1,ans,output);
// }
// vector<vector<int> > subsets(int *arr1, int n)
// {
//     vector<vector<int> > ans;
//     vector<int> output;
//     int index = 0;
//     solve(arr1, n, index, ans, output);
//     return ans;
// }
bool subset(int *arr1, int *arr2, int n, int m)
{
    // vector<vector<int> > ans = subsets(arr1,n);
    // for(auto i : ans){
    //     for(int k = 0;k<i.size();k++){
    //         for(int j = 0;j<m;j++){
    //             if(i[k]!=arr2[j]){
    //                 return false;
    //             }
    //         }
    //     }
    // }
    // return true;

    // Write your code here.
    unordered_map<int, int> map;

    // frequency 1
    for (int i = 0; i < n; i++)
    {
        map[arr1[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        if (map[arr2[i]] > 0)
        {
            map[arr2[i]]--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int arr1[] = {1, 2};
    int arr2[] = {1, 2, 3};
    if (subset(arr1, arr2, 2, 3))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}