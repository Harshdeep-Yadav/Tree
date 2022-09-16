
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        if(root==NULL){
            return ans;
        }
        q.push({root,0});
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            Node*node=p.first;
            int index=p.second;
            mp[index]=node->data; // whenever finds any value assigne to any line and get another 
            // node for that value again it replace but in top view it not this 
            if(node->left!=NULL){
                q.push({node->left,index-1});
            }
            if(node->right!=NULL){
                q.push({node->right,index+1});
            }
           
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};