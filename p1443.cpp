#include <bits/stdc++.h>
using namespace std;
int n,m,x,y;
int ax[10] = {1,2,2,1,-1,-2,-2,-1};//·½Ïò 
int ay[10] = {-2,-1,1,2,2,1,-1,-2};
int a[410][410];
struct info
{
	int tx;
	int ty;
	int min;
};
queue<info> q;
int main()
{
	int i,j;
	cin >> n >> m >> x >> y;
	info tmp = {x,y,0};
	q.push(tmp); 
	for(i = 1;i<=n;i++)
	{
		for(j = 1;j<=m;j++)
		{
			a[i][j] = -1;
		}
	}
	a[x][y] = 0;
	while(!q.empty())
	{
		for(i = 0;i<8;i++)
		{
			if(a[q.front().tx+ax[i]][q.front().ty+ay[i]]==-1&&q.front().tx+ax[i]>0&&q.front().tx+ax[i]<n+1&&q.front().ty+ay[i]>0&&q.front().ty+ay[i]<m+1)
			{
				tmp.tx = q.front().tx+ax[i];
				tmp.ty = q.front().ty+ay[i];
				tmp.min = q.front().min + 1;
				q.push(tmp); 
				a[tmp.tx][tmp.ty] = tmp.min;
			}
		}
		q.pop();
	}
	for(i = 1;i<=n;i++)
	{
		for(j = 1;j<=m;j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
 } 
