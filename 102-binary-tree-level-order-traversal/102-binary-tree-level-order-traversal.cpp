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
    
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    
    void rec(TreeNode* root, vector<vector<int>> &res, vector<int> &levelNodes, int level){
        //base case
        if(root==NULL){
            return;
        }
        if(level==1){
            levelNodes.push_back(root->val);
            return;
        }
        if(root->left!=NULL){
            rec(root->left, res, levelNodes, level-1);
        }
        if(root->right!=NULL){
            rec(root->right, res, levelNodes, level-1);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>> res;
        int h = height(root);
        vector<int> levelNodes;
        for(int i=1;i<=h;i++){
            rec(root, res, levelNodes, i);
            res.push_back(levelNodes);
            levelNodes.clear();
        }
        return res;
    }
};