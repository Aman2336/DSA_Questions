#include<iostream>
using namespace std;
bool checkequal(int*arr1,int*arr2)
{
    for(int i = 0;i<26;i++)
    {
        if(arr1[i]!=arr2[i])
        {
            return 0;
        }
    }
    return 1;
}
 bool checkInclusion(string s1, string s2) {
        //charac count for st 1
        int count1[26]={0};
        for(int i = 0;i<s1.length();i++)
        {
            int index = s1[i]-'a';
            count1[index]++;
        }
        int i = 0;
        int window = s1.length();
        int count2[26]={0};
        while(i<window && i<s2.length())
        {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }
        if(checkequal(count1,count2)){
            return 1;
        }
        while(i<s2.length())
        {
            int index = s2[i] - 'a';
            count2[index]++;
            
            index = s2[i-window] -'a';
            count2[index]--;
            
            i++;
            if(checkequal(count1,count2)){
            return 1;
        }
            
    }
    return 0;
    }
int main()
{
    string s1;
    string s2;
    cin>>s1>>s2;
    if(checkInclusion(s1, s2))
    {
        cout<<"true"<<endl;
    }
    else{
        cout<<"false";
    }
}
