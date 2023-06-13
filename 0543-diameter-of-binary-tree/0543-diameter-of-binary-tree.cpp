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
    int height(TreeNode* root)
    {
        if(root == NULL) return 0;
        
        int l = height(root->left);
        int r = height(root->right);
        
        return 1+max(l,r);
    }
    
    int diameter(TreeNode* root, int &maxi)
    {
        if(root == NULL) return 0;
        
        int lh = diameter(root->left, maxi);
        int rh = diameter(root->right, maxi);
        
        maxi = max(maxi, lh+rh);
        return 1+max(lh,rh);
    } 
    
    int diameterOfBinaryTree(TreeNode* root) {
       /* int maxi = 0;
        
        if(root == NULL) return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        maxi = max(maxi,lh+rh);
        
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        
        return maxi;
        */ 
        int maxi = 0;
        diameter(root,maxi);
        return maxi;
    }
    
    
};