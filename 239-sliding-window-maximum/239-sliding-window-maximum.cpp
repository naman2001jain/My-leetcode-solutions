class Solution {
public:
    // 1 3 -1 -3 5 3 6 7
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res(nums.size()-k+1);
        for(int i=0;i<nums.size();i++){
            if(dq.empty()){
                dq.push_back(i);
            }else{
                while(nums[dq.back()] < nums[i]){
                    dq.pop_back();
                    if(dq.empty()) break;
                }
                dq.push_back(i);
                
            }
            if(i>=(k-1) && i<=nums.size()){
                
                if(dq.front() == i-k){
                    dq.pop_front();
                }
                res[i-k+1] = nums[dq.front()];
            }
            
        }
        return res;
    }
};