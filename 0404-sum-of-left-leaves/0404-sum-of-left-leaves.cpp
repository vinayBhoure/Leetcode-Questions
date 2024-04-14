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
    bool isLeaf(TreeNode* node){
        return node->left == NULL && node->right == NULL;
    }
    void sum(TreeNode* root, int &var){
        if(root == NULL) return;
        
        if(root->left != NULL){
            if(isLeaf(root->left)) var += root->left->val;
            sum(root->left, var);
        }
        if(root->right != NULL) sum(root->right, var);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        sum(root, ans);
        return ans;
    }
};