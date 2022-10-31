#include <iostream>
using namespace std;
int a[50003];
int len,n,m,i,mid,ans;
bool is(int x)
{
    int j,cnt = 0,now = 0;
    for(j = 1;j<=n+1;j++)
    {
        if(a[j]-a[now]<x)
        {
            cnt++;
        }
        else
        now = j;
        if(cnt > m)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin >> len >> n >> m;
    int l = 0,r = len;
    for(i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    a[0] = 0;
    a[n+1] = len;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(!is(mid))
        {
            r = mid;
        }
        else
        {
        	ans = mid;
            l = mid+1;
        }
    }
    cout << ans;
    return 0;
}
