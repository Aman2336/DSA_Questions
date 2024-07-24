#include <iostream>
using namespace std;
class circulauq
{
    int front;
    int rear;
    int *arr;
    int size;

public:
    circulauq(int s)
    {
        size = s;
        front = -1;
        rear = -1;
        arr = new int[size];
    }
    void push(int x)
    {
        if (front == 0 && rear == size - 1)
        {
            return;
        }
        if (rear == front - 1)
        {
            return;
        }
        if (front == -1)
        {
            front = rear = 0;
            arr[rear] = x;
        }
        if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = x;
        }
        else
        {
            rear++;
            arr[rear] = x;
        }
    }
    int pop()
    {
        if (front == -1 && rear == -1)
        {
            return -1;
        }
        int x = arr[front];
        arr[front] = -1;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return x;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    circulauq cq(5);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
    cq.push(5);
    cout << cq.pop();
    cout << endl;
    cq.push(6);
    cq.push(12);
    cq.print();
}