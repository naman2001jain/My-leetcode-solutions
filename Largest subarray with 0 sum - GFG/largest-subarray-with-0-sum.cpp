// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int, int> um;
        int sum=0;
        int maxLen = 0;
        for(int i=0;i<n;i++){
            sum += A[i];
            if(A[i]==0 && maxLen==0){
                maxLen=1;
            }
            if(sum == 0){
                maxLen = i+1;
            }
            if(um.find(sum) != um.end()){
                maxLen = max(maxLen, i-um[sum]);
            }else{
                um[sum] = i;
            }
                
        }
        return maxLen;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends