#include<iostream>
using namespace std;
class Stack{
    int top;
    int* arr;
    int size;
    public:
    Stack(int size){
        this->size = size;
        top = -1;
        arr = new int[size];
    }
    void push(int data){
        if(top < size-1){
          top++;
        arr[top] = data;
        }
      else{
        return;
      }
    }
    int pop(int data){
        if(top == -1){
            return 0;
        }
        int element = arr[top];
        top--;
        return element;
    }
    bool isempty(){
        if(top == -1){
            return 1;
        }
        else{
            return 0;
        }
    }
    int gettop(){
        return arr[top];
    }
    void print(){
        for(int i = top;i>=size-1;i--){
            cout<<arr[i]<<endl;
        }
    }
};
int main(){
    // Stack *s = new Stack(10);
    // s->push(10);
    // s->push(20);
    // s->push(30);
    // s->print();
    Stack s(10);
    s.push(10);
    s.push(20);
    s.push(30);
    s.print();
    return 0;
}