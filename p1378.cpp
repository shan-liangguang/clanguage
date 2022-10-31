#include <bits/stdc++.h>
using namespace std;
double n,l1,l2,l3,l4;
double sum = 0.0,m = 0.0,r[12] = {0.0};
double x[12],y[12];
bool a[12] = {0};
void dfs(int k)
{
	if(k==n+1)
	{
		m = max(m,sum);
		return ;
	}
	int i,j;
	for(i = 0;i<n;i++)
	{
		if(!a[i])//µãÎ´Ê¹ÓÃ 
		{
			r[i] = min(abs(l2-y[i]),abs(l4-y[i]));
			r[i] = min(r[i],abs(l1-x[i]));
			r[i] = min(r[i],abs(l3-x[i]));
			for(j = 0;j<n;j++)
			{
				if(a[j]&&j!=i)
				{
					if(sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2))-r[j]>0)
					{
						r[i] = min(sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2))-r[j],r[i]);
					}
					else
					r[i] = 0;
				}
			}
			sum += 3.1415926535*pow(r[i],2);
			a[i] = 1;
			dfs(k+1);
			sum -= 3.1415926535*pow(r[i],2);
			a[i] = 0;
		}
	}
		
}
int main()
{
	int i;
	cin >> n >> l1 >> l2 >> l3 >> l4;
	for(i = 0;i<n;i++)
	{
		cin >> x[i] >> y[i];
	}
	dfs(1);
	cout << (int)(abs(l1-l3)*abs(l2-l4)-m+0.5);
	return 0;
 } 
