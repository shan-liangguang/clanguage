#include <bits/stdc++.h>
using namespace std;
int v[30],w[30],dp[30005][30];
int main()
{
	int n,m,i,j;
	cin >> n >> m;
	for(i = 1;i<=m;i++)
	{
		cin >> v[i] >> w[i];
	}
	for(i = 0;i<=n;i++)
	{
		for(j = 0;j<=m;j++)
		{
			if(i==0||j==0)
			{
				dp[i][j] = 0;
			}
			else if(i>=v[j])
			dp[i][j] = max(dp[i][j-1],dp[i-v[j]][j-1]+v[j]*w[j]);
		}
	}
	cout << dp[n][m];
	return 0;
}
