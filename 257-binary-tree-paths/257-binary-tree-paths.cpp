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
    
    bool isLeaf(TreeNode* root){
        if(root->left == NULL && root->right==NULL){
            return true;
        }
        return false;
    }
    
    void util(vector<string> &res, TreeNode* root, string pathsofar){
        
        if(isLeaf(root)){
            pathsofar += to_string(root->val);
            res.push_back(pathsofar);
            return;
        }
        else{
            pathsofar += to_string(root->val);
            pathsofar += "->";
        }
        
        if(root->left!=NULL){
            util(res, root->left, pathsofar);
        }
        if(root->right!=NULL){
            util(res, root->right, pathsofar);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(isLeaf(root)){
            return {to_string(root->val)};
        }
        vector<string> res;
        string pathsofar="";
        util(res, root, pathsofar);    
        return res;
    }
};