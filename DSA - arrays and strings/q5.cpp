//duplicates
#include <iostream>
#include <vector>
using namespace std;
vector<int> duplicates(int *arr, int n)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int e = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] == e)
            {
                v.push_back(e);
                e = -12334555;
                break;
            }
        }
    }
    return v;
}
int main()
{
    int arr[] = {0,2,1,2,3,3};
    vector<int> v1 = duplicates(arr, 6);
        for (int i = 0; i < v1.size(); i++)
        {
            cout << v1[i] << " ";
        }
    

    return 0;
}