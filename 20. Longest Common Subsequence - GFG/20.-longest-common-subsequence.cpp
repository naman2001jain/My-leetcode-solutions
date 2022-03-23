// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int dp[1001][1001];
    int findlcs(int x, int y, string s1, string s2)
    {
        if(x<1 || y<1){
            return 0;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        if(s1[x-1] == s2[y-1]){
            return dp[x][y] = 1+findlcs(x-1, y-1, s1, s2);
        }
        return dp[x][y] = max(findlcs(x-1, y, s1, s2), findlcs(x, y-1, s1, s2));
    }
    
    int lcs(int x, int y, string s1, string s2){
        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                dp[i][j] = -1;
            }
        }
        return findlcs(x, y, s1, s2);
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends