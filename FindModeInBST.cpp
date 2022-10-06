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
    void inorder(TreeNode* root,unordered_map<int,int> &map)
    {
        if(root==nullptr) return;
        inorder(root->left,map);
        map[root->val]++;
        inorder(root->right,map);
    }
    public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        vector<int> ans;
        inorder(root,mp);
        int maxfreq=0;
        for(auto &it:mp)
        {
            maxfreq=max(it.second,maxfreq);
        }
        for(auto &it:mp)
        {
            if(it.second==maxfreq)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
        
    }
};
