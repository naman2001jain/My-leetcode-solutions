class Solution {
public:
    string say(string s){
        
        string res = "";
        int x=1;
        for(int i=0;i<s.length();i++){
            if(s[i]==s[i+1]){
                x++;
            }else{
                res += to_string(x) + s[i];
                x=1;
            }
        }
        
        return res;
    }
    
    string countAndSay(int n) {
        string res = "";
        if(n==1){
            res =  "1";
            return res;
        }
        if(n==2){
            return "11";
        }
        res = "21";
        for(int i=3;i<n;i++){
            res = say(res);
        }
        return res;
    }
};