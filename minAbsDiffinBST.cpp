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
    


 void inorder(TreeNode*root,vector<int> &ans)
    {
        if(!root) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        int n= ans.size();
        int min =INT_MAX;
        for(int i=0;i<n-1;i++)
        {
            int x=abs(ans[i]-ans[i+1]);
            if(x<min)
            {
                min=x;    
            }
        }
        return min;
    }
    
};