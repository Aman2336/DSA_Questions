#include <iostream>
using namespace std;
class kqueue
{
public:
    int *arr;
    int *front;
    int *rear;
    int size;
    int *next;
    int freespot;
    kqueue(int size, int k)
    {
        this->size = size;
        arr = new int[size];
        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[size];
        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1;
        freespot = 0;
    }
    void push(int element, int m)
    {
        if (freespot == -1)
        {
            return;
        }
        int index = freespot;
        freespot = next[index];
        if (front[m - 1] == -1)
        {
            front[m - 1] = index;
        }
        else
        {
            next[rear[m - 1]] = index;
        }
        next[index] = -1;
        rear[m - 1] = index;
        arr[index] = element;
    }
    int pop(int m)
    {
        if (front[m - 1] == -1)
        {
            return -1;
        }
        int index = front[m - 1];

        front[m - 1] = next[index];

        next[index] = freespot;

        freespot = index;
        return arr[index];
    }
  
};
int main()
{
    kqueue q(12, 3);
    q.push(10, 1);
    q.push(100, 2);
    q.push(200, 2);
    q.push(20, 1);
    q.push(30, 1);
    q.print(1);
    cout << endl;
    q.print(2);

    return 0;
}