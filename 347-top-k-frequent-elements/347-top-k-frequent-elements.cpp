class Solution {
public:
    
    static bool cmp(const pair<int, int> &p1, const pair<int, int> &p2){
        return (p1.second > p2.second);
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int, int>> temp;
        for(auto x: mp){
            temp.push_back({x.first, x.second});
        }
        if(mp.size()<=1){
            return {(*(mp.begin())).first};
        }
        sort(temp.begin(), temp.end(), cmp);
        for(int i=0;i<k;i++){
            res.push_back(temp[i].first);
        }
        return res;
    }
};