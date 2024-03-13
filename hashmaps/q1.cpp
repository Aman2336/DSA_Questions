#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main()
{
    string s = "dddbbbsddsscc";
    unordered_map<char, int> count;
    for (int i = 0; i < s.length(); i++)
    {
        count[s[i]]++;
    }
    // for (auto i : count)
    // {
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    // iterator
    unordered_map<char, int>::iterator it = count.begin();
    while (it != count.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    int maxcount = INT_MIN;
    char maxoccured;
    for (int i = 0; i < count.size(); i++)
    {
        if (maxcount <= count[s[i]])
        {
            maxcount = count[s[i]];
            maxoccured = s[i];
        }
    }
    cout << maxoccured << ":" << maxcount;
}