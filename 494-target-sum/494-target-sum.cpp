class Solution {
public:
    int count=0;
    void rec(vector<int> &nums, int n, int sum, const int &target){
        
        
        
        if(n<0){
            if(target==sum)
                count++;
        }
        else{
            rec(nums, n-1, sum + nums[n], target);
            rec(nums, n-1, sum-nums[n], target);
        }
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum=0;
        rec(nums, n-1, sum, target);
        return count;
    }
};