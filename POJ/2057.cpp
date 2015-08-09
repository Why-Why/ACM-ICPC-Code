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
// Created Time  : 2015年08月03日 星期一 12时32分58秒
// File Name     : 2057.cpp

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

const int MaxN=1010;
const long long INF=100000000000000000LL;

int soncou[MaxN];
int son[MaxN][10];
int N;
bool worm[MaxN];
int couN;
int pai[50000][10];
int paicou[10];
int cou;

long long buzai[MaxN];
int size[MaxN];
long long dp[MaxN];

void getbuzai(int u)
{
	buzai[u]=0;
	if(soncou[u]==0)
		size[u]=1;
	else
		size[u]=0;
	
	for(int i=1;i<=soncou[u];++i)
	{
		getbuzai(son[u][i]);
		size[u]+=size[son[u][i]];
		buzai[u]+=2+buzai[son[u][i]];
	}

	if(worm[u])
		buzai[u]=0;
}

inline long long getmin(int u,int pai[])
{
	long long ret=0;
	long long len=0;

	for(int i=1;i<=soncou[u];++i)
	{
		ret+=size[son[u][pai[i]]]*(len+1)+dp[son[u][pai[i]]];
		len+=buzai[son[u][pai[i]]]+2;
	}

	return ret;
}

struct state
{
	double val;
	int id;

	bool operator <(const state &b) const
	{
		return val>b.val;
	}
};

state sta[100];

void getpai(int u,int pai[])
{
	for(int i=1;i<=soncou[u];++i)
	{
		sta[i].val=(double)size[son[u][i]]/(buzai[son[u][i]]+2.0);
		sta[i].id=i;
	}

	sort(sta+1,sta+soncou[u]+1);
	for(int i=1;i<=soncou[u];++i)
		pai[i]=sta[i].id;
}

void getdp(int u)
{
	long long minn=INF;

	dp[u]=0;
	for(int i=1;i<=soncou[u];++i)
		getdp(son[u][i]);

	int pai[10];
	getpai(u,pai);
	minn=min(minn,getmin(u,pai));
	dp[u]=minn>=INF ? 0 : minn;
}

inline bool judge(int a,int d,int num[])
{
	for(int i=1;i<=d;++i)
		if(num[i]==a)
			return 0;

	return 1;
}

void pailie(int d,int N,int num[])
{
	if(d>N)
	{
		for(int i=1;i<=N;++i)
			pai[cou][i]=num[i];
		++cou;
		return;
	}

	for(int i=1;i<=N;++i)
		if(judge(i,d-1,num))
		{
			num[d]=i;
			pailie(d+1,N,num);
		}
}

void init()
{
	int t;
	int tnum[10];
	cou=0;
	paicou[0]=0;
	paicou[1]=1;

	for(int i=2;i<=8;++i)
		paicou[i]=paicou[i-1]*i;

	for(int i=1;i<=8;++i)
	{
		paicou[i]+=paicou[i-1];
		pailie(1,i,tnum);
	}
}

long long getans()
{
	getbuzai(1);
	getdp(1);
	return dp[1];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a;
	char ts[5];
	
//	init();

	while(~scanf("%d",&N) && N)
	{
		memset(soncou,0,sizeof(soncou));
		memset(worm,0,sizeof(worm));
		couN=N;
		scanf("%d %s",&a,ts);
		worm[1]=ts[0]=='Y';

		for(int i=2;i<=N;++i)
		{
			scanf("%d %s",&a,ts);
			worm[i]=ts[0]=='Y';
			son[a][++soncou[a]]=i;
			if(soncou[a]==1)
				--couN;
		}

		printf("%.4f\n",getans()/(double)couN);
	}
	
	return 0;
}
