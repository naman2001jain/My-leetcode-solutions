class Solution {
public:
    
    void subsets(vector<vector<int>> &res, vector<int> &sofar, vector<int> &nums, int len, int index){
        //base condition
        if(len==0){
            res.push_back(sofar);
            return;
        }
        if(len<0 || index>=nums.size()){
            return;
        }
        
        sofar.push_back(nums[index]);
        subsets(res, sofar, nums, len-1, index+1);
        sofar.pop_back();
        subsets(res, sofar, nums, len, index+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sofar;
        for(int len=0;len<=nums.size();len++){
            subsets(res, sofar, nums, len, 0);
        }
        return res;
    }
};