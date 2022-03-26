class Solution {
public:
    int rec(vector<int> &nums, int n, int target){
        
        if(n<0){
            if(target==0){
                return 1;
            }
        }else{
            //recursion
        int res = 0;
    
        res += rec(nums, n-1, target - nums[n]) + rec(nums, n-1, target + nums[n]);
        return res;
        }
        
        return 0;
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return rec(nums, n-1, target);
    }
};