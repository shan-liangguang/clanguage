#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool a[50000] = {0};//0为素数 
ll b[50000];//存储素数 
bool c[1000009] = {0};//1为素数 
int main()
{
	//50000
	ll l,r,i,j,cnt = 1,sum = 0;
	cin >> l >> r;
	//找出50000前的素数
	for(i = 2;i*i<50000;i++)
	{
		if(!a[i])
		{
			for(j = i*i;j<50000;j+=i)
			{
				a[j] = 1;
			}
		}
	}
	for(i = 2;i<50000;i++)
	{
		if(!a[i])
		{
			b[cnt] = i;
			cnt++;
		}
	}	
	
	for(i = 1;i<cnt;i++)
	{
		for(j = l/b[i]*b[i]+b[i];j<=r;j+=b[i])
		{
			if(j!=b[i])
			c[j-l] = 1;
		}
	}
	for(i = 0;i<=r-l;i++)
	{
	    if(!c[i])
		sum++;
	}
	if(l>=2)
	cout << sum;
	else
	cout << sum+l-2; 
	return 0;
 } 
