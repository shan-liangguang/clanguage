#include <bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005];
int main()
{
	int n,i,j,k,m1 = 0,m2 = 0,m,cnt = 0,cnt2 = 0,tmp,sum = 0,sum2 = 0;
	cin >> n;
	tmp = n;
	for(i = 0;i<n;i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(&a[0],&a[n]);
	for(k = 0;k<n;k++)
	{
		for(i = k;i<n;i++)
		{
			for(j = 0;j<n;j++)
			{
				if(a[i] == b[j])
				{
					cnt++;
					i++;
					
				}
			}
		}
		m1 = max(m1,cnt);
		cnt = 0;
	}
		for(k = 0;k<n;k++)
	{
		for(i = k;i<n;i++)
		{
			for(j = n-1;j>-1;j--)
			{
				if(a[i] == b[j])
				{
					cnt2++;
					i++;
				
				}
			}
		}
		m2 = max(m2,cnt2);
		cnt2 = 0;
	}
	m = max(m1,m2);
	cout << n-m << endl; 
	return 0;
}
