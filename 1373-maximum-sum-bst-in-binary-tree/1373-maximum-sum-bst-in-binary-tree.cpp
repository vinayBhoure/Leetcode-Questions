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
    
    class info {
        public:
        int maxi;
        int mini;
        bool isBST;
        int size;
    };
    
    info solve(TreeNode* root, int &ans)
    {
        if(root == NULL)
        {
            return {INT_MIN, INT_MAX, true, 0};
        }
        
        info left = solve(root->left, ans);
        info right = solve(root->right, ans);
        
        info currNode;
        
        currNode.size = root->val + left.size + right.size;
        currNode.mini = min(root->val, left.mini);
        currNode.maxi = max(root->val, right.maxi);
        
        if(left.isBST && right.isBST && (root->val < right.mini && root->val > left.maxi))
        {
            currNode.isBST = true;
        }else{
            currNode.isBST = false;
        }
        
        if(currNode.isBST)
        {
            ans = max(ans, currNode.size);
        }
        
        return currNode;
    }
    
    info find(TreeNode* root, int &ans)
    {
        if(!root){
            return {INT_MIN, INT_MAX, true, 0};
        }
        
        info left = find(root->left, ans);
        info right = find(root->right, ans);
        
        info node;
        
        if(left.isBST && right.isBST && (root->val < right.mini && root->val > left.maxi))
        {
            node.isBST = true;
            node.size = left.size + right.size + root->val;
            node.mini = min(root->val, left.mini);
            node.maxi = max(root->val, right.maxi);
        }
        else{
            node.isBST = false;
            node.size = max(left.size, right.size);
        }
        ans = max(ans, node.size);
        return node;
    }
    
    int maxSumBST(TreeNode* root) {
           
        int maxSize = 0;
        
        // appraoch 1 
        // info temp = solve(root,maxSize);
        
        // approach -> 2 by discussion section
        info sum = find(root,maxSize);
        
        return maxSize;
        
       
        
    }
};