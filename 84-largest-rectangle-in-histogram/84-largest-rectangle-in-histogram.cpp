class Solution {
public:
    vector<int> nseR(vector<int> heights){
        stack<int> s;
        int n = heights.size();
        vector<int> res(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(s.empty()){
                s.push(i);
                res[i] = n;
                continue;
            }
            res[i] = s.top();
            s.push(i);
        }
        return res;
    }
    vector<int> nseL(vector<int> heights){
        stack<int> s;
        int n = heights.size();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(s.empty()){
                s.push(i);
                res[i] = -1;
                continue;
            }
            res[i] = s.top();
            s.push(i);
        }
        return res;
    }
    // void printArray(vector<int> heights){
    //     for(int i=0;i<heights.size();i++){
    //         cout<<heights[i]<<" ";
    //     }
    //     cout<<endl;
    // }
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> nseLeft = nseL(heights);
        vector<int> nseRight = nseR(heights);
        
        int maxArea = INT_MIN;
        for(int i=0;i<n;i++){
            maxArea = max(maxArea, ((nseRight[i]-1) - (nseLeft[i]+1) + 1)*heights[i]);
        }
        return maxArea;
    }
};