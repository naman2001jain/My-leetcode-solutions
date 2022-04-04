class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i-1]==nums[i]){
                continue;
            }
            int low = i+1, high = n-1;
            while(low<high){
                
                if(nums[i] + nums[low]+nums[high]==0){
                    res.push_back({nums[i], nums[low], nums[high]});
                    while(low<high && nums[low] == nums[low+1]){
                        low++;
                    }
                    while(low<high && nums[high] == nums[high-1]){
                        high--;
                    }
                    low++;
                    high--;
                }else if(nums[i] + nums[low]+nums[high]<0){
                    low++;
                }else{
                    high--;
                }
            }
        }
        return res;
        
    }
};