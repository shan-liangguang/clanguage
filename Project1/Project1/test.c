#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    int i = 0;
//    int n = 0;
//    int l = 0;
//    int j = 0;
//    int t = 0;
//    scanf("%d", &t);
//    for (i = 0; i < t; i++)
//    {
//        int min = 0;
//        int sum = -1;
//        char s[100001] = { 0 };
//        int k = 0;
//        scanf("%s%d", s, &k);
//        int count[27] = { 0 };
//        int locate[27][100001] = { 0 };
//        for (j = 0; j < strlen(s); j++)
//        {
//            locate[s[j] - 'a'][count[s[j] - 'a']] = j;
//            count[s[j] - 'a']++;
//        }//记录位置和数量
//        for (l = 0; l<26 && count[l]>k - 1; l++)
//        {
//            sum++;
//            for (n = 0; n + k - 1 < count[l]; n++)
//            {
//                if (locate[l][n + k - 1] - locate[l][n] < min || sum == 1)
//                {
//                    min = locate[l][n + k - 1] - locate[l][n];
//                }
//            }
//        }
//        printf("%d\n", min);
//    }
//    return 0;
//}
#include <stdio.h>
#include <math.h>
int main()
{
    int T = 0;
    scanf("%d", &T);
    int i = 0;
    for (i = 0; i < T; i++)
    {
        int a = 0;
        int b = 0;
        int r = 0;
        int h = 0;
        scanf("%d%d%d%%d", &a, &b, &r, &h);
        double result = 0.0;
        int an = a > b ? (a - b) : (b - a);
        result = pow(h, 2) + an * 3.1415926535 * r / 180.0;
        printf("%lf\n", result);
    }
    return 0;
}
