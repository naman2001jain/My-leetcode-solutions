// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <fstream>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
// You need to complete this function


class Solution
{
    public:
    //Function to find the nth fibonacci number using bottom-up approach.
    long long  dp[100];
    long long fibonacci(int number)
    {   
        if(number<=1){
            return number;
        }
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=number;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[number];
    }
    
    long long findNthFibonacci(int number){
        for(int i=0;i<100;i++){
            dp[i] = 0;
        }
        return fibonacci(number);
    }

};

// { Driver Code Starts.

int main()
 {
    //taking testcases
    int testcases;
    cin>>testcases;
    
    while(testcases--)
    {
        //taking nth fibonacci 
        //to be found
        int number;
        cin>>number;
        
        //calling function findNthFibonacci()
        //and passing number as parameter
        Solution obj;
        cout<<obj.findNthFibonacci(number)<<endl;
    }
    
	return 0;
}
  // } Driver Code Ends