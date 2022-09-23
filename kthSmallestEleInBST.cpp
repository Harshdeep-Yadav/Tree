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
    void inorder(TreeNode*root,int k,vector<int>&ans)
    {
        if(root==NULL) return;
        inorder(root->left,k,ans);
        ans.push_back(root->val);
        inorder(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root,k,ans);
        return ans[k-1];
        
    }
};


class Solution {
public:
    int ans=0;
    int cnt=0;
    int count(TreeNode*root,int k)
    {
        if(root==NULL) return 0;
        count(root->left,k);
        cnt++;
        if(cnt==k){
            ans=root->val;
        }
        count(root->right,k);
        return ans!=-1?ans:-1;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return 0;
        return count(root,k);
    }
};