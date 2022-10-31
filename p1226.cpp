#include <iostream>
#include <cstdio>
using namespace std;
long long s = 1;
void quick_power(long long a,long long b,long long mod)
{
    int i;
   	while(b>0)
    {
        if(b & 1 == 1)
        {
            s*=a;
            s%=mod;
        }
        
        b >>= 1;
        a*=a;
        a%=mod;
    }
}
int main()
{
    long long a,b,p;
    cin >> a >> b >> p;
    quick_power(a,b,p);
    printf("%lld^%lld mod %lld=%lld",a,b,p,s);
    return 0; 
}
