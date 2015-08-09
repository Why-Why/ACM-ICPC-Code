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
// Created Time  : 2015年07月26日 星期日 11时02分03秒
// File Name     : 2112.cpp

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

const int MaxN=50010+10010;
const int MaxNode=2600010;

int Tcou;											// 节点个数。
int Troot[MaxN],NT[MaxN];							// 每颗原线段树根的位置，新线段树的根。
int lson[MaxNode],rson[MaxNode],BIT[MaxNode];		// 左右子树的位置，节点维护的值。

int Hnum[MaxN],Hcou;								// Hash相关。
int use[MaxN];										// 询问是正在用的线段树的节点的值。
int N;

void Hash_init()
{
	sort(Hnum+1,Hnum+Hcou+1);
	Hcou=unique(Hnum+1,Hnum+Hcou+1)-Hnum-1;
}

int hash(int x)
{
	return lower_bound(Hnum+1,Hnum+Hcou+1,x)-Hnum;
}

void init()
{
	Tcou=Hcou=0;
}

int build(int L,int R)
{
	int root=Tcou++;

	BIT[root]=0;

	if(L!=R)
	{
		int M=(L+R)>>1;

		lson[root]=build(L,M);
		rson[root]=build(M+1,R);
	}

	return root;
}

int insert(int old,int val,int d)
{
	int root=Tcou++,ret=root;
	int L=1,R=Hcou,M;

	BIT[root]=BIT[old]+d;

	while(R>L)
	{
		M=(L+R)>>1;

		if(val<=M)
		{
			lson[root]=Tcou++;
			rson[root]=rson[old];
			root=lson[root];
			old=lson[old];
			R=M;
		}
		else
		{
			lson[root]=lson[old];
			rson[root]=Tcou++;
			root=rson[root];
			old=rson[old];
			L=M+1;
		}

		BIT[root]=BIT[old]+d;
	}

	return ret;
}

inline int lowbit(int x)
{
	return x&(-x);
}

int sum(int x)
{
	int ret=0;

	for(;x;x-=lowbit(x))
		ret+=BIT[lson[use[x]]];

	return ret;
}

int query(int ql,int qr,int qt)
{
	int L=1,R=Hcou,M;
	int temp;
	int baseTL=Troot[ql-1],baseTR=Troot[qr];

	for(int i=ql-1;i;i-=lowbit(i))
		use[i]=NT[i];
	for(int i=qr;i;i-=lowbit(i))
		use[i]=NT[i];

	while(R>L)
	{
		M=(L+R)>>1;
		temp=sum(qr)-sum(ql-1)+BIT[lson[baseTR]]-BIT[lson[baseTL]];

		if(qt<=temp)
		{
			for(int i=ql-1;i;i-=lowbit(i))
				use[i]=lson[use[i]];
			for(int i=qr;i;i-=lowbit(i))
				use[i]=lson[use[i]];
			baseTR=lson[baseTR];
			baseTL=lson[baseTL];
			R=M;
		}
		else
		{
			qt-=temp;

			for(int i=ql-1;i;i-=lowbit(i))
				use[i]=rson[use[i]];
			for(int i=qr;i;i-=lowbit(i))
				use[i]=rson[use[i]];
			baseTR=rson[baseTR];
			baseTL=rson[baseTL];
			L=M+1;
		}
	}

	return L;
}

void add(int x,int val,int d)
{
	while(x<=N)
	{
		NT[x]=insert(NT[x],val,d);
		x+=lowbit(x);
	}
}

void CT_init(int num[])
{
	Troot[0]=build(1,Hcou);

	for(int i=1;i<=N;++i)				// ???
	{
		Troot[i]=insert(Troot[i-1],hash(num[i]),1);
		NT[i]=Troot[0];
	}
}

struct Query
{
	bool type;
	int a,b,c;
};

Query q[10004];
int num[50010];					// 序列的值。

void update(int up,int ut)
{
	add(up,hash(num[up]),-1);
	add(up,hash(ut),1);
	num[up]=ut;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T;
	char ts[10];
	int M;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);
		init();

		for(int i=1;i<=N;++i)
		{
			scanf("%d",&num[i]);
			Hnum[++Hcou]=num[i];
		}

		for(int i=1;i<=M;++i)
		{
			scanf("%s",ts);

			if(ts[0]=='Q')
			{
				q[i].type=0;
				scanf("%d %d %d",&q[i].a,&q[i].b,&q[i].c);
			}
			else
			{
				q[i].type=1;
				scanf("%d %d",&q[i].a,&q[i].b);
				Hnum[++Hcou]=q[i].b;
			}
		}

		Hash_init();
		CT_init(num);

		for(int i=1;i<=M;++i)
		{
			if(q[i].type)
				update(q[i].a,q[i].b);
			else
				printf("%d\n",Hnum[query(q[i].a,q[i].b,q[i].c)]);
		}
	}
	
	return 0;
}
