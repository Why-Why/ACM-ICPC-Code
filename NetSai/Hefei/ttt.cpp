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
// Created Time  : 2015年09月27日 星期日 15时56分00秒
// File Name     : ttt.cpp

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
const int INF=1000000009;

int N,L;
int num[MaxN],tnum[MaxN];
int dp[MaxN],f[MaxN];

int LIS(int dp[],int num[],int N)
{
	int ret=-1;
	for(int i=1;i<=N;++i) f[i]=INF;
	for(int i=1;i<=N;++i)
	{
		int x=lower_bound(f+1,f+N+1,num[i])-f;
		f[x]=num[i];
		dp[i]=x;
		ret=max(ret,dp[i]);
	}

	return ret;
}

int chuli(int l1,int r1,int l2,int r2)
{
	int cou=0;
	for(int i=l1;i<=r1;++i) tnum[++cou]=num[i];
	for(int i=l2;i<=r2;++i) tnum[++cou]=num[i];

	return LIS(dp,tnum,cou);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out1.txt","w",stdout);

	int T,cas=1;
	int ans;

	cin>>T;
	while(T--)
	{
		cin>>N>>L;
		for(int i=1;i<=N;++i)
			cin>>num[i];
		ans=-1;
		for(int i=N-L+1;i>=1;--i)
		{
			ans=max(ans,chuli(1,i-1,i+L,N));
		}

		printf("Case #%d: %d\n",cas++,ans);
	}
	
	return 0;
}
