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
// Created Time  : 2015年11月09日 星期一 22时45分41秒
// File Name     : G.cpp

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
const int INF=0x3f3f3f3f;

struct Edge { int to,next; } E[MaxN<<1];
int head[MaxN],Ecou;

struct OPE
{
	bool t;
	int v,id,u;
	OPE(bool a=0,int b=0,int c=0,int d=0):t(a),v(b),id(c),u(d) {}
	bool operator < (const OPE & b) const { return id<b.id; }
};
vector <OPE> ope[MaxN];

int N,Q;
int w[MaxN],ans[MaxN];
bool vis[MaxN];

int sumnode,rsize[MaxN];
int dist[MaxN];

inline void init() { Ecou=0; for(int i=1;i<=N;++i) { ope[i].clear(); head[i]=-1; vis[i]=0; ans[i]=0; } }
inline void addEdge(int u,int v) { E[Ecou].to=v; E[Ecou].next=head[u]; head[u]=Ecou++; }
inline void addOPE(int u,bool t,int v,int id) { ope[u].push_back(OPE(t,v,id)); }

//////////////////////////

int cen,minnC;

int dfsC(int u,int pre)
{
	int ret=1,maxn=0,t;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
		{
			t=dfsC(E[i].to,u);
			maxn=max(maxn,t);
			ret+=t;
		}
	maxn=max(maxn,sumnode-ret);
	if(maxn<minnC) { minnC=maxn; cen=u; }
	
	return ret;
}

int getCen(int u)
{
	minnC=INF;
	dfsC(u,-1);
	return cen;
}

//////////////////////////

int num[MaxN],nlen;
int C[MaxN],NN;
OPE tope[MaxN];
int rem[MaxN];

bool cmp(int a,int b) { return dist[a]<dist[b]; }
inline int lowbit(int x) { return x&(-x); }
void add(int x,int d) { while (x<=NN) { C[x]+=d; x+=lowbit(x); } }
int sum(int x)
{
	int ret=0;
	while(x>0) { ret+=C[x]; x-=lowbit(x); }
	return ret;
}

int upper(int num[],int len,int v)
{
	int L=0,R=len,M;

	while(R>L)
	{
		M=(L+R)>>1;
		if(dist[num[M]]>v) R=M;
		else L=M+1;
	}
	return L;
}

void getnum(int L,int R,int t)
{
	int olen=0,tlen,temp;
	NN=R-L;
	sort(num+L,num+R,cmp);

	C[0]=0;
	for(int i=L;i<R;++i)
	{
		rem[i-L+1]=w[num[i]];
		C[i-L+1]=0;
		tlen=ope[num[i]].size();
		for(int j=0;j<tlen;++j) tope[olen++]=OPE(ope[num[i]][j].t,ope[num[i]][j].v,ope[num[i]][j].id,i-L+1);
	}
	sort(tope,tope+olen);
	for(int i=L;i<R;++i) add(i-L+1,w[num[i]]);

	for(int i=0;i<olen;++i)
		if(tope[i].t)
		{

			temp=upper(num+L,R-L,tope[i].v-dist[num[L-1+tope[i].u]]);
			if(temp) ans[tope[i].id]+=t*sum(temp);
		}
		else
		{
			add(tope[i].u,tope[i].v-rem[tope[i].u]);
			rem[tope[i].u]=tope[i].v;
		}
}

int dfscal(int u,int pre,int dis)
{
	int ret=1;
	num[nlen++]=u;
	dist[u]=dis;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			ret+=dfscal(E[i].to,u,dis+1);
	return ret;
}

void calc(int u)
{
	int pre=1;
	nlen=1; num[0]=u;
	dist[u]=0;
	for(int i=head[u],j=0;i!=-1;i=E[i].next)
		if(!vis[E[i].to])
		{
			rsize[j++]=dfscal(E[i].to,u,1);
			getnum(pre,nlen,-1);
			pre=nlen;
		}
	getnum(0,nlen,1);
}

void getans(int u)
{
	int c=getCen(u);
	vis[c]=1;
	calc(c);

	for(int i=head[c],j=0;i!=-1;i=E[i].next)
		if(!vis[E[i].to])
		{
			sumnode=rsize[j++];
			getans(E[i].to);
		}
}

//////////////////////////

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	char ts[5];

	while(~scanf("%d %d",&N,&Q))
	{
		init();
		for(int i=1;i<=N;++i) scanf("%d",w+i);

		for(int i=1;i<N;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		for(int i=1;i<=Q;++i)
		{
			scanf("%s %d %d",ts,&a,&b);
			addOPE(a,ts[0]=='?',b,i);
			if(ts[0]!='?') ans[i]=-1;
		}

		sumnode=N;
		getans(1);
		for(int i=1;i<=Q;++i) if(ans[i]>=0) printf("%d\n",ans[i]);
	}
	
	return 0;
}
