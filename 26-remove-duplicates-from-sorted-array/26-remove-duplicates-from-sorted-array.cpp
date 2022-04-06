class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int x = 0;
        int n = nums.size();
        while(true){
            while(i<n-1 && nums[i]==nums[i+1]){
                i++;
            }
            if(i==n){
                break;
            }
            nums[x++] = nums[i++];
        }
        return x;
    }
};