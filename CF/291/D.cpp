// ━━━━━━神兽出没━━━━━━
// 　　 ┏┓       ┏┓
// 　　┏┛┻━━━━━━━┛┻┓
// 　　┃           ┃
// 　　┃     ━     ┃
//     ████━████   ┃
// 　　┃           ┃
// 　　┃    ┻      ┃
// 　　┃           ┃
// 　　┗━┓       ┏━┛
// 　　  ┃       ┃
// 　　  ┃       ┃
// 　　　┃       ┗━━━┓
// 　　　┃           ┣┓
// 　　　┃           ┏┛
// 　　　┗┓┓┏━━━━━┳┓┏┛
// 　　　 ┃┫┫     ┃┫┫
// 　　　 ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年05月18日 星期一 09时59分39秒
// File Name     : D.cpp

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

int n,m,k;
int num[100005][7];

const int MaxN=100005;

int dp[MaxN][7][20];
int logN[MaxN];

void init()
{
	logN[0]=-1;

	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			dp[i][j][0]=num[i][j];

		logN[i]=((i&(i-1))==0) ? logN[i-1]+1 : logN[i-1];
	}

	for(int j=1;j<=logN[n];++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			for(int k=1;k<=m;++k)
				dp[i][k][j]=max(dp[i][k][j-1],dp[i+(1<<(j-1))][k][j-1]);
}

int query(int x,int y,int j)
{
	if(x>y)
		return 0;

	int k=logN[y-x+1];

	return max(dp[x][j][k],dp[y-(1<<k)+1][j][k]);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d",&n,&m,&k);

	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&num[i][j]);

	int ans=0;
	int ansnum[7]={0};
	int p=1;
	int rest=k;
	int have[7];
	int sum=0;

	init();

	memset(have,0,sizeof(have));

	for(int i=1;i<=n+1;++i)
	{
		if(i-p>ans)
		{
			ans=i-p;
			for(int j=1;j<=m;++j)
				ansnum[j]=have[j];
		}

		if(i==n+1)
			break;

		sum=0;
		for(int j=1;j<=m;++j)
			sum+=num[i][j];

		if(sum>k)
		{
			memset(have,0,sizeof(have));
			p=i+1;
			rest=k;

			continue;
		}

		for(int j=1;j<=m;++j)
		{
			if(have[j]<num[i][j])
			{
				rest-=num[i][j]-have[j];
				have[j]=num[i][j];
			}
		}

		if(rest>=0)
			continue;

		while(rest<0)
		{
			for(int j=1;j<=m;++j)
			{
				sum=query(p+1,i,j);

				if(num[p][j]>sum)
				{
					rest+=num[p][j]-sum;
					have[j]=sum;
				}
			}

			++p;
		}
	}

	for(int i=1;i<m;++i)
		printf("%d ",ansnum[i]);
	printf("%d\n",ansnum[m]);
	
	return 0;
}
