#include <iostream>
using namespace std;
class queue
{
    int front;
    int rear;
    int *arr;
    int size;

public:
    queue(int s)
    {
        size = s;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    void enqueue(int m)
    {
        if (rear == size - 1)
        {
            return;
        }
        else
        {
            arr[rear] = m;
            rear++;
        }
    }
    int dequeue()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            int x = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            return x;
        }
    }
    bool empty()
    {
        if (front == -1 && rear == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
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
    queue q(10);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print();
    cout << endl;
    cout << q.dequeue();
    cout << endl;
    q.enqueue(4);
    q.print();
    cout << endl;
    cout << q.empty();
    return 0;
}