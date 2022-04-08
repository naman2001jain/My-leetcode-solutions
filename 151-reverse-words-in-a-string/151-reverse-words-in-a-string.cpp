class Solution {
public:
    
    // void reverse(string &s, int low, int high){
    //     while(low<high){
    //         swap(s[low++], s[high--]);
    //     }
    // }
    
    string reverseWords(string s) {
        string res="";
        s += ' ';
        stack<string> st;
        string word = "";
        int i=0, n=s.length();
        while(i<n){
            if(s[i]==' ') {
                if(word.length()>0){
                    st.push(word);
                    word="";
                }
                i++;
                continue;
             }
            word += s[i];
            i++;
        }
        while(!st.empty()){
            res += st.top();
            st.pop();
            if(!st.empty()){
                res += " ";
            }
        }
        return res;
    }
};