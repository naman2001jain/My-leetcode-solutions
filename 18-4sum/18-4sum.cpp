class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j-1]==nums[j]) continue;
                int low = j+1, high = n-1;
                while(low<high){
                    if(nums[i]+nums[j]==target-(nums[low]+nums[high])){
                        res.push_back({nums[i], nums[j], nums[low], nums[high]});
                        while(low<high && nums[low]==nums[low+1]){
                            low++;
                        }
                        while(low<high && nums[high]==nums[high-1]){
                            high--;
                        }
                        low++;
                        high--;
                    }else if(nums[i]+nums[j]<target-(nums[low]+nums[high])){
                        low++;
                    }else{
                        high--;
                    }
                }
            }
        }
        return res;
    }
};