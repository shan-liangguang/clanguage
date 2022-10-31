#include <iostream>
using namespace std;
char arr[100000] = {0};
int main()
{
    int i = 0,j=0,locate,a,b;
    while(1)
    {
        cin >> arr[i];
        i++;
        if(arr[i-1] == 'E')
        break;
    }
    i--;
    if(i==0)
    {
    	cout << 0 << ':' << 0 << endl << endl;
    	cout << 0 << ':' << 0 << endl;
	}
    for(j = 0;j<i;j++)
    {
        if(arr[j] == 'W')
        {
            a++;
            if((a>10&&a-1>b)||(b>10&&b-1>a))
            {
                cout << a << ':' << b <<endl;
                a=0;
                b=0;
            }
            else if(j==i-1)
        	{
        		cout << a << ':' << b <<endl;
                a=0;
                b=0;
			}
        }
        else
        {
            b++;
            if((a>10&&a-1>b)||(b>10&&b-1>a))
            {
                cout << a << ':' << b <<endl;
                a=0;
                b=0;
            }
            else if(j==i-1)
        	{
        		cout << a << ':' << b <<endl;
                a=0;
                b=0;
			}
        }
    }
    cout << endl;
    for(j=0;j<i;j++)
    {
        if(arr[j] == 'W')
        {
            a++;
            if((a>20&&a-1>b)||(b>20&&b-1>a))
            {
                cout << a << ':' << b;
                if(j != i-1)
                {
                    cout << endl;
                }
                a=0;
                b=0;
            }
            else if(j==i-1)
        	{
        		cout << a << ':' << b;
                a=0;
                b=0;
			}
        }
        else
        {
            b++;
            if((a>20&&a-1>b)||(b>20&&b-1>a))
            {
                cout << a << ':' << b;
                if(j != i-1)
                {
                    cout << endl;
                }
                a=0;
                b=0;
            }
            else if(j==i-1)
        	{
        		cout << a << ':' << b;
                a=0;
                b=0;
			}
        }
    }
    return 0;
}
