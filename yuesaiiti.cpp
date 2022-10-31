#include <iostream>
using namespace std;
long long c[1000001][4];
void Func()
{
	int i,j;
	c[1][1] = 1;
	c[1][0] = 1;
	for(i = 2;i<=1000000;i++)
	{
		for(j = 0;j<=i&&j<=3;j++)
		{
			if(j==0)
			c[i][0] = 1;
			else
			c[i][j] = c[i-1][j]+c[i-1][j-1];
		}
	}
}
int main()
{
	int t,n,i;
	cin >> t;
	Func();
	for(i = 0;i<t;i++)
	{
		cin >> n;
		if(n==1)
		cout << 3 << endl;
		else if(n==2)
		cout << 3 << endl;
		else if(n==3)
		cout << 1 << endl;
		else
		{
			cout << c[n][3] << endl;
		}
	 } 
	return 0;
 } 
