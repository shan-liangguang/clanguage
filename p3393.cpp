#include<bits/stdc++.h>
#include <cstdio>
using namespace std;
bool isnp[100000000] = {0};
int a[10000000]; 
int x,cnt = 1;
int main()
{
	int n,q,i,j;
	cin >> n >> q;
	for(i = 2;i*i<=n;i++)
	{
		if(!isnp[i])
		{ 
			for(j = i*i;j<=n;j+=i)
			{
				isnp[j] = true;
			}
		}
	}
	for(i = 2;i<=1000000;i++)
	{
		if(isnp[i] == false)
		{
			a[cnt] = i;
			cnt++;
		}
	}
	for(i = 0;i<q;i++)
	{
		cin >> x;
		printf("%d\n",a[x]);
	}
	return 0;
 } 
