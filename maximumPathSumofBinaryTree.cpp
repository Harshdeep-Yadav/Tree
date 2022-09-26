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
    int maxPathDown(TreeNode*node,int & maxi)
    {
        if(node==NULL) return 0;
        
        int left=max(0,maxPathDown(node->left,maxi)); // this give us left side maximum sum
        int right=max(0,maxPathDown(node->right,maxi));// this for right
        
        maxi=max(maxi,left+right+node->val); // storing maximum sum when backtracking 
        return max(left,right)+node->val; 
//         max(left,right) -> will tell us which path we have to follow or how have large value
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN; // for maximum ans take int_min
        maxPathDown(root,maxi);
        return maxi; // storing ans;
    }
};