class Solution {
public:
    
    void rec(vector<vector<int>> &res, vector<int> &setsofar, vector<int> &candidates, int target, int index){
        if(target == 0){
            res.push_back(setsofar);
            return;
        }
        if(target<0){
            return;
        }
        if(index >= candidates.size()){           
            return;
        }
        while(index<candidates.size() && target-candidates[index] >= 0){
            setsofar.push_back(candidates[index]);
            rec(res, setsofar, candidates, target-candidates[index], index);
            setsofar.pop_back();
            while(index<candidates.size()-1 && candidates[index]==candidates[index+1]){
                index++;
            }
            index++;
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> setsofar;
        sort(candidates.begin(), candidates.end());
        rec(res, setsofar, candidates, target, 0);
        return res;
    }
};