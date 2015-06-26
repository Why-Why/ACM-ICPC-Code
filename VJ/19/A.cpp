#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
	
using namespace std;

const int MaxN=5;
const int mod=1000000000+7;

void cheng(int a[][MaxN],int b[][MaxN],int N,int M,int L)
{
	long long temp;
	int ret[MaxN][MaxN];

	for(int i=1;i<=N;++i)
		for(int j=1;j<=L;++j)
		{
			temp=0;

			for(int k=1;k<=M;++k)
				temp=(temp+(a[i][k]*b[k][j])%mod)%mod;

			ret[i][j]=temp;
		}

	for(int i=1;i<=N;++i)
		for(int j=1;j<=L;++j)
			a[i][j]=ret[i][j];
}

void MatMi(int a[][MaxN],int N,long long k)
{
	int ret[MaxN][MaxN]={0};

	for(int i=1;i<=N;++i)
		ret[i][i]=1;

	while(k)
	{
		if(k&1)
			cheng(ret,a,N,N,N);

		cheng(a,a,N,N,N);
		k>>=1;
	}

	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			a[i][j]=ret[i][j];
}

//#define I64d lld

void dis(int a[][MaxN],int N)
{
	for(int i=1;i<=N;++i,cout<<endl)
		for(int j=1;j<=N;++j)
			cout<<a[i][j]<<' ';
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int a[5][5];
	long long x,y;
	int n;

	a[1][1]=-1;
	a[1][2]=-1;
	a[2][1]=1;
	a[2][2]=0;

	scanf("%lld %lld %d",&x,&y,&n);
	
	MatMi(a,2,(n-1)/2);

	if(n&1)
		printf("%lld\n",(((x*a[1][1]+y*a[2][1])%mod)+mod)%mod);
	else
		printf("%lld\n",(((x*a[1][2]+y*a[2][2])%mod)+mod)%mod);

	return 0;
}
