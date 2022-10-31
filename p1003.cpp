#include <iostream>
using namespace std;
int x1[10001],y1[10001],x2[10001],y2[10001];
int main()
{
    int n,x,y,i,j;
    bool f = false;
    cin >> n;
    for(i = 0;i<n;i++)
    {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        x2[i] += x1[i];
        y2[i] += y1[i];
    }
    cin >> x >> y;
    for(i = n-1;i>-1;i--)
    {
        if(x>=x1[i]&&y>=y1[i]&&x<=x2[i]&&y<=y2[i])
        {
            cout << i;
            f = true;
            break;
        }
    }
    if(!f)
    {
        cout << -1;
    }
    
    return 0;
}
