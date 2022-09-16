 public:
    void revPreorder(Node*root,int level,vector<int>&ans)
    {
        if(root==NULL) return;
        
        if(level==ans.size())
         ans.push_back(root->data);
        revPreorder(root->right,level+1,ans);
        revPreorder(root->left,level+1,ans);     
    }
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
      vector<int> ans;//storing right view
       revPreorder(root,0,ans);
       return ans;
    }