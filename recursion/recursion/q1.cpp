//no. of digits of a number using recursion
#include <iostream>
using namespace std;
int returncount(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int count = returncount(n / 10);
    return count +1;
}
int main()
{
    int n;
    cin >> n;
    cout << returncount(n) << endl;
}