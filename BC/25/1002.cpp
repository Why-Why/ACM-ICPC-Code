#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int mod=1000000007;

unsigned long long C[55][55];
long long F[55][55];

void getC()
{
    for(int i=0;i<=50;++i)
        C[i][0]=1;

    for(int i=1;i<=50;++i)
        for(int j=1;j<=i;++j)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
}

void getF()
{
    for(int i=1;i<=50;++i)
        F[i][1]=F[1][i]=1;

    for(int i=2;i<=50;++i)
        for(int j=2;j<=i;++j)
        {
            for(int k=1;k<=j;++k)
                for(int l=0;l<=k;++l)
                    F[i][j]=(F[i][j]+(((C[j][k]*C[k][l])%mod)*F[i-1][j-l])%mod)%mod;
            F[j][i]=F[i][j];
        }
}

int main()
{
    getC();
    getF();

    int n,m;

    while(~scanf("%d %d",&n,&m))
    {
    if(n==0||m==0)
    cout<<1<<endl;
    else
        cout<<F[m][n]<<endl;
    }

    return 0;
}
