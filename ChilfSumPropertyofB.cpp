#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void reorder(BinaryTreeNode < int > * root) {
    int child=0;
    if(root==NULL) return;
    if(root->left){
        child+=root->left->data;
    }
    if(root->right){
        child+=root->right->data;
    }
    if(child>=root->data) root->data=child;
    else{
        if(root->left) root->left->data=root->data;
        else if(root->right) root->right->data=root->data;
    }
    reorder(root->left);
    reorder(root->right);
    
    int res=0;
    if(root->left) res+=root->left->data;
    if(root->right) res+=root->right->data;
    if(root->left or root->right){
        root->data=res;
    }
    
}  
void changeTree(BinaryTreeNode < int > * root) {
    reorder(root);   
}




















