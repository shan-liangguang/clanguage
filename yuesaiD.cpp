#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int gcd(int x, int y)
{
    while(y^=x^=y^=x%=y);
    return x;
}
int main()
{
	int n,i,ans,d;
	cin >> n;
	for(i = 0;i<n;i++)
	{
		cin >> a[i];
	}
	if(a[0]!=a[1])
	{
	
	d = a[1]-a[0];
	for(i = 2;i<n;i++)
	{
		d = gcd(d,a[i]-a[i-1]);
	}
	ans = (a[n-1]-a[0])/d+1;
	cout << ans << endl;
}
else
cout << n << endl;
	return 0;
}
