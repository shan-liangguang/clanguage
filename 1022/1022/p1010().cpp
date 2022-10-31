#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
void sep(int n)   
{
    bool f = false;
    int i, cnt = 0;
    int a[31];//存2的多少次方
    if (n == 0)
    {
        if (f)
        {
            cout << '+';
            f = true;
        }
        cout << '(' << 0 << ')';
    }
    else if (n == 2)
    {
        if (f)
        {
            cout << '+';
            f = true;
        }
        cout << 2;
    }
    else if (n > 2)
    {
        for (i = 0; i < 31; i++)
        {
            if (n & 1)
            {
                a[cnt] = i;
                cnt++;
            }
            n >>= n;
        }
        if (f)
        {
            cout << '+';
            f = true;
        }
        for (i = 0; i < cnt; i++)
        {
            cout << 2 << '(';
            sep(a[i]);
            cout << ')';
        }
    }
}
int main()
{
    int n;
    cin >> n;
    sep(n);
    return 0;
}