#include<bits/stdc++.h>


// tabulation method
#include<bits/stdc++.h>
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    int dp[n];
    memset(dp,0,sizeof dp);
    dp[0]=nums[0];
    dp[1]=max(dp[0],nums[1]);
    for(int i=2;i<n;i++)
    {
        dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[n-1];
}

// space optimization 
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    int prev2 = nums[0];
    int prev  = max(nums[1],prev2);
    
    for(int i=2;i<n;i++)
    {
        int cur = max(prev2+nums[i],prev);
        prev2 = prev;
        prev = cur;
     }
    
    return prev;
}