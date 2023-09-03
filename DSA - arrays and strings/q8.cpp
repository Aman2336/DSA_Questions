//square root of a no. using binary search
#include <iostream>
using namespace std;
int sqroot(int n)
{
    int s = 0;
    int e = n;
    long long int mid = s + (e - s) / 2;
    long long int ans = -1;
    while (s <= e)
    {
        long long int sq = mid*mid;
        if (sq == n)
        {
            return mid;
        }
        if (sq > n)
        {
            e = mid - 1;
        }
        if (sq < n)
        {
            int ans = mid;
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
    
}
int main()
{
    int n;
    cin >> n;
    int s =sqroot(n);
    cout<<s<<" ";
}