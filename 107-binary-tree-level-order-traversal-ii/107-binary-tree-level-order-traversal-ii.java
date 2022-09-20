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
    
    public int height(TreeNode root){
        if(root==null){
            return 0;
        }
        return 1+Math.max(height(root.left), height(root.right));
    }
    
    public void elementsOnLevel(List<Integer> levelElements, TreeNode root, int level){
        if(root==null){return;}
        if(level==1){
            levelElements.add(root.val);
            return;
        }
        
        if(level>1){
            elementsOnLevel(levelElements, root.left, level-1);
            elementsOnLevel(levelElements, root.right, level-1);
        }
    }
    
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if(root==null){
            return res;
        }
        
        int h = height(root);
        for(int i=h;i>0;i--){
            List<Integer> levelElements = new ArrayList<>();
            elementsOnLevel(levelElements, root, i);
            res.add(levelElements);
        }
        return res;
    }
}