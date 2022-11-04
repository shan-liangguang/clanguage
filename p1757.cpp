#include <bits/stdc++.h>
using namespace std;
int dp[1005],loc[1005],w[1005],v[1005],ma,tmp;
struct info
{
	int we,va;
};
info a[1005][1005];
int main()
{
	int m,n,i,j,k;
	cin >> m >> n;
	for(int i = 1;i<=n;i++)
	{
		cin >> w[i] >> v[i] >> tmp;
		ma = max(ma,tmp);
		loc[tmp]++;
		a[tmp][loc[tmp]].we = w[i];
		a[tmp][loc[tmp]].va = v[i];
	}
	for(i = 0;i<=ma;i++)//遍历每个组 
	{
		for(j = m;j>=0;j--)//遍历每个重量 
		{
			for(k = 1;k<=loc[i];k++)//遍历每个组的每个位置 
			{
				if(a[i][k].we<=j)// 
				{
					dp[j] = max(dp[j],dp[j-a[i][k].we]+a[i][k].va);
				}
			}
		}
	}
	cout << dp[m];
	return 0;
}
