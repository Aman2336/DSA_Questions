#include <iostream>
#include<queue>
using namespace std;
int main()
{
deque<int> d;
d.push_front(1);
d.push_front(2);
d.push_back(3);
for(int  i = 0;i<d.size();i++){
    cout<<d.front()<<" ";
    d.pop_front();
}
}