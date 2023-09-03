//factorial of a no. recursively
#include<iostream>
using namespace std;
int fact(int n)
{
    if(n==0||n==1)
    {
        return 1;
    }
    int ans = fact(n-1);
    return n*ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<fact(n);
}