#include <bits/stdc++.h>
using namespace std;
int main()
{
	int l,r;
	cin >> l >> r;
	int i,j,sum;
	for(i = l;i<r+1;i++)
	{
		if(i<2)
		sum++;
		for(j = 2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				sum++;
				break;
			}
		}
	}
	cout << r-l+1-sum;
}
