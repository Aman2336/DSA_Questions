#include <iostream>
#include <string>
using namespace std;
char tolow(char s3)
{
     if (s3 >= 'a' && s3  <= 'z')
        {
            return s3;
        }
        else
        {
            char temp = s3 - 'A' + 'a';
          
            return temp;
        }
    }


bool valid(char s1)
{
    if ((s1 >= 'a' && s1 <= 'z') || (s1 >= 'A' && s1 <= 'Z') || (s1 >= '0' && s1 <= '9'))
    {
        return 1;
    }
    else
    return 0;
}
bool validpalindrome(string s2)
{
   
    string temp = "";
    for(int j = 0;j<s2.length();j++)
    {
        if(valid(s2[j]))
        {
            temp.push_back(s2[j]);
        }
    }
    for(int i = 0;i<temp.length();i++)
    {
        temp[i] = tolow(temp[i]);
    }
    int s = 0;
    int e = temp.length() - 1;
    for(int i = 0;i<temp.length();i++)
    {
        if(temp[s] == temp[e])
        {
            s++;
            e--;
        }
        else{
            return 0;
        }
    }
    return 1;
}
int main()
{
    string s;
    cin >> s;
    bool ans = validpalindrome(s);
    if(ans)
    {
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}