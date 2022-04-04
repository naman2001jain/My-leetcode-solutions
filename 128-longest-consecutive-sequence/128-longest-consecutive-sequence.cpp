class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        if(nums.size()==0){
            return 0;
        }
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i])==s.end()){
                s.insert(nums[i]);
            }
        }
        int count=1, maxCount=1;
        auto prev = s.begin();
        
        for(auto it = ++s.begin(); it!=s.end(); it++){
            if(*it - *prev == 1){
                count++;
            }else{
                count = 1;
            }
            prev++;
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};