#include <iostream>
#include <cmath>
using namespace std;
int n,k,cnt = 0;
int a[22];
int isprime(int y)
{
    int l;
    for(l = 2;l<=sqrt(y);l++)
    {
        if(y%l==0)
        {
            return 0;
        }
    }
    if(y==1)
    {
        return 0;
    }
    else
    return 1;
}
void fun(int x,int need,int sum)
{
    int j;
    if(!need)
    {
        cnt += isprime(sum);
    }
    else
    {
        for(j = x;j<=n-need+1;j++)
        {
            fun(j+1,need-1,a[j]+sum);
        }
    }    
}
int main()
{
    int i;
    cin >> n >> k;
    for(i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    fun(1,k,0);
    cout << cnt;
    return 0;
}
