#include <bits/stdc++.h>
using namespace std;
int a[50][50] = {0},b[50][50] = {0};
int tx[4] = {0,1,0,-1},ty[4] = {-1,0,1,0};
struct info
{
	int x,y;
};
int main()
{
	int n,i,j;
	cin >> n;
	for(i = 1;i<=n;i++)
	{
		for(j = 1;j<=n;j++)
		{
			cin >> a[i][j];
		}
	}
	queue <info> q;
	info tmp = {0,0};
	q.push(tmp);
	while(!q.empty())
	{
		for(i = 0;i<4;i++)
		{
			tmp.x = q.front().x+tx[i];
			tmp.y = q.front().y+ty[i];
			if(tmp.x>=0&&tmp.x<=n+1&&tmp.y>=0&&tmp.y<=n+1&&a[tmp.x][tmp.y]==0&&b[tmp.x][tmp.y]==0)
			{
				q.push(tmp);
				b[tmp.x][tmp.y] = 1;
			}
		}
		q.pop();
	}	
	for(i = 1;i<=n;i++)
	{
		for(j = 1;j<=n;j++)
		{
			if(a[i][j]==0&&b[i][j]==1)
			{
				cout << 0 << ' ';
			}
			else if(a[i][j]==0&&b[i][j]==0)
			{
				cout << 2 << ' ';
			}
			else
			{
				cout << 1 << ' ';
			}
		}
		cout << endl;
	}
	return 0;
 } 
