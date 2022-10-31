#include <iostream>
using namespace std;
int a[41][41] = {0};
int main()
{
    int n,x,y,i,j;
    cin >> n;
    x = 1;
    y = n/2+1;
    a[x][y] = 1;
    for(i = 2;i<=n*n;i++)
    {
        if(x == 1&&y != n)
        {
            x = n;
            y += 1;
            a[x][y] = i;
        }
        else if(x != 1&&y==n)
        {
            y = 1;
            x -= 1;
            a[x][y] = i;
        }
        else if(x == 1&&y == n)
        {
            x += 1;
            a[x][y] = i;
        }
        else
        {
            if(a[x-1][y+1] == 0)
            {
                x -= 1;
                y += 1;
                a[x][y] = i;
            }
            else
            {
                x+=1;
                a[x][y] = i;
            }
        }
    }
    for(i = 1;i<=n;i++)
    {
        for(j = 1;j<=n;j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
