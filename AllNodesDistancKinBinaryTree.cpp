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
    void marktoParent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&prnt_trck,TreeNode *target)
     { // marking for parents
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode*current=q.front();
            q.pop();
            if(current->left)
            {
                prnt_trck[current->left]=current;
                q.push(current->left);
            }
            if(current->right)
            {
                prnt_trck[current->right]=current;
                q.push(current->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>prnt_trck;
        marktoParent(root,prnt_trck,target);
        
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>queue;
        queue.push(target);
        vis[target]=true;
        int curr_level=0; // this for count the distance
        while(!queue.empty())
        {
            
            int sz=queue.size();
            if(curr_level==k)
            {
                break;
            }
            curr_level++;
            for(int i=0;i<sz;i++)
            {
                TreeNode*node=queue.front();
                queue.pop();
                if(node->left && !vis[node->left])
                {
                    queue.push(node->left);
                    vis[node->left]=true;
                }
                if(node->right && !vis[node->right])
                {
                    queue.push(node->right);
                    vis[node->right]=true;
                }
                if(prnt_trck[node] && !vis[prnt_trck[node]])
                {
                    queue.push(prnt_trck[node]);
                    vis[prnt_trck[node]]=true;
                }
            }
          
        }
        vector<int>ans;
        while(!queue.empty())
        {
            TreeNode*current=queue.front();
            queue.pop();
            ans.push_back(current->val);    
        }
        return ans;
    }
};