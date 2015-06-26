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

const int mod=9973;

int map1[15][15];
int N,K;

void dis(int a[][15])
{
	for(int i=1;i<=N;++i,cout<<endl)
		for(int j=1;j<=N;++j)
			cout<<a[i][j]<<' ';
}

void cheng(int a[][15],int b[][15])
{
	int temp;
	int ret[15][15];

//	dis(a);
//	dis(b);

	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
		{
			temp=0;
			for(int k=1;k<=N;++k)
				temp=(temp+a[i][k]*b[k][j])%mod;

			ret[i][j]=temp;
		}

//	dis(a);

	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			a[i][j]=ret[i][j];
}

void getans()
{
	int ans[15][15];

	memset(ans,0,sizeof(ans));

	for(int i=1;i<=N;++i)
		ans[i][i]=1;

	while(K)
	{
		if(K&1)
			cheng(ans,map1);

		cheng(map1,map1);
		K>>=1;
	}

	int num=0;

	for(int i=1;i<=N;++i)
		num=(num+ans[i][i])%mod;
	
	printf("%d\n",num);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d\n",&T);

	while(T--)
	{
		scanf("%d %d",&N,&K);

		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				scanf("%d",&map1[i][j]);

		getans();
	}
	
	return 0;
}
