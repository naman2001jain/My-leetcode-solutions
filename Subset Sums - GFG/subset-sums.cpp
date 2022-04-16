// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    
    void rec(vector<int> &arr, int index, int sum, vector<int> &res){
        if(index<0){
            res.push_back(sum);
            return;
        }
        // res.push_back(sum);
        rec(arr, index-1, sum+arr[index], res);
        rec(arr, index-1, sum, res);
        
        
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> res;
        int sum=0;
        // for(int i=0;i<N;i++){
            rec(arr, N-1, sum, res);
        // }
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends