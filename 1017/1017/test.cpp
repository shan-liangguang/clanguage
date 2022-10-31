#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int arr[1000] = { 0 };
int main()
{
    int n;
    int m;
    cin >> n;
    cin >> m;

    while (m--)
    {
        int a;
        cin >> a;
        arr[a]++;
    }
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            cout << i << " ";
        }
    }
    return 0;
}