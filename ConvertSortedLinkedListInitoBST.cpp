class Solution {
public:
    TreeNode*helper(vector<int>nums,int l,int r)
    {
        if(l>r) return NULL;
        
        int mid=(l+r)/2;
        TreeNode*root=new TreeNode(nums[mid]);
        root->left=helper(nums,l,mid-1);
        root->right=helper(nums,mid+1,r);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>nums;
        while(head) // converting given linked list into array
        {
            nums.push_back(head->val);
            head=head->next;
        }
        return helper(nums,0,nums.size()-1);
    }
};