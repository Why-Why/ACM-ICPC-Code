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
// Created Time  : 2015年07月17日 星期五 16时52分31秒
// File Name     : 3264.cpp

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

const int MaxN=50004;

int dp1[MaxN][20],dp2[MaxN][20];
int logN[MaxN];

void init(int N,int num[])
{
	logN[0]=-1;

	for(int i=1;i<=N;++i)
	{
		dp1[i][0]=num[i];
		dp2[i][0]=num[i];
		logN[i]=logN[i-1]+((i&(i-1))==0);
	}

	for(int j=1;j<=logN[N];++j)
		for(int i=1;i+(1<<j)-1<=N;++i)
		{
			dp1[i][j]=max(dp1[i][j-1],dp1[i+(1<<(j-1))][j-1]);
			dp2[i][j]=min(dp2[i][j-1],dp2[i+(1<<(j-1))][j-1]);
		}
}

int RMQ(int x,int y)
{
	int k=logN[y-x+1];

	return max(dp1[x][k],dp1[y-(1<<k)+1][k])-min(dp2[x][k],dp2[y-(1<<k)+1][k]);
}

int num[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,Q;
	int a,b;

	while(~scanf("%d %d",&N,&Q))
	{
		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);

		init(N,num);

		while(Q--)
		{
			scanf("%d %d",&a,&b);

			printf("%d\n",RMQ(a,b));
		}
	}
	
	return 0;
}
