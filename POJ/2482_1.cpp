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
// Created Time  : 2015年07月16日 星期四 16时33分23秒
// File Name     : 2482_1.cpp

// 注意：建的不是完全二叉树，所以空间要开大，然后就是注意ｌｃ和ｒｃ的越界问题（不知如何判，所以直接初始化为０）。

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

const int MaxN=80004;

#define lc (po<<1)
#define rc ((po<<1)|1)

struct DE
{
	int a,b,c;

	bool operator < (const DE &b) const
	{
		return c<b.c;
	}
}de[MaxN];

int decou=0;

struct BIT
{
	int N;
	long long key[MaxN],val[MaxN];
	long long *numP;

	long long SUM[MaxN],MAXN[MaxN];

	void _build(int L,int R,int po)
	{
		if(L>R)
			return;

		de[decou].a=L;
		de[decou].b=R;
		de[decou].c=po;
		++decou;
		
		int M=(L+R+1)>>1;

		_build(L,M-1,lc);

		key[po]=numP[M];
		val[po]=0;
		SUM[po]=MAXN[po]=0;
		
		_build(M+1,R,rc);
	}

	void build(long long *num,int cou)
	{
		N=cou;
		numP=num;
		memset(SUM,0,sizeof(SUM));
		memset(MAXN,0,sizeof(MAXN));
		_build(1,N,1);
	}

	void pushUP(int po)
	{
/*		long long Lnum,Rnum,Rmaxn,Lmaxn;

		if(lc>N)
			Lnum=Lmaxn=0;
		else
		{
			Lnum=SUM[lc];
			Lmaxn=MAXN[lc];
		}

		if(rc>N)
			Rnum=Rmaxn=0;
		else
		{
			Rnum=SUM[rc];
			Rmaxn=MAXN[rc];
		}

		SUM[po]=Lnum+Rnum+val[po];
		MAXN[po]=max(Lmaxn,max(Lnum+val[po]+Rmaxn,Lnum+val[po]));*/

		SUM[po]=SUM[lc]+SUM[rc]+val[po];
		MAXN[po]=max(MAXN[lc],SUM[lc]+val[po]+max(0LL,MAXN[rc]));
	}

	void _add(int po,long long k,long long num)
	{
	//	if(po>N)
	//		return;

		if(k==key[po])
			val[po]+=num;
		else if(k<key[po])
			_add(lc,k,num);
		else
			_add(rc,k,num);

		pushUP(po);
	}

	void add(long long k,long long num)
	{
		_add(1,k,num);
	}

	long long query()
	{
		return MAXN[1];
	}

	void display()
	{
		for(int i=1;i<=N;++i)
			cout<<key[i]<<' '<<val[i]<<' '<<SUM[i]<<' '<<MAXN[i]<<endl;
		cout<<endl;
	}
};

BIT tree;

struct Point
{
	long long x,y,val;

	bool operator < (const Point &b) const
	{
		if(x==b.x)
			return y<b.y;

		return x<b.x;
	}
};

Point P[MaxN];
int N;
long long W,H;
int cou;
long long num[MaxN];
long long ans;

long long getans()
{
	if(W==0 || H==0)
		return 0;

	int Lp,Rp;

	Lp=Rp=1;

	for(int i=1;i<=N;++i)
	{
		while(Lp<=N && P[Lp].x<P[i].x)
		{
			tree.add(P[Lp].y,-P[Lp].val);
			tree.add(P[Lp].y+H,P[Lp].val);
			++Lp;
		}

		while(Rp<=N && P[Rp].x<P[i].x+W)
		{
			tree.add(P[Rp].y,P[Rp].val);
			tree.add(P[Rp].y+H,-P[Rp].val);
			++Rp;
		}

		ans=max(ans,tree.query());
	}

	return ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %lld %lld",&N,&W,&H))
	{
		ans=0;
		cou=0;

		for(int i=1;i<=N;++i)
		{
			scanf("%lld %lld %lld",&P[i].x,&P[i].y,&P[i].val);
			num[++cou]=P[i].y;
			num[++cou]=P[i].y+H;
		}

		sort(P+1,P+N+1);
		sort(num+1,num+cou+1);
		cou=unique(num+1,num+cou+1)-num-1;

		tree.build(num,cou);

		printf("%lld\n",getans());
	}
	
	return 0;
}
