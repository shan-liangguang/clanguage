#include<bits/stdc++.h>
using namespace std;
int a[100005];
int v[1000005] = {0};
int c[1000005] = {0};
int main()
{
	int n,i,j;
	cin >> n;
	for(i = 0;i<n;i++)
	{
		cin >> a[i];
		v[a[i]]++;
	}
	for(i = 1;i<=1000000;i++)
	{
		for(j = i;j<=1000000;j+=i)
		{
			c[j] += v[i];
		}
	}
	for(i = 0;i<n;i++)
	{
		cout << c[a[i]]-1 << endl;
	}
	return 0;
}
