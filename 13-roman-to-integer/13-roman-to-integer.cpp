class Solution {
public:
    
    int getInt(char a){
        int res=0;
        switch(a){
            case 'I':
                res = 1;
                break;
            case 'V':
                res = 5;
                break;
            case 'X':
                res = 10;
                break;
            case 'L':
                res = 50;
                break;
            case 'C':
                res = 100;
                break;
            case 'D':
                res = 500;
                break;
            case 'M':
                res = 1000;
                break;
            default:
                res = 0;
        }
        return res;
    }
    
    int romanToInt(string s) {
        
        int n = s.length();
        int i=n-2;
        int res = getInt(s[n-1]);
        while(i>=0){
            int x = getInt(s[i]);
            int y = getInt(s[i+1]);
            if(x < y){
                res -= x;
            }else{
                res += x;
            }
            i--;
        }
        return res;
    }
};