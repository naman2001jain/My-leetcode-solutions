class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int val = nums[0];
        int n = nums.size();
        for(int i=1;i<nums.size();i++){
            if(nums[i]==val){
                count++;
            }else{
                count--;
                if(count==0){
                    count=1;
                    val = nums[i];
                }
                    
            }
        }
        int freq = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==val){
                freq++;
            }
        }
        if(freq > n/2){
            return val;
        }
        return -1;
    }
};