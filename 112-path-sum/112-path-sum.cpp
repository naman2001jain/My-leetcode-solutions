/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool isLeafNode(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        return false;
    }
    
    bool traversal(TreeNode* root,const int &targetSum, int currSum){
        if(root==NULL){
            return false;
        }
        currSum += root->val;
        if(targetSum == currSum && isLeafNode(root)){
            return true;
        }
        
        return traversal(root->left, targetSum, currSum) || traversal(root->right, targetSum, currSum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        int currSum = 0;
        return traversal(root, targetSum, currSum);
    }
};