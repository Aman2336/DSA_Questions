#include<iostream>
using namespace std;
 int minimumLength(string s) {
        if(s.length() == 1){
            return 1;
        }
        
        int start = 0;
        int end = s.length()-1;
        int length = s.length();
        while(start<=end){
            if(s[start] == s[end]){
                
                char ele = s[start];
                while( start <=end && s[start] == ele){
                    start++;
                }
                while(start<=end && s[end] == ele){
                    end--;
                }
            }
            else
            {
                break;
            }
        }
        return end-start+1;
        // cout<<end-start+1;
    }
int main(){
    string s = "cabaabac";
   cout<<minimumLength(s);
}