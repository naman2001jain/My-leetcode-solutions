class Solution {
    public String reverseWords(String s) {
        char[] chArray = s.toCharArray();
        int lastSpaceIndex = -1;
        
        for(int i=0;i<=s.length();i++){
            if(i==s.length() || chArray[i] == ' '){
                int start = lastSpaceIndex+1;
                int end = i-1;
                while(start<end){
                    char temp = chArray[start];
                    chArray[start] = chArray[end];
                    chArray[end] = temp;
                    start++;
                    end--;
                }
                lastSpaceIndex = i;
            }
        }
        return new String(chArray);
    }
}