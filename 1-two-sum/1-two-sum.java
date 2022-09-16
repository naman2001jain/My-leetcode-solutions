
class Solution {
    public int[] twoSum(int[] nums, int target) {
        try{
            Map<Integer, Integer> mp = new HashMap<>();
            for(int i=0;i<nums.length;i++){
                if(mp.containsKey(nums[i])){
                    return new int[]{mp.get(nums[i]), i};
                }else{   
                    mp.put(target-nums[i], i);
                }
            }
            return new int[]{-1, -1};
        }catch(Exception e){
            throw e;
        }
        
    }
}