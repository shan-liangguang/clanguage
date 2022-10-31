#include <iostream>
using namespace std;
#include <algorithm>
int p[30001];
int main()
{
    int w,n,i,sum = 0;
    cin >> w >> n;
    for(i = 0;i<n;i++)
    {
        cin >> p[i];
    }
    sort(p,p+n);
    int *l = p,*r = p+n-1;
    while(r-l>0)
    {
        if(*r+*l>w)
        {
            sum++;
            r--;
        }
        else
        {
            r--;
            l++;
            sum++;
        }
    }
    if(r==l)
    {
    	sum++;
	}
    cout << sum;
}
