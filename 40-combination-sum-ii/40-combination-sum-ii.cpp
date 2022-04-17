class Solution {
public:
    
    void combination(vector<vector<int>> &res, vector<int> &sofar, vector<int> &candidates, int target, int index){
        
        if(target==0){
            res.push_back(sofar);
            return;
        }
        
        if(index >= candidates.size() || target<0){
            return;
        }
        
        for(int i=index;i<candidates.size();i++){
            if(candidates[i]>target)
            {
                break;
            }
            
            if(i>index && candidates[i] == candidates[i-1]){
                continue;
            }
            
            sofar.push_back(candidates[i]);
            combination(res, sofar, candidates, target-candidates[i], i+1);
            sofar.pop_back();
            
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> sofar;
        vector <vector<int>> res;
        sort(candidates.begin(), candidates.end());
        combination(res, sofar, candidates, target, 0);
        
        return res;
    }
};