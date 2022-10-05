
// class Solution {
// public:  // recursoin
//     int numTrees(int n) {
//         if(n<=1)
//             return 1;
//         int count=0;
//         for(int i=1;i<=n;i++)
//         {
//             count+=numTrees(i-1)*numTrees(n-i);
//         }
//         return count;
//     }
// };


class Solution {
public:  // using DP
    
    int fun(int n,vector<int> &dp)
    {
        if(n<=1) 
            return 1;
        int ans =0;
        if(dp[n]!=-1) return dp[n];

        for(int i=1;i<=n;i++)
        {
            ans+=fun(i-1,dp)*fun(n-i,dp);   
         }
        return dp[n]=ans;
    }
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return fun(n,dp);
    }
};

