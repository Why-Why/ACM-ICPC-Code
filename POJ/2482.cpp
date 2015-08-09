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
// Created Time  : 2015年07月16日 星期四 15时08分43秒
// File Name     : 2482.cpp

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

const int MaxN=40004;

long long rem[MaxN],val[MaxN];
long long num[MaxN];
int cou;
long long SUM[MaxN],MAXN[MaxN];

void build(int L,int R,int po)
{
	if(L>R)
		return;

	int M=(L+R+1)>>1;

	build(L,M-1,po<<1);
	rem[po]=num[M];
	val[po]=0;
	SUM[po]=MAXN[po]=0;
	build(M+1,R,(po<<1)|1);
}

void pushUP(int po)
{
	SUM[po]=SUM[po<<1]+SUM[(po<<1)|1]+val[po];
	MAXN[po]=max(MAXN[po<<1],max(SUM[po]-SUM[(po<<1)|1],SUM[po]-SUM[(po<<1)|1]+MAXN[(po<<1)|1]));
}

void add(long long p,long long num,int po)
{
	if(rem[po]==p)
		val[po]+=num;
	else if(rem[po]>p)
		add(p,num,po<<1);
	else
		add(p,num,(po<<1)|1);

	pushUP(po);
}

long long getans()
{
	return MAXN[1];
}

struct Point
{
	long long x,y,num;

	bool operator < (const Point &b) const
	{
		if(x==b.x)
			return y<b.y;

		return x<b.x;
	}
};

Point P[MaxN];

void solve(long long p,long long num)
{
	add(p,num,1);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,W,H;
	long long a,b,c;
	int Lp,Rp;
	long long ans;

	while(~scanf("%d %d %d",&N,&W,&H))
	{
		Lp=Rp=1;
		cou=0;
		ans=0;

		for(int i=1;i<=N;++i)
		{
			scanf("%lld %lld %lld",&a,&b,&c);
			P[i].x=a;
			P[i].y=b;
			num[++cou]=b;
			num[++cou]=b+H;
			P[i].num=c;
		}

		sort(num+1,num+cou+1);

		int k=1,p=1;

		while(++p <= cou)
		{
			if(num[p]!=num[k])
				num[++k]=num[p];
		}

		cou=k;

		build(1,cou,1);

		sort(P+1,P+N+1);

		for(int i=1;i<=N;++i)
		{
			while(P[Lp].x<P[i].x)
			{
				solve(P[Lp].y,-P[Lp].num);
				solve(P[Lp].y+H,P[Lp].num);
				++Lp;
			}

			while(Rp<=N && P[Rp].x<P[i].x+W)
			{
				solve(P[Rp].y,P[Rp].num);
				solve(P[Rp].y+H,-P[Rp].num);
				++Rp;
			}

			ans=max(ans,getans());
		}

		printf("%lld\n",ans);
	}
	
	return 0;
}
