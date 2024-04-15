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
        return (root->left == NULL) && (root->right == NULL);
    }
    void solve(TreeNode* root, int &ans, long long &temp){
        if(isLeaf(root)){
            temp = temp*10 + root->val;
            ans += temp;
            temp = (temp-root->val)/10;
            return;
        }
        
        temp = temp*10 + root->val;
        if(root->left) solve(root->left,ans, temp);
        if(root->right) solve(root->right, ans, temp);
        temp = (temp - root->val)/10;
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        long long temp = 0;
        solve(root, ans, temp);
        return ans;
    }
};