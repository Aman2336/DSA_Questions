#include <iostream>
using namespace std;
void largestrowindex(int arr[][3] ,int row,int col)
{
    int ans = 0;
    int max = INT16_MIN;
    for(int i = 0;i<3;i++)
    {
        int sum = 0;
        for(int j = 0;j<3;j++)
        {
            sum = sum + arr[i][j];
        }
        if(max < sum)
        {
            max = sum;
            ans = i;
        }
    }
    cout<<"max sum is :"<<max<<" "<<"row no. is :"<<ans<<endl;
}
int main()
{
    int arr[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    largestrowindex(arr,3,3);
}