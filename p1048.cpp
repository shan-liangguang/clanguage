#include <bits/stdc++.h>
using namespace std;
int ti[105],v[105];
int dp[105][1005];
int main()
{
	int t,n,i,j;
	cin >> t >> n;
	for(i = 1;i<=n;i++)
	{
		cin >> ti[i] >> v[i];
	}
	for(i = 0;i<=n;i++)
	{
		for(j = 0;j<=t;j++)
		{
			if(i==0||j==0)
			{
				dp[i][j] = 0;
			}
			else if(j>=ti[i])
			{
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-ti[i]]+v[i]);
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout << dp[n][t];
}
