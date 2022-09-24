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
     // -> two pointer approach 
    vector<int> ans;
    void inorder(TreeNode*root)
    {
        
        if(!root) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
        
    }
    bool findTarget(TreeNode* root, int k) {
    // -> two pointer approach 
        inorder(root);
        
        int l=0;
        int r=ans.size()-1;
        while(l<r)
        {
            if(ans[l]+ans[r]==k)
                return true;
            else if(ans[l]+ans[r]>k)
            {
                r--;
            }
            else
                l++;
        }                       // TC->o(N)
                                // SC->o(N) for using vector
        return false;
    }
};

class Solution {
    public:
    set<int>s;
    bool findTarget(TreeNode*root,int k)
    {
        if(!root) return false;
        if(s.find(k-root->val)!=s.end()) return true;
        s.insert(root->val);
        return findTarget(root->left,k)|| findTarget(root->right,k);
    }
};