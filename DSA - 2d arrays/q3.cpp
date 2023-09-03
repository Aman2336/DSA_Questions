#include <iostream>
using namespace std;
/*
1 2 3
4 5 6
7 8 9
*/
void printspiral(int arr[][3], int row, int col)
{
    int count = 0;
    int total = row * col;

    int startingrow = 0;
    int startingcol = 0;
    int endingrow = row - 1;
    int endingcol = col - 1;

    while (count < total)
    {
        // print starting row
        for (int i = startingcol; count < total && i <= endingcol; i++)
        {
            cout << arr[startingrow][i];
            count++;
        }
        startingrow++;
        // print ending col
        for (int i = startingrow; count < total && i <= endingrow; i++)
        {
            cout << arr[i][endingcol];
            count++;
        }
        endingcol--;
        for (int i = endingcol; count < total && i >= startingcol; i--)
        {

            cout << arr[endingrow][i];
            count++;
        }
        endingrow--;
        for (int i = endingrow; count < total && i >= startingrow; i--)
        {
            cout << arr[i][startingcol];
            count++;
        }
        startingcol++;
    }
}
void printwave(int arr[][3], int row, int col)
{
    for (int j = 0; j < col; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < row; i++)
            {
                cout << arr[i][j] << " ";
            }
        }
        else
        {
            for (int i = row - 1; i >= 0; i--)
            {
                cout << arr[i][j] << " ";
            }
        }
    }
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
    // printwave(arr,3,3);
    printspiral(arr, 3, 3);
}