#include<bits/stdc++.h>

// Space optimized 
long long int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    long long int n = nums.size();
    long long int prev = nums[0];
    long long int prev2  = 0;
    for(int i=1;i<n;i++)
    {
         long long int take = nums[i];
        if(i>1) take+=prev2;
        long long int notTake = 0 + prev;
         long long int cur = max(take,notTake);
        prev2 = prev;
        prev = cur;
     }
    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    if(valueInHouse.size()==1)
    {
        return valueInHouse[0];
    }
    int n = valueInHouse.size();
    vector<int>tmp1,tmp2;
    for(int i=0;i<n;i++)
    {
        if(i!=0) tmp1.push_back(valueInHouse[i]);
        if(i!=n-1) tmp2.push_back(valueInHouse[i]);
    }
    
    return max(maximumNonAdjacentSum(tmp1),maximumNonAdjacentSum(tmp2));
}