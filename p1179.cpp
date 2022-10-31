#include <iostream>
using namespace std;
int howm2(int n)
{
    int cnt = 0;
    while(n)
    {
        if(n%10 == 2)
        {
            cnt++;
        }
        n /= 10;
    }
    return cnt;
}
int main()
{
    int l,r,sum = 0;
    cin >> l >> r;
    for(;l<=r;l++)
    {
        sum += howm2(l);
    }
    cout << sum;
    return 0;
}
