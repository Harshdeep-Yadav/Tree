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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*>q;
        if(depth==1)
        {
            TreeNode*x=new TreeNode(val);
            TreeNode*y=root;
            root=x;
            root->left=y;
        }
        q.push(root);
        while(!q.empty())
        {
            int siz=q.size();
            depth--;
            if(depth==0) 
            {
                break;
            }
            while(siz--)
            {
                TreeNode*cur=q.front();
                q.pop();
                if(depth==1)
                {
                    if(cur->left!=NULL)
                    {
                        TreeNode*x=new TreeNode(val);
                        TreeNode*y=cur->left;
                        cur->left=x;
                        x->left=y;
                        q.push(x);
                    }
                    else
                    {
                        TreeNode*x=new TreeNode(val);
                        cur->left=x;
                        q.push(x);
                    }
                    if(cur->right)
                    {
                        TreeNode*x=new TreeNode(val);
                        TreeNode*y=cur->right;
                        cur->right=x;
                        x->right=y;
                        q.push(x);
                    }
                    else
                    {
                         TreeNode*x=new TreeNode(val);
                        cur->right=x;
                        q.push(x);
                    }
                }
                else
                {
                    if(cur->left!=NULL)
                    {
                        q.push(cur->left);    
                    }
                    if(cur->right!=NULL)
                    {
                        q.push(cur->right);
                    }
                }
            }
        }
        return root;
    }
};