class Solution{
 public:
 vector<Node*>ans;
void inorder(Node*root){
      
      if(root == NULL)
       return ;
       
       inorder(root->left);
       ans.push_back(root);
       inorder(root->right);
  }
   Node * inOrderSuccessor(Node *root, Node *x)
   
   {
      if(root==NULL)
        return root;
        
      inorder(root);
        
        if(x == ans[ans.size()-1])
         return NULL;
        for(int i=0;i<ans.size()-1;i++){
            
            if(ans[i]==x)
                return ans[i+1];
        }
        
        return NULL;
        
    }
    
    

};






class Solution{
 public:

   Node * inOrderSuccessor(Node *root, Node *x)
   
   {
      Node*successor=NULL:
      while(root!NULL)
      {
        if(x->val>=root->val)
        {
            root=root->right;
        }
        else{
            successor=root;
            root=root->left;
        }
      }
      return NULL;
   }
};