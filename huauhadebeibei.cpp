#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
	if(x<y)
	{
		int tmp = y;
		y = x;
		x = tmp;
	}
	while(x%y!=0)
	{
		int tmp = y;
		y = x%y;
		x = y;
	}
	return y;
}
int main()
{
    int n,i,j,ans = 0,k = 0;
    cin >> n;
for(k = 1;k<=n;k++)
{
	
    for(i = 1;i<=k;i++)
    {
        for(j = 1;j<=i;j++)
        {
            if(gcd(i,j)==1)
            {	
                ans += k/i; 
            }
        }
   	}
   	cout << ans << ' ';
	ans = 0;
}
}
