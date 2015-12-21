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
// Created Time  : 2015年10月13日 星期二 17时27分11秒
// File Name     : F.cpp

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

const int MaxN=1700005;

struct Num
{
	int a,b;

	Num() {}

	Num(int x,int y):a(x),b(y)
	{}

	bool operator < (const Num & y) const
	{
		return a==y.a ? b<y.b : a<y.a;
	}

	bool operator > (const Num & y) const
	{
		return a==y.a ? b>y.b : a>y.a;
	}

	bool operator == (const Num & y) const
	{
		return a==y.a && b==y.b;
	}

	Num operator + (const Num & y) const
	{
		return Num(a+y.a,b+y.b);
	}
};

struct SBT
{
	int tot,root;
	int size[MaxN],ch[MaxN][2];

	Num key[MaxN];
	int base[MaxN];
	long long lu[MaxN];

	void init()
	{
		tot=1; root=0; size[0]=0;
		ch[0][0]=ch[0][1]=0;
	}
	void update(int x)
	{
		size[x]=size[ch[x][0]]+size[ch[x][1]]+(x!=0);
	}
	void rotate(int &x,int t)
	{
		int y=ch[x][t];
		ch[x][t]=ch[y][1-t];
		ch[y][1-t]=x;
		update(x); update(y);
		x=y;
	}
	void maintain(int &x,int t)
	{
		if(size[ch[ch[x][t]][t]]>size[ch[x][1-t]]) rotate(x,t);
		else if(size[ch[ch[x][t]][1-t]]>size[ch[x][1-t]])
		{
			rotate(ch[x][t],1-t); rotate(x,t);
		}
		else return;

		maintain(ch[x][0],0);
		maintain(ch[x][1],1);
		maintain(x,0);
		maintain(x,1);
	}
	bool _insert(int &x,Num k,int b,long long l)
	{
		if(!x)
		{
			x=tot++; key[x]=k; size[x]=1;
			base[x]=b;
			lu[x]=l;
			ch[x][0]=ch[x][1]=0;
			return 1;
		}
		else if(!(k==key[x]))
		{
			if(_insert(ch[x][k>key[x]],k,b,l))
			{
				++size[x];
				maintain(x,k>key[x]);
				return 1;
			}
			return 0;
		}
		else if(base[x]<b)
		{
			base[x]=b;
			lu[x]=l;
			return 0;
		}
		return 0;
	}
	bool find(Num k,int &b,long long &l)
	{
		int x=root;

		while(x)
		{
			if(key[x]==k)
			{
				b=base[x];
				l=lu[x];
				return 1;
			}
			x=ch[x][k>key[x]];
		}
		return 0;
	}
	void insert(Num k,int b,long long l)
	{
		_insert(root,k,b,l);
	}
}tree;

int N;
Num rem[30][3];
int rnum[30];

int bbb;
long long lll;

const int INF=0x3f3f3f3f;

void dfs1(int d,Num tn,int b,long long l)
{
	if(d>((N+1)>>1))
	{
		tree.insert(tn,b,l);
		return;
	}

	for(int i=0;i<3;++i)
		dfs1(d+1,tn+rem[d][i],b+(i ? rnum[d] : 0),(l<<2)|i);
}

void dfs2(int d,Num tn,int b,long long l)
{
	if(d>N)
	{
		Num ttt;
		ttt.a=-tn.a;
		ttt.b=-tn.b;

		int tb;
		long long tl;

		if(tree.find(ttt,tb,tl))
			if(bbb<tb+b)
			{
				bbb=tb+b;
				lll=(tl<<(2*(N/2)))|l;
			}
		return;
	}

	for(int i=0;i<3;++i)
		dfs2(d+1,tn+rem[d][i],b+(i ? rnum[d] : 0),(l<<2)|i);
}

int rrr[30];

void show()
{
	for(int i=0;i<N;++i)
	{
		rrr[i]=lll & 3;
		lll>>=2;
	}

	for(int i=N-1;i>=0;--i)
		if(rrr[i]==0) puts("MW");
		else if(rrr[i]==1) puts("LW");
		else puts("LM");
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;

	scanf("%d",&N);
	for(int i=1;i<=N;++i)
	{
		scanf("%d %d %d",&a,&b,&c);
		rnum[i]=a;
		rem[i][0]=Num(b,c);
		rem[i][1]=Num(-a,c-a);
		rem[i][2]=Num(b-a,-a);
	}

	bbb=-INF;
	tree.init();
	dfs1(1,Num(0,0),0,0);
	dfs2((N+1)/2+1,Num(0,0),0,0);

	if(bbb==-INF) puts("Impossible");
	else show();
	
	return 0;
}
