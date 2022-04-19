class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        bool isNegetive = false;
        while(i<s.length() && s[i]==' '){
            i++;
        }
        if(s[i]=='+'){
            i++;
        }
        else if(s[i]=='-'){
            isNegetive = true;
            i++;
        }
        int x = 0;
        while(i<s.length() && s[i]>=48 && s[i]<=57){
            // int digit = s[i]-'0';
            if(x>INT_MAX/10 || (x==INT_MAX/10 && (s[i]-'0')>INT_MAX%10)){
                return (isNegetive)? INT_MIN : INT_MAX;
            }
               x = x*10l + s[i]-'0';
            i++;
        }
        x = ((isNegetive)? -x : x);
        return x;
    }
};