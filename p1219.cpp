#include <bits/stdc++.h>
using namespace std;
int row[14] = {0},col[14] = {0},ci[25] = {0},zhu[25] = {0};//��¼�У��У��ζԽ��ߣ��� 
int arr[14] = {0};
int ans = 0;
int n,cnt = 0;
void dfs(int k)
{
	if(k>n)
	{
		ans++;
		int i;
		for(i = 1;i<=n&&ans<4;i++)
		{
			cout << arr[i] << ' '; 
		}
		if(ans<4)
		cout << endl;
		return;
	}
	int i;
	for(i = 1;i<=n;i++)
	{
		if(!row[k]&&!col[i]&&!ci[k+i-2]&&!zhu[i-k+12])//��-��Ϊһ����ֵ��������С��0����һƫ����12��ͬ���м��� 
		{
			row[k] = 1;
			col[i] = 1;
			ci[k+i-2] = 1;
			zhu[i-k+12] = 1;
			arr[k] = i;
			dfs(k+1);
			row[k] = 0;
			col[i] = 0;
			ci[k+i-2] = 0;
			zhu[i-k+12] = 0;
			arr[k] = 0;
		}
	}
}
int main()
{

	cin >> n;
	dfs(1);
	cout << ans;
	return 0;
}
