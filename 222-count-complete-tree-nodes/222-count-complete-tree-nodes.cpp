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
    
    int leftTreeHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1 + leftTreeHeight(root->left);
    }
    
    int rightTreeHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+rightTreeHeight(root->right);
    }
    
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lHeight = leftTreeHeight(root);
        int rHeight = rightTreeHeight(root);
        if(lHeight == rHeight){
            return pow(2,lHeight) - 1;
        }
        
        return 1+countNodes(root->left) + countNodes(root->right);
    }
};