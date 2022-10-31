#include <stdio.h>
int gcd(int i,int j)
{
    int l = 1;
    for(l = i;l>0;l--)
    {
        if(i%l==0&&j%l==0)
        {
            return l;
        }
    }
}
int main()
{
    int t = 0;
    int n,m,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        int i =1;
        int j = 1;
        int count = 0;
        for(i = 1;i<=n;i++)
        {
            for(j = 1;j<=m;j++)
            {
                if(gcd(i,j)%k==0)
                {
                    count++;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
