// ━━━━━━神兽出没━━━━━━
//      ┏┓       ┏┓
//     ┏┛┻━━━━━━━┛┻┓
//     ┃           ┃
//     ┃     ━     ┃
//     ████━████   ┃
//     ┃           ┃
//     ┃    ┻      ┃
//     ┃           ┃
//     ┗━┓       ┏━┛
//       ┃       ┃
//       ┃       ┃
//       ┃       ┗━━━┓
//       ┃           ┣┓
//       ┃           ┏┛
//       ┗┓┓┏━━━━━┳┓┏┛
//        ┃┫┫     ┃┫┫
//        ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年07月21日 星期二 13时45分50秒
// File Name     : B.cpp

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

const int MaxN=100005;

int dp1[MaxN][20];
int dp2[MaxN][20];
int logN[MaxN];			// logN[i]表示log(i)的值。

void init_RMQ(int n,int num[])
{
	logN[0]=-1;

	for(int i=1;i<=n;++i)
	{
		dp1[i][0]=num[i];
		dp2[i][0]=num[i];
		logN[i]=((i&(i-1))==0) ? logN[i-1]+1 : logN[i-1];	// !!!
	}

	for(int j=1;j<=logN[n];++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
		{
			dp1[i][j]=max(dp1[i][j-1],dp1[i+(1<<(j-1))][j-1]);
			dp2[i][j]=min(dp2[i][j-1],dp2[i+(1<<(j-1))][j-1]);
		}
}

int Max(int x,int y)
{
	int k=logN[y-x+1];

	return max(dp1[x][k],dp1[y-(1<<k)+1][k]);
}

int Min(int x,int y)
{
	int k=logN[y-x+1];

	return min(dp2[x][k],dp2[y-(1<<k)+1][k]);
}

int N,K;
int num[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int p1,p2;
	int minn,maxn;
	long long ans;
	long long LM;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&K);

		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);

		init_RMQ(N,num);
		ans=1;
		p1=1;
		minn=maxn=num[1];

		for(int i=2;i<=N;++i)
		{
			if(num[i]<minn)
			{
				minn=num[i];

				while(maxn-minn>=K)
				{
					++p1;
					maxn=Max(p1,i);
				}
			}
			else if(num[i]>maxn)
			{
				maxn=num[i];

				while(maxn-minn>=K)
				{
					++p1;
					minn=Min(p1,i);
				}
			}

			ans+=(i-p1+1);
		}

		printf("%I64d\n",ans);
	}
	
	return 0;
}
