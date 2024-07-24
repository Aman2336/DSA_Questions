#include <iostream>
using namespace std;
class twostack
{
    int top1;
    int top2;
    int *arr;
    int size;

public:
    twostack(int s)
    {
        size = s;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }
    void push1(int k)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = k;
        }
        else
        {
            return;
        }
    }
    void push2(int k)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = k;
        }
        else
        {
            return;
        }
    }
    int pop1()
    {
        if (top1 > 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }
    int pop2()
    {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }
    void print1()
    {
        for (int i = top1; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
    void print2()
    {
        for (int i = top2; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }
};
int main()
{
    twostack t(10);
    t.push1(10);
    t.push2(100);
    t.push1(20);
    t.push2(200);
    t.push1(30);
    t.print1();
    cout<<endl;
    t.print2();
    cout<<endl;
    t.pop2();
    cout<<endl;
    t.print2();
}