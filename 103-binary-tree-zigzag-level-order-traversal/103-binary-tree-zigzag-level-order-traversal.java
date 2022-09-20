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
        
    }
    
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if(root==null){
            return res;
        }
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        boolean ltor = true;
        while(!q.isEmpty()){
            int qsize = q.size();
            List<Integer> levelElements = new ArrayList<>(qsize);
            for(int i=0;i<qsize;i++){
                TreeNode temp = q.remove();
                if(ltor){
                    levelElements.add(temp.val);
                }
                else{
                    levelElements.add(0, temp.val);
                }
                if(temp.left!=null){
                   q.add(temp.left);
                }
                
                if(temp.right!=null){
                    q.add(temp.right);
                }
            }
           res.add(levelElements);
           ltor = !ltor;
        }
        
        return res;
    }
}