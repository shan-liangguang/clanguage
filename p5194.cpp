#include <bits/stdc++.h>
using namespace std;
int n,c,sum = 0,ans = 0;
int w[1005],a[1005] = {0};
long long b[1005] = {0};
void dfs(int k)//°´ÖØÁ¿ËÑË÷ 
{
	 int i,j;
	 for(i = n-1;i>-1;i--)
	 {
	 	if(ans>=b[i]+sum)
	 	{
	 		return;
		 }
	 	if(w[i]<=k&&!a[i])
	 	{
	 		a[i] = 1;
	 		sum += w[i];
	 		dfs(k-w[i]);
	 		sum -= w[i];
	 		a[i] = 0;
		}
	 }
	 ans = max(ans,sum);
	 
}
int main()
{
	cin >> n >> c;
	int i;
	for(i = 0;i<n;i++)
	{
		cin >> w[i];
		if(i==0)
		{
			b[i] = w[i];
		}
		else
		b[i] = b[i-1]+w[i];
		cout << b[i] << endl;
	}
	dfs(c);
	cout << ans;
	return 0;
}
