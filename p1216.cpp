#include <bits/stdc++.h>
using namespace std;
int arr[1005][1005];
int dp[1005][1005];
int main()
{
	int n,i,j;
	cin >> n;
	for(i = 1;i<=n;i++)
	{
		for(j = 1;j<=i;j++)
		{
			cin >> arr[i][j];
		 } 
	}
	for(i = 1;i<=n;i++)
	{
		for(j = 1;j<=i;j++)
		{
			if(i==1&&j==1)
			{
				dp[i][j] = arr[i][j];
			}
			else if(j==1)
			{
				dp[i][j] = dp[i-1][j]+arr[i][j];
			}
			else if(j==i)
			{
				dp[i][j] = dp[i-1][j-1]+arr[i][j];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-1])+arr[i][j];
			}
		}
	}
	int ans = 0;
	for(i = 1;i<=n;i++)
	{
		ans = max(ans,dp[n][i]);
	 } 
	 cout << ans;
}
