class Solution {
public:
    vector<TreeNode*>ans;
    int n=ans.size();
    TreeNode*arraytobst(int l,int r) // isse hi banega new tree 
    {
        if(l>r) // base case
        {
            return NULL;
        }
        int mid=(r+l)/2; // har bar mid value nikalenge array ki usko root assign kar denge fir 
        TreeNode*root=ans[mid]; // mid value ko root assign kae diya 
        root->left=arraytobst(l,mid-1); // same left side 
        root->right=arraytobst(mid+1,r); // right side
        return root;
    }
    void inorder(TreeNode*root) // isse given tree ko array me badal lenge
    {
        if(root==NULL) return;
        inorder(root->left);
        ans.push_back(root);
        inorder(root->right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return  arraytobst(0,ans.size()-1); // ans return karega ye 
    }
};