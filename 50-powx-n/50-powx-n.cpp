class Solution {
public:
    bool isNegative = false;
    double myPow(double x, int n) {
        double ans=1;
        if(n<0){
            isNegative = true;
        }
        n = abs(n);
        while(n>0){
            if(n&1){//odd
                ans = ans*x;
            }
            x = x*x;
            n = n>>1;
            // n = n/2;
        }
        if(isNegative){
            return 1/ans;
        }
        return ans;
    }
};