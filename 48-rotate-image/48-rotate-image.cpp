class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(i<j){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
        for(int i=0;i<R;i++){
            for(int j=0;j<C/2;j++){
                
                swap(matrix[i][j], matrix[i][C-j-1]);
            
            }
        }
    }
};