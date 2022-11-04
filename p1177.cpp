#include <iostream>
using namespace std;
int arr[100010];
void q_sort(int*arr,int n)
{
    if(n<2)
    return;
    int l = 0,r = n-1;
    int a = arr[0];
    bool f = 0;
    while(r>l)
    {
        if(!f)
        {
            if(arr[r]<a)
            {
                arr[l] = arr[r];
                f = 1;
                l++;
            }
            else
            r--;
        }
        else
        {
            if(a<arr[l])
            {
                arr[r] = arr[l];
                f = 0;
                r--;
            }
            else
            l++;
        }
    }
    arr[l] = a;
    q_sort(arr,l+1);
    q_sort(arr+l+1,n-l-1);
}
int main()
{
    int n,i,j;
    cin >> n;
    for(i = 0;i<n;i++)
    {
        cin >> arr[i];
    }
    q_sort(arr,n);
	for(i = 0;i<n;i++)
	{
		cout << arr[i] << ' ';
	}
    return 0;
}
