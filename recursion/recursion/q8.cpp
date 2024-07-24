#include <iostream>
using namespace std;
void saydigits(string arr[], int n)
{
    if (n == 0)
    {
        return;
    }
    int digit = n % 10;
    n = n / 10;
    

    saydigits(arr,n);
    cout << arr[digit] << " ";
}
int main()
{
    string arr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n;
    cin >> n;
    saydigits(arr,n);
}