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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if(inorder.size()!=postorder.size()) return NULL;
        map<int ,int > mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;//this will put all the inorder elements in hashmap mp
        }
        
                TreeNode*root=buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp); //recursive call for tree building
            return root;
    }
    TreeNode *buildTree(vector<int>& inorder,int inStart,int inEnd,vector<int>& postorder,int posStart,int posEnd ,map<int,int> &mp)
    {
        if(posStart>posEnd||inStart>inEnd) return NULL;
        
        TreeNode*root=new TreeNode(postorder[posEnd]); // root of the tree
        
        int inRoot=mp[postorder[posEnd]];
        int numLeft=inRoot-inStart;
         
        root->left=buildTree(inorder,inStart,inRoot-1,postorder,posStart,posStart+numLeft-1,mp); // for left subtree
        
        root->right=buildTree(inorder,inRoot+1,inEnd,postorder,posStart+numLeft,posEnd-1,mp); // for right subtree
    
    return root;
    }
};

// TC:- O(N),SC:- O(N)