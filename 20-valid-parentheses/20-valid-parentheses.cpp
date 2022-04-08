class Solution {
public:
    
    
    bool isMatched(char a, char b){
        return (a=='{' && b=='}' ||
               a=='[' && b==']' ||
                a=='(' && b==')');
    }
    
    bool isValid(string s) {
        stack<int> st;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='{' || s[i]=='[' || s[i]=='('){
                st.push(s[i]);
            }
            else if(st.empty()){
                return false;
            }
            else{
                if(isMatched(st.top(), s[i])){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};