class Solution {
public:
    
    // void reverse(string &s, int low, int high){
    //     while(low<high){
    //         swap(s[low++], s[high--]);
    //     }
    // }
    
    string reverseWords(string s) {
        string res="";
        int i=0;
        int n=s.length();
        while(i<n && s[i]==' '){
            i++;
        }
        string word="";
        while(i<n){
            if(s[i]!=' '){
                word += s[i];
            }else{
                reverse(word.begin(), word.end());
                res += word + " ";
                word = "";
                while(s[i+1]==' '){
                    i++;
                }
            }
            i++;
        }
        if(word.length()>0){
            reverse(word.begin(), word.end());
            res += word;
        }
        if(res[res.length()-1]==' '){
            res = res.substr(0, res.length()-1);
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};