#include <iostream>
#include <queue>
#include <map>
using namespace std;
bool repeating(int *count, char m)
{
    int i = m - 'a';
    if (count[i] > 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
string output(string s)
{
    queue<char> q;
    string temp = "";
    int count[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        int ch = s[i] - 'a';
        count[ch] = count[ch] + 1;
        q.push(s[i]);

        while (!q.empty())
        {
            if (repeating(count, q.front()))
            {
                q.pop();
            }
            else
            {
                temp.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            temp.push_back('#');
        }
    }
    return temp;
}


int main()
{
    string s;
    cin >> s;
    cout << output(s);
}