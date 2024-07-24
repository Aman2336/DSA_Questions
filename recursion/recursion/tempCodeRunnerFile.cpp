#include<iostream>
#include<vector>
using namespace std;
void solve(string s,int index,string output,vector<string>& ans,string arr[])
{
if(index ==s.length())
{
    ans.push_back(output);
    return;
}
 //input string me se (2-9) uski mapped index value nikal li
string val = arr[s[index] - '0']; //val me uss mapped index ki corresponding value daal di

for(int i = 0;i<val.length();i++)
{
    output.push_back(val[i]);
    solve(s,i+1,output,ans,arr);
    output.pop_back();
}
}
vector<string> keypad(string s)
{
    vector<string> ans;
    if(s.length() == 0)
    {
        return ans;
    }
    string output ="";
    int i = 0;
    string arr[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(s,i,output,ans,arr);
    return ans;
}
int main()
{
    string str;
    cin>>str;
    vector<string> y = keypad(str);
    for(int i = 0;i<y.size();i++)
    {
        cout<<y[i]<<" ";
    }
}