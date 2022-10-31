#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int h[301];
int main()
{
    int n,i;
    long long sum = 0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> h[i];
    }
    sort(h,h+n);
    sum += pow(h[n-1],2);
    int *l = h,*r = h+n-1;
    bool f = true;
    while(l<r)
    {
        sum += pow(*r-*l,2);
        if(f)
        {
            f = !f;
            r--;
        }
        else
        {
            f = !f;
            l++;
        }
    }
    cout << sum;
    return 0;
}
