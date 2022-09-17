
bool getpath(TreeNode*node,vector<int>&ans,int b)
{
    if(!node) return false;
    ans.push_back(node->val);
    if(node->val==b) return true;
    
    if(getpath(node,ans,b)||getpath(node,ans,b))
    {
                return true;
    }
        
    ans.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) 
{
    vector<int> ans;
    if(A==NULL) return ans;
    getpath(A,ans,B);
    return ans;
}