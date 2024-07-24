#include<iostream>
#include<vector>
using namespace std;
void solve(string s,int i,vector<string>& ans)
{
    if(i == s.length())
    {
        ans.push_back(s);
        return;
    }
    for(int j = i;j<s.size();j++)
    {
        swap(s[i],s[j]);
        solve(s,i+1,ans);
        //backtrack
        swap(s[i],s[j]);
    }
}
vector<string> permutations(string s)
{
    int i = 0;
    vector<string> ans;
    solve(s,i,ans);
    return ans;
}
int main()
{
    string s="abc";
    vector<string> v = permutations(s);
    for(int i = 0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}