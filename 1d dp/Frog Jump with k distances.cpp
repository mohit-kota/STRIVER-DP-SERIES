#include<bits/stdc++.h>

using namespace std;

int recurWithmemo(int ind,int k,int arr[],map<int,int>&mp)
{
	if(ind == 0)
	{
		return 0;
	}
	if(mp[ind]!=0)
	{
		return mp[ind];
	}
	int mincost = INT_MAX;
	for(int i=1;i<=k;i++)
	{
		if(ind-i>=0)
		{
			int cost = recurWithmemo(ind-i,k,arr,mp) + abs(arr[ind]-arr[ind-i]);
			mincost = min(mincost,cost);
		}
	}

	return mp[ind] = mincost;
}

int tabulation(int n,int k,int arr[])
{
	int dp[n] = {0};
	dp[0] = 0;
	for(int i=1;i<n;i++)
	{
		int mincost = INT_MAX;
		for(int j=1;j<=k;j++)
		{
			if(i-j>=0)
			{
				int cost = dp[i-j] + abs(arr[i]-arr[i-j]);
				mincost = min(mincost,cost);
			}
		}
		dp[i] = mincost;
 	}

 	return dp[n-1];

}

void solve(int n,int k,int arr[])
{
	map<int,int>mp;
	// recursion with memoization applied 
	cout<<recurWithmemo(n-1,k,arr,mp)<<endl;

	// tabulation approach 
	cout<<tabulation(n,k,arr)<<endl;
}

int main()
{
	int n , k;
	cin >> n >> k;

	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}

	solve(n,k,arr);
}