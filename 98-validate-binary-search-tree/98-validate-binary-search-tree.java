/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    public boolean isValidBst(TreeNode root, Integer mn, Integer mx){
        if(root==null){
            return true;
        }
        if(mn!=null && root.val<=mn){
            return false;
        }
        if(mx!=null && root.val>=mx){
            return false;
        }
        return isValidBst(root.left, mn, root.val) && isValidBst(root.right, root.val, mx);
    }
    
    public boolean isValidBST(TreeNode root) {
        if(root==null){
            return true;
        }
        return isValidBst(root, null, null);
    }
}