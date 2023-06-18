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
    void inorder(TreeNode* root, vector<int> &res)
    {
        if(root == NULL) return;
        
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    
    bool approach1(TreeNode* root)
    {
         vector<int> res;
        inorder(root,res);
        
        int n =res.size();
        for(int i=0; i<n/2; i++)
        {
            if(res[i] != res[n-1-i]) return false;
        }
        return true;
    }
    
    bool approach2(TreeNode* left, TreeNode* right)
    {
        if (left == NULL || right == NULL)
        return left == right;
        
        if(left->val != right->val) return false;
        
        return approach2(left->left , right->right)
              && approach2(left->right , right->left);
    }
    bool isSymmetric(TreeNode* root) {
       
        // return approach1;
        
        return root==NULL || approach2(root->left, root->right);
    }
};