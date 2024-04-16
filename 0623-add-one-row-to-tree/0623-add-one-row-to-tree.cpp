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
    void func(TreeNode* root, int lvl, int val, int depth){
       if(root == NULL) return;
        
       if(lvl == depth-1){
           TreeNode* newLeft = new TreeNode(val);
           TreeNode* newRight = new TreeNode(val);
           
           TreeNode* left = root->left;
           TreeNode* right = root->right;
           
           root->left = newLeft;
           root->right = newRight;
           
           newLeft->left = left;
           newRight->right = right;
           
           return;
       }
        
        if(root->left) func(root->left, lvl+1, val, depth);
        if(root->right) func(root->right, lvl+1, val, depth);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == NULL) return root;
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        int lvl = 1;
        func(root, lvl, val, depth);
        return root;
    }
};