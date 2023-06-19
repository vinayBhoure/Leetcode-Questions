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
    int lefthgt(TreeNode* node)
    {
        int hgt = 0;
        while(node)
        {
            hgt++;
            node = node->left;
        }
        return hgt;
    }
     int righthgt(TreeNode* node)
    {
        int hgt = 0;
        while(node)
        {
            hgt++;
            node = node->right;
        }
        return hgt;
    }
    
    int countNodes(TreeNode* root) {
        
        if(root == NULL) return 0;
        
        int lh = lefthgt(root->left);
        int rh = righthgt(root->right);
        
                // (1 << 3) = 2*2*2;
        if(lh == rh) (1<<lh)-1; 
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};