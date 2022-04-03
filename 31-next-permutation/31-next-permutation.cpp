class Solution {
public:
    void reverse(vector<int> &nums, int start, int end){
        while(start<end){
            swap(nums[start++], nums[end--]);
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n<=1){
            return;
        }
        int i, j;
        for(i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                // i--;
                break;
            }
            else if(i==0){
                reverse(nums, 0, n-1);
                return;
            }
        }
        for(j = n-1;j>i;j--){
            if(nums[j]>nums[i]){
                break;
            }
        }
        swap(nums[i], nums[j]);
        reverse(nums, i+1, n-1);
    }
};