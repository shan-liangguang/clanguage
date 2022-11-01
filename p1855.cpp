#include <bits/stdc++.h>
using namespace std;
int m[105],t[105],dp[210][210] = {0};
int main()
{
	int n,M,T,i,j,k;
	cin >> n >> M >> T;
	for(i = 1;i<=n;i++)
	{
		cin >> m[i] >> t[i];
	}
	for(i = 1;i<=n;i++)
	{
		for(j = M;j>=0;j--)
		{
			for(k = T;k>=0;k--)
			{
				if(j>=m[i]&&k>=t[i])
				dp[j][k] = max(dp[j][k],dp[j-m[i]][k-t[i]]+1);
			}
		}
	} 
	cout << dp[M][T]; 
	return 0;
}
