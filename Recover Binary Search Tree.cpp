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



//  brute way
class Solution {
public:
    vector<int>v;
    void inorder(TreeNode*root)
    {
        if(root==NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
        
    }
    void recover(TreeNode*root,int &i) // for recovering new BST 
    {
        if(!root) return;
        recover(root->left,i);
        root->val=v[i++]; // jo nya tree banega uski root value sorted vector se lake dalenge  
        recover(root->right,i);
    }
    void recoverTree(TreeNode* root) {
        int i=0;
        if(root==NULL) return;
        inorder(root);
        sort(v.begin(),v.end());
        recover(root,i);
    }
};


//  optimal solution
class Solution {

    private:
        TreeNode*first,*last, *prev,*middle; // first violation
        // prev; // storing the prev guy in inorder traversal
        // middle; // adjecent one
        // last; // last violation
    private:
    void inorder(TreeNode*root)
    {
        if(!root) return;
        inorder(root->left);
        if(prev!=NULL &&(root->val<prev->val))
         //   prev!=NULL->jab prev me koi value ho
            //root->val<prev->val-> ye first voilation hoga 
        {
            // agar pehle voilation hai 
            if(first==NULL)
            {
                first=prev;
                middle=root;
            }
            else
                // dusra voilation hoga ye
                last=root;
        }
        prev=root;
        inorder(root->right);
            
    }
    public:
    void recoverTree(TreeNode* root) {
        first=last=prev=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first&&last) swap(first->val,last->val); //jab adjecent ni hai wala case
        else if (first &&middle) // jab adjcent honge
            swap(first->val,middle->val);
    }
};




















