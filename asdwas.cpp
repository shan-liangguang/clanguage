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
		x = tmp;
	}
	return y;
}
int main()
{
    int n,i,j,ans = 0;
    cin >> n;
    
    for(i = 1;i<=n;i++)
    {
        for(j = 1;j<=i;j++)
        {
            if(gcd(i,j)==1)
            {
                ans += n/i; 
            }
        }
    }
    cout << ans;
}
