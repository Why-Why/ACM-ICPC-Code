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
// Created Time  : 2015年11月04日 星期三 21时38分20秒
// File Name     : C.cpp

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

#pragma comment(linker,"/STACK:102400000,102400000") 

using namespace std;

const int MaxN=100005;
const int mod=1000000+3;

struct Edge
{
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;

long long v[MaxN];
bool vis[MaxN];
int sumnode;

int rsize[MaxN];
int cen,minncen;

int N,K;
int rem1,rem2;

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int dfsCen(int u,int pre)
{
	int ret=1,maxn=0,t;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
		{
			t=dfsCen(E[i].to,u);
			maxn=max(maxn,t);
			ret+=t;
		}
	maxn=max(maxn,sumnode-ret);
	if(maxn<minncen) { minncen=maxn; cen=u; }

	return ret;
}

int getCenter(int u)
{
	minncen=0x3f3f3f3f;
	dfsCen(u,-1);
	return cen;
}

int nvis[1000006],flag=1;
int trem[1000006];
int num[MaxN],nid[MaxN],len;

long long INV[1000006];

long long inv(long long a,long long m)
{
	if(INV[a]) return INV[a];
	if(a==1) return 1;
	INV[a]=inv(m%a,m)*(m-m/a)%m;
	return INV[a];
}

int dfsCal(int u,int pre,long long k)
{
	(k*=v[u])%=mod;
	num[len]=k;
	nid[len++]=u;

	int ret=1;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			ret+=dfsCal(E[i].to,u,k);
	return ret;
}

void update(int a,int b)
{
	if(a>b) swap(a,b);
	if(rem1==-1 || a<rem1 || (a==rem1 && b<rem2))
	{
		rem1=a;
		rem2=b;
	}
}

void calc(int u)
{
	long long t,temp;
	int a,b;
	++flag;
	nvis[1]=flag;
	trem[1]=u;

	for(int i=head[u],j=0;i!=-1;i=E[i].next)
		if(!vis[E[i].to])
		{
			len=0;
			rsize[j++]=dfsCal(E[i].to,u,1);

			for(int k=0;k<len;++k)
			{
				t=inv((num[k]*v[u])%mod,mod);
				if(nvis[temp=(t*K)%mod]==flag)
					update(nid[k],trem[temp]);
			}
			for(int k=0;k<len;++k)
			{
				if(nvis[num[k]]!=flag)
				{
					nvis[num[k]]=flag;
					trem[num[k]]=nid[k];
				}
				else trem[num[k]]=min(trem[num[k]],nid[k]);
			}
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

	int a,b;
	while(~scanf("%d %d",&N,&K))
	{
		Ecou=0;
		for(int i=1;i<=N;++i) scanf("%I64d",v+i),head[i]=-1,vis[i]=0;
		//for(int i=1;i<=N;++i) scanf("%lld",v+i);
		for(int i=1;i<N;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		rem1=-1;
		sumnode=N;
		getans(1);

		if(-1==rem1) puts("No solution");
		else printf("%d %d\n",rem1,rem2);
	}
	
	return 0;
}
