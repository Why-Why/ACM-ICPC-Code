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
// Created Time  : 2015年07月04日 星期六 23时02分04秒
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

#pragma comment(linker, "/STACK:1024000000,1024000000")

struct state
{
	int num,cou;

	bool operator < (const state &b) const
	{
		return cou>b.cou;
	}
};

bool vis[1010];
int prime[200],pcou=0;
int rem[200][600],rcou[200];

state sta[1010];
int rank[1010];

void init()
{
	for(int i=1;i<=1000;++i)
		sta[i].num=i;

	for(int i=2;i<=1000;++i)
		if(!vis[i])
		{
			prime[pcou++]=i;
			rem[pcou-1][rcou[pcou-1]++]=i;
			++sta[i].cou;

			for(int j=i+i;j<=1000;j+=i)
			{
				vis[j]=1;
				rem[pcou-1][rcou[pcou-1]++]=j;
				++sta[j].cou;
			}
		}
}

int N,K;

const int INF=0x3f3f3f3f;
const int MaxN=1005;
const int MaxM=200;
const int MaxNode=MaxN*MaxN;

struct DLX
{
	int U[MaxNode],D[MaxNode],L[MaxNode],R[MaxNode],col[MaxNode],row[MaxNode];
	int H[MaxN],S[MaxM];
	int size,n,m;
	int ans;

	void init(int _n,int _m)
	{
		n=_n;
		m=_m;
		size=m;
		ans=INF;

		for(int i=0;i<=m;++i)
		{
			L[i]=i-1;
			R[i]=i+1;
			U[i]=D[i]=i;
			S[i]=0;
		}

		L[0]=m;
		R[m]=0;

		for(int i=1;i<=n;++i)
			H[i]=-1;
	}

	void Link(int r,int c)
	{
		col[++size]=c;
		row[size]=r;
		++S[c];
		U[size]=U[c];
		D[size]=c;
		D[U[c]]=size;
		U[c]=size;

		if(H[r]==-1)
			H[r]=L[size]=R[size]=size;
		else
		{
			L[size]=L[H[r]];
			R[size]=H[r];
			R[L[H[r]]]=size;
			L[H[r]]=size;
		}
	}

	void remove(int c)
	{
		L[R[c]]=L[c];
		R[L[c]]=R[c];

		for(int i=D[c];i!=c;i=D[i])
			for(int j=R[i];j!=i;j=R[j])
			{
				U[D[j]]=U[j];
				D[U[j]]=D[j];
				--S[col[j]];
			}
	}

	void resume(int c)
	{
		for(int i=U[c];i!=c;i=U[i])
			for(int j=L[i];j!=i;j=L[j])
			{
				U[D[j]]=D[U[j]]=j;
				++S[col[j]];
			}

		L[R[c]]=R[L[c]]=c;
	}

	void Dance(int d)
	{
		if(R[0]==0)
		{
			if(ans>d)
			{
				ans=d;
				cerr<<ans<<endl;
			}

			return;
		}

		int c=R[0];

		for(int i=R[0];i;i=R[i])
			if(S[i]<S[c])
				c=i;

		remove(c);

		for(int i=D[c];i!=c;i=D[i])
		{
			if(row[i]==K)
				continue;

			for(int j=R[i];j!=i;j=R[j])
				remove(col[j]);

			Dance(d+1);

			for(int j=L[i];j!=i;j=L[j])
				resume(col[j]);
		}

		resume(c);
	}
};

DLX dlx;

int getans()
{
	int m=0;

	for(m=0;m<pcou;++m)
		if(prime[m]>N)
			break;

	dlx.init(N,m);

	for(int i=0;i<m;++i)
		for(int j=0;j<rcou[i] && rem[i][j]<=N;++j)
			dlx.Link(rank[rem[i][j]],i+1);

	dlx.Dance(0);

	return dlx.ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	int T,cas=1;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&K);

//		for(int i=1;i<=N;++i)
//			cout<<sta[i].cou<<' ';
//		cout<<endl;
	
		sort(sta+1,sta+N+1);

//		for(int i=1;i<=N;++i)
//			cout<<sta[i].num<<' ';
//		cout<<endl;
	
		for(int i=1;i<=N;++i)
			rank[i]=sta[i].num;

//		for(int i=1;i<=N;++i)
//			cout<<rank[i]<<' ';
//		cout<<endl;
	
		printf("Case #%d: %d\n",cas++,getans()+(K!=1));
	}
	
	return 0;
}
