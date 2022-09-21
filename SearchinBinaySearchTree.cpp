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
    TreeNode* searchBST(TreeNode* root, int val) {
       while(root!=NULL&&root->val!=val) // rooot null ni hai aur val given node ke bhi equL NI HAI to
       {
           root=val<root->val?root->left:root->right; // chotti hai to left ni hai to right
       }
        return root; // OP RETURN 
    }
};