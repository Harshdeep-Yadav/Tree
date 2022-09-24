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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0; // pointer at 0 index of preorder
        return buildbst(preorder,i,INT_MAX);
    }
    TreeNode* buildbst(vector<int>preorder,int &i,int bound)
    //bound is checking next given value of vector moving to left or right
    {
       if(i==preorder.size()||preorder[i]>bound) return NULL;
        TreeNode*root=new TreeNode(preorder[i++]);
        root->left=buildbst(preorder,i,root->val);
        root->right=buildbst(preorder,i,bound);
        
        return root;
    }
};  