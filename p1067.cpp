#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    int n,i,a;
    cin >> n;
    for(i = 0;i<n+1;i++)
    {
        cin >> a;
        if(i&&a>0)cout << '+';
        if(a<0)cout << '-';
        if(abs(a)!=1&&a!=0)cout << abs(a);
        if(n-i == 0&&abs(a)==1)cout << abs(a);
        if(a&&n-i!=0)cout << 'x';
        if(a&&n-i>1)cout << '^' << n-i;
    }
}
