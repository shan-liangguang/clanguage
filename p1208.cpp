#include <iostream>
using namespace std;
int p[5001],a[5001];
int main()
{
    int n,m,i,j,tmp,sum;
    cin >> n >> m;
    for(i = 0;i<m;i++)
    {
        cin >> p[i] >> a[i];
    }
    for(i = 0;i<m-1;i++)
    {
        for(j=0;j<m-i-1;j++)
        {
            if(p[j]>p[j+1])
            {
                tmp = p[j];
                p[j] = p[j+1];
                p[j+1] = tmp;
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    tmp = 0;
    sum = 0;
    for(i = 0;tmp<n;i++)
    {
        if(n-tmp>a[i])
        {
            tmp += a[i];
            sum += a[i]*p[i];
        }
        else
        {
	        sum += p[i]*(n-tmp);
            tmp = n;
        }
        
    }
    cout << sum;
    return 0;
}
