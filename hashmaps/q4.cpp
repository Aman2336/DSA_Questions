#include <iostream>
using namespace std;
int swapcount(int *arr, int n)
{
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(make_pair(arr[i], i));
    }
    sort(v.begin(), v.end());
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(v[i].second == i){
            continue;
        }
        else{
            count++;
            swap(v[i],v[v[i].second]);
            i--;
        }
    }
    return count;
}
int main()
{
    int arr[] = {1, 5, 4, 3, 2};
    cout << swapcount(arr, 5);
}