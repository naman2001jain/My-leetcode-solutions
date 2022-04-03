class Solution {
public:
    
    static bool comparator(vector<int> i1, vector<int> i2){
        return i1[0]<i2[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), comparator);
        vector<vector<int>> res;
        vector<int> temp = intervals[0];
        res.push_back(temp);
        for(int i=1;i<intervals.size();i++){
            int a = res.back()[0], b = res.back()[1];
            int c = intervals[i][0], d = intervals[i][1];
            if(c<=b && b<=d || b>d){
                res.back()[0] = min(res.back()[0], intervals[i][0]);
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }else{
                res.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        return res;
    }
};