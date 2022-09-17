class Solution {
    public int lengthOfLongestSubstring(String s) {
        int left=0, right=0;
        Set<Character> st = new HashSet<>();
        int res = 0;
        while(right<s.length()){
            if(!st.contains(s.charAt(right))){
                st.add(s.charAt(right));
                right++;
            }else{
                st.remove(s.charAt(left));
                left++;
            }
            res = Math.max(res, right-left);
        }
        return res;
    }
}