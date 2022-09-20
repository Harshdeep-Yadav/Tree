 TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        map<int ,int > mp; // 
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;//this will put all the inorder elements in hashmap mp
        }
        
        TreeNode*root=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp); //recursive call for tree building
            return root;
    }

    TreeNode*buildTree(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd,map<int,int>&map)
    {
        if(preStart>preEnd||inStart>inEnd) return NULL; //

        TreeNode*root=new TreeNode(preorder[preStart]); // new root for constructing tree
        int inRoot=map[root->val]; // find the root taken from preorder in inorder (map)
        int numleft=inRoot-inStart; // num left in inorder vector for left sub tree in inorder
        root->left=buildTree(preorder,preStart+1,preStart+numleft,inorder,inStart,inRoot-1,map);
        root->right=buildTree(preorder,preStart+numleft+1,preEnd,inorder,inRoot+1,inEnd,map);
        return root;
    }

    // inorder [1,    2,3,     4]
    //          ^              ^
    //          |              |
    //          inStart       inEnd

    // preorder [8,    5,6,        7]
    //           ^                 ^  
    //           |                 |  
    //         preStart         preEnd