/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void markParent(TreeNode* root,  unordered_map<TreeNode*, TreeNode*> &parentPointer)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parentPointer[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parentPointer[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        //map parent and child using maps
        unordered_map<TreeNode*, TreeNode*> parentPointer;
        markParent(root,parentPointer);
        
        // target node ko queue me push krke transversal start kro
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> flag;
        q.push(target);
        flag[target] = true;
        int distance = 0;
        while(!q.empty())
        {
            int size = q.size();
            if(distance == k) break;
            distance++;
            
            for(int i=0; i<size; i++)
            {
                TreeNode*  node = q.front();
                q.pop();
                
                if(node->left && !flag[node->left])
                {
                    q.push(node->left);
                    flag[node->left] = true;
                }
                if(node->right && !flag[node->right])
                {
                    q.push(node->right);
                    flag[node->right] = true;
                }
                
                if(parentPointer[node] && !flag[parentPointer[node]])
                {
                    q.push(parentPointer[node]);
                    flag[parentPointer[node]] = true;
                }
            }
        }
        
        vector<int> res;
        while(!q.empty())
        {
            TreeNode* ans = q.front();
            q.pop();
            res.push_back(ans->val);
        }
        return res;
    }
};