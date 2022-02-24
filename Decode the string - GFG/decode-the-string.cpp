// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isAlphabate(char ch){
        return (ch>=65 && ch<=90 ) || (ch>=97 && ch<=122);
    }
    bool isNum(char ch){
        return ch>=48 && ch<=57;
    }
    
    string decodedString(string s){
        string currString = "";
        int currNo=0;
        int prevNo;
        string prevString;
        stack<string> stringStack;
        stack<int> numStack;
        for(int i=0;i<s.size();i++){
            if(isNum(s[i])){
                currNo = currNo*10 + (s[i]-'0');
            }
            if(isAlphabate(s[i])){
                currString += s[i];
            }
            if(s[i]=='['){
                stringStack.push(currString);
                numStack.push(currNo);
                currNo = 0;
                currString = "";
            }
            if(s[i]==']'){
                prevNo = numStack.top();
                numStack.pop();
                prevString = stringStack.top();
                stringStack.pop();
                while(prevNo--){
                    prevString += currString;
                }
                currString = prevString;
            }
        }
        return currString;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends