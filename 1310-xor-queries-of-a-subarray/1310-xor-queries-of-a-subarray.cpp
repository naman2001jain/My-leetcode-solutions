class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefixor;
        int xr = 0;
        vector<int> res;
        for(int i=0;i<arr.size();i++){
            xr = xr^arr[i];
            prefixor.push_back(xr);
        }
        for(auto q: queries){
            if(q[0]>0){
                res.push_back(prefixor[q[1]] ^ prefixor[q[0]-1]);
            }else{
                res.push_back(prefixor[q[1]]);
            }
            
        }
        return res;
    }
};