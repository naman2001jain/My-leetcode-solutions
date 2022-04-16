class Solution {
public:
    
    void rec(vector<vector<int>> &res, vector<int> &setsofar, vector<int> &nums, int index){

        res.push_back(setsofar);

        for(int i=index;i<nums.size();i++){
            if(index<i && nums[i]==nums[i-1]){
                continue;
            }
        
            setsofar.push_back(nums[i]);
            rec(res, setsofar, nums, i+1);
            setsofar.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> setsofar;
        sort(nums.begin(),nums.end());
        rec(res, setsofar, nums, 0);

        return res;
    }
};