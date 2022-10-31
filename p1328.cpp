#include <iostream>
using namespace std;
int Na[201],Nb[201];
void whowin(int *sa,int*sb,int a,int b)
{
    if(Na[a]==0)
    {
        if(Nb[b]==2||Nb[b]==3)
        {
            (*sa)++;
        }
        else if(Nb[b]==1||Nb[b]==4)
        {
            (*sb)++;
        }
    }
    else if(Na[a]==1)
    {
        if(Nb[b]==0||Nb[b]==3)
        {
            (*sa)++;
        }
        else if(Nb[b]==4||Nb[b]==2)
        {
            (*sb)++;
        }
    }
    else if(Na[a]==2)
    {
        if(Nb[b]==4||Nb[b]==1)
        {
            (*sa)++;
        }
        else if(Nb[b]==3||Nb[b]==0)
        {
            (*sb)++;
        }
    }
    else if(Na[a]==3)
    {
        if(Nb[b]==4||Nb[b]==2)
        {
            (*sa)++;
        }
        else if(Nb[b]==0||Nb[b]==1)
        {
            (*sb)++;
        }
    }
    else
    {
        if(Nb[b]==1||Nb[b]==0)
        {
            (*sa)++;
        }
        else if(Nb[b]==2||Nb[b]==3)
        {
            (*sb)++;
        }
    }
}
int main()
{
    int n,na,nb,i,suma=0,sumb=0;
    cin >> n >> na >> nb;
    for(i = 0;i<na;i++)
    {
        cin >> Na[i];
    }
    for(i=0;i<nb;i++)
    {
        cin >> Nb[i];
    }
    for(i = 0;i<n;i++)
    {
       whowin(&suma,&sumb,i%na,i%nb); 
    }
    cout << suma <<" "<< sumb;
    return 0;
}
