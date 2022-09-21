
int floorInBST(TreeNode<int> * root, int X)

{
    // if (root == NULL) return -1;
    int floor=-1;
    while(root)
    {
        if(root->val==X){
            floor=root->val;
            return floor;
        } 
        if(root->val<X)
        {
             floor=root->val;
            root=root->right;
        }
        else
        {
           
            root=root->left;
        }
        
    }
    return floor;
}