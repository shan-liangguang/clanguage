#include <iostream>
#include <algorithm>
using namespace std;
long long a[100005];
int main()
{
    int n,k,i,j;
    cin >> n >> k;
    a[0] = 1;
    for(i = 1;i<=n;i++)
    {
        if(i<k+1)
        {
            for(j = 1;j<=i;j++)
            {
                a[i] += a[j-1];
            }
        }
        else
        {
            for(j = 1;j<=k;j++)
            {
                a[i] += a[i-j];
            }
        }
    }
    cout << a[n];
    return 0;
}
