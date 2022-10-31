#include <iostream>
using namespace std;
int b[100001];
bool a[100001],c[100001];
char name[100001][11];
int main()
{
    int n,m,i,locate = 0;
    cin >> n >> m;
    for(i = 0;i<n;i++)
    {
        cin >> a[i] >> name[i];
    }
    for(i = 0;i<m;i++)
    {
        cin >> c[i] >> b[i];
        if(a[locate] == false)//√ÊœÚ¿Ô
        {
            if(c[i] == true)//”“
            {
                locate += b[i];
                locate %= n;
            }
            else
            {
                locate -= b[i];
                while(locate<0)
                {
                    locate += n;
                }
            }
        }
        else if(a[locate] == true)
        {
            if(c[i] == true)
            {
                locate -= b[i];
                while(locate<0)
                {
                    locate += n;
                }
            }
            else
            {
                locate += b[i];
                locate %= n;
            }
        }
    }
    cout << name[locate];
    
    return 0;
}
