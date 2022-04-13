class Solution {
public:
    string countAndSay(int n)
    {
        // base case..
        if (n == 1)
            return "1";
        
        string s = countAndSay(n - 1);

        int count = 1;
        string temp = "";

        for (int i = 0; i < s.size(); i++) {   
             if (s[i] == s[i + 1])  count++;
             else{
                temp +=  to_string(count) + s[i] ;
                count = 1;
            }
        }

        return temp;
    }
};