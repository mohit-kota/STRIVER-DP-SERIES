#include<bits/stdc++.h>

// using dp array 
int frogJump1(int n, vector<int> &heights)
{
    // Write your code here.
    int dp[n+1];
    memset(dp,0,sizeof dp);
    dp[0]=0;
   
    for(int i=1;i<n;i++)
    {
        int fs = dp[i-1] + abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;
        if(i>1)
        {
            ss = dp[i-2] + abs(heights[i]-heights[i-2]);
        }
        dp[i]=min(fs,ss);
    }
    return dp[n-1];
}

// Optimization for space 

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
     
    int prev = 0;
    int prev2 = 0;
   
    for(int i=1;i<n;i++)
    {
        int fs = prev + abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;
        if(i>1)
        {
            ss =prev2 + abs(heights[i]-heights[i-2]);
        }
        int curi=min(fs,ss);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}