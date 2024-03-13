#include <iostream>
#include <map>
#include <set>
using namespace std;
pair<int, int> similarity(int *arr1, int *arr2, int n, int m)
{
    unordered_map<int, int> count;

    // frequency count for arr1
    for (int i = 0; i < n; i++)
    {
        count[arr1[i]]++;
    }

    // for common elements
    int count1 = 0;
    for (int i = 0; i < m; i++)
    {
        if (count[arr2[i]] == 1)
        {
            count1++;
        }
    }

    set<int> s;

    for (int i = 0; i < n; i++)
    {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        s.insert(arr2[i]);
    }

    // for union
    int count2 = 0;
    vector<int> temp(s.begin(), s.end());
    for (int i = 0; i < temp.size(); i++)
    {
        count2++;
    }
    pair<int, int> p = make_pair(count1, count2);
    return p;
}
int main()
{
    int arr1[] = {2, 4, 6, 8};
    int arr2[] = {2, 4};
    pair<int, int> ans = similarity(arr1, arr2, 4, 2);
    cout << ans.first << " " << ans.second << " ";
}