class Solution {
public:
    
    void permute(vector<vector<int>> &res, vector<int> &sofar, vector<int> &nums, int index ,int n, vector<int> &freq){
        if(index >= n){
            res.push_back(sofar);
            return;
        }
        
        //recursion and backtracking
        
        for(int i=0;i<n;i++){
            if(!freq[i]){
                freq[i]++;
                sofar.push_back(nums[i]);
                permute(res, sofar, nums, index+1, n, freq);
                sofar.pop_back();
                freq[i]--;
            }    
        }
       
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> sofar;
        vector<vector<int>> res;
        vector<int> freq(n, 0);
        permute(res, sofar, nums, 0, n, freq);
        
        return res;
    }
};