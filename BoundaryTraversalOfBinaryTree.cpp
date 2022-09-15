void leftBoundary(Node*root,vector<int>&ans)
{
    Node*curr=root->left;
    while(curr)
    {
        if(!isLeaf(curr))
        {
            ans.push_back(curr->data); // agar leaf node ni hai to array me ghusa do
        }
        if(curr->left){
            curr=curr->left; // agar left hai to age left me hi bda do
        }
        else{
            curr=curr->right; // agar left me null hai to right me jao
        }

    }
}

void rightBoundary(Node*root,vector<int> &ans)
{
    Node*curr=root->right;
    vector<int> rb;
    while(curr)
    {
        if(!isLeaf9curr) rb.push_back(curr->data);
        if(curr->right){
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
    }
    for(int i=rb.size()-1;i>=0;i--)
    {
        ans.push_back(rb[i]);
    }
}


void addleaves(Node*root,vector<int>ans)
{
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left) addleaves(root->left,ans);
    if(root->right) addleaves(root->right,ans);
}

vector<int> boundary(Node*root)
{
    vector<int> ans;
    if(!root) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    leftBoundary(root,ans);
    addleaves(root,ans)
    rightboundary(root,ans);
    return ans;
}

private:

    void leftsolve(Node* root, vector<int> &v)

    {

        if(root==NULL|| (root->left==NULL && root->right==NULL))

        return;

        v.push_back(root->data);

        if(root->left)

        leftsolve(root->left,v);

        else

        leftsolve(root->right,v);

    }

    void leafsolve(Node* root, vector<int> &v)

    {

        if(root==NULL )

        return;

        if(root->left == NULL && root->right==NULL)

        {

        v.push_back(root->data);

        return;

        }

        leafsolve(root->left,v);

        leafsolve(root->right,v);

    }

    void rightsolve(Node* root, vector<int> &v)

    {

        if(root==NULL|| (root->left==NULL && root->right==NULL))

        return;

        if(root->right)

        rightsolve(root->right,v);

        else

        rightsolve(root->left,v);

        v.push_back(root->data);

    }

public:

    vector <int> boundary(Node *root)

    {

        //Your code here

        vector<int> ans;

        if(root==NULL)

        return ans;

        ans.push_back(root->data);

        if(root->left == NULL && root->right==NULL)

        return ans;

        leftsolve(root->left,ans);

        leafsolve(root,ans);

        // leafsolve(root->right,ans);

        rightsolve(root->right,ans);

        return ans;

    }