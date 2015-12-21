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
// Created Time  : 2015年11月05日 星期四 22时52分12秒
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

#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

const int MaxN=50011;

struct Edge
{
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
bool vis[MaxN];

void init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int K;
long long prime[33];

struct State
{
	unsigned long long num;

	State(unsigned long long x=0) { num=x; }

	void operator = (long long x)
	{
		num=0;
		long long cou;

		if(x==0)
		{
			num|=(1ULL<<62);
			return;
		}

		for(int i=0;i<K;++i)
		{
			for(cou=0;x%prime[i]==0;++cou,x/=prime[i]);
			cou%=3;
			num|=(cou<<(i*2));
		}
	}

	State operator * (const State & b)
	{
		State ret;
		long long t;
		unsigned long long x=num,y=b.num;

		for(int i=0;i<K;++i,x>>=2,y>>=2)
		{
			t=(x & 3)+(y & 3);
			if(t>=3) t-=3;
			ret.num|=(t<<(i*2));
		}
		return ret;
	}

	State bu (const State & b)
	{
		State ret;
		long long t;
		unsigned long long x=num,y=b.num;

		for(int i=0;i<K;++i,x>>=2,y>>=2)
		{
			t=(x & 3)+(y & 3);
			if(t>=3) t-=3;
			t=3-t;
			if(t>=3) t-=3;
			ret.num|=(t<<(i*2));
		}
		return ret;
	}

	void show()
	{
		unsigned long long x=num;

		for(int i=0;i<K;++i,x>>=2)
			cout<<(x&3)<<' ';
		cout<<endl;
	}

}num[MaxN];

int N;
long long ans;

////////////////////////

int sumnode;
int rsize[MaxN];

int minn,cen;

int dfsC(int u,int pre)
{
	int maxn=0,t,sum=1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
		{
			t=dfsC(E[i].to,u);
			maxn=max(maxn,t);
			sum+=t;
		}
	maxn=max(maxn,sumnode-sum);
	if(maxn<minn) { minn=maxn; cen=u; }
	
	return sum;
}

int getCenter(int u)
{
	minn=0x3f3f3f3f;
	dfsC(u,-1);
	return cen;
}

State tnum[MaxN];
int len;

int dfs(int u,int pre,State sta,bool ok)
{
	int sum=1;
	sta=sta*num[u];

	if(ok && (num[u].num & (1ULL<<62))) ok=0;
	if(ok) tnum[len++]=sta;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			sum+=dfs(E[i].to,u,sta,ok);
	return sum;
}

multiset <unsigned long long> staset;

inline void add(State sta)
{
	staset.insert(sta.num);
}

inline int find(const State & sta)
{
	return staset.count(sta.num);
}

void getnum(int u)
{
	State temp;
	for(int i=0;i<len;++i)
	{
		temp=tnum[i].bu(num[u]);
		ans+=find(temp);
	}
	for(int i=0;i<len;++i) add(tnum[i]);
}

void calc(int u)
{
	staset.clear();
	add(State(0));

	if((num[u].num & (1ULL<<62))==0 && num[u].num==0) ++ans;

	for(int i=head[u],j=0;i!=-1;i=E[i].next)
		if(!vis[E[i].to])
		{
			len=0;
			rsize[j++]=dfs(E[i].to,-1,State(0),(num[u].num & (1ULL<<62))==0);
			getnum(u);
		}
}

void getans(int u)
{
	int c=getCenter(u);
	vis[c]=1;
	calc(c);

	for(int i=head[c],j=0;i!=-1;i=E[i].next)
		if(!vis[E[i].to])
		{
			sumnode=rsize[j++];
			getans(E[i].to);
		}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long x;
	int a,b;

	while(~scanf("%d",&N))
	{
		init();
		scanf("%d",&K);
		for(int i=0;i<K;++i) scanf("%I64d",prime+i);
		for(int i=1;i<=N;++i)
		{
			scanf("%I64d",&x);
			num[i]=x;
		}
		for(int i=1;i<N;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		sumnode=N;
		ans=0;
		getans(1);

		printf("%I64d\n",ans);
	}
	
	return 0;
}
