//merge two sorted arrays
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int arr1[] = {1, 3, 4, 6};
    int arr2[] = {2, 5, 7};
    vector<int> v;
    int i = 0;
    int j = 0;
    while (i<4 && j<3)
    {
        if(arr1[i] < arr2[j])
        {
            v.push_back(arr1[i]);
            i++;
        }
        else
        {
            v.push_back(arr2[j]);
            j++;
        }
    }
    while(i<4)
    {
        v.push_back(arr1[i]);
        i++;
    }
    while(j<3)
    {
        v.push_back(arr2[j]);
        j++;
    }

        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
}