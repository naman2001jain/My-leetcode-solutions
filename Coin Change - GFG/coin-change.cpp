// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
  long long coin(int S[], int m, int n, vector<vector<long long>> &dp){
      //base condition
        if(m<=0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        //recursion
        long long res = 0;
        res += coin(S, m, n-S[m-1], dp) + coin(S, m-1, n, dp);
        
        return dp[n][m] = res;
  }
    long long int count(int S[], int m, int n) {
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, -1));
        return coin(S, m, n, dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends