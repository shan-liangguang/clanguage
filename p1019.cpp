#include <bits/stdc++.h>
using namespace std;
int n;
char a[22][25];
int ans = 0,cnt = 0,sum = 0;
int c[22] = {0};
char b[2];
void dfs(char k[25])
{
	int i,j,l;
	cnt = 0;
	for(l = (!strcmp(b,k)) ? 0:1;l<strlen(k);l++)
	{
	
	for(j = 0;j<n;j++)
	{
		for(i = l;i<strlen(k);i++)
		{
			if(k[i]==a[j][i-l])
			{
				cnt++;
				if(cnt==strlen(k)-l)
				{
					break;
				}
			}
			else
			{
				cnt = 0; 
				break;
			}
		}
		if(cnt==strlen(k)-l&&c[j]<2&&strlen(&k[l])<strlen(a[j]))
		{
			int tmp1 = sum;
			if(strcmp(b,k))
			sum += strlen(a[j])-(strlen(k)-l);
			else
			sum += strlen(a[j]);
			c[j]++;
			dfs(a[j]);
			cnt = 0; 
			sum = tmp1;
			c[j]--;
		}
		else if(strlen(&k[l])>=strlen(a[j]))
		{
			cnt = 0;
		}	
		else if(c[j]==2)
		{
			cnt = 0;
			
		}
	}
		if(k[l+1]==0)
	{
		ans = max(ans,sum);
		return;
	}
}
}
int main()
{
	int i = 0;
	cin >> n;
	for(i = 0;i<n;i++)
	{
		cin >> a[i];
	}
	cin >> b; 
	dfs(b);
	cout << ans;
	return 0;
}
