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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val); // null hai to wahi given value return kar denge as a root
        TreeNode*curr= root; //  putting pointer at root
        while(true)
        {
           if(curr->val<=val) // if large hui to right
           {
               if(curr->right!=NULL) // null ni hai to right
                   curr=curr->right;
               else{
                  curr->right=new TreeNode(val); // aur agar null hai to uss given val ko hi node bna ke add kar denge 
                    break;
           }
           }
            else // warna left
            {
                if(val<=curr->val)
                {
                    if(curr->left!=NULL)
                        curr=curr->left;
                    else{
                        curr->left=new TreeNode(val);
                        break;
                    }
                }
            }
        }
        return root;
    }
};