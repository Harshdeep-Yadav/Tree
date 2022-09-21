int findCeil(Node* root, int x) {
    // if (root == NULL) return -1;
    int ceil=-1;
    while(root)
    {
        if(root->data==x){
            ceil=root->data;
            return ceil;
        } 
        if(root->data<x)
        {
            root=root->right;
        }
        else
        {
            ceil=root->data;
            root=root->left;
        }
        
    }
    return ceil;
}