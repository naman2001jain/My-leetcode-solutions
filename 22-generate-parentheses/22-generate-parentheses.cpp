class Solution {
public:
    
    void generate(vector<string> &res, string &sofar, int open, int close, int n){
        if(open<0 || close<0 || open>close){
            return;
        }
        if(open==0 && close==0){
            res.push_back(sofar);
            return;
        }
        
        
        //recursion
        sofar += "(";
        generate(res, sofar, open-1, close, n);
        sofar.pop_back();
        sofar += ")";
        generate(res, sofar, open, close-1, n);
        sofar.pop_back();
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string sofar="";
        generate(res, sofar, n, n, n);
        return res;
    }
};