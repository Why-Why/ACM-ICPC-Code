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
// Created Time  : 2015年08月11日 星期二 13时24分12秒
// File Name     : 1011.cpp

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

const int MaxN=101005;
const int mod=1000000007;

struct Edge
{
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
int N;
long long dp[MaxN];
long long jie[MaxN];

bool zero;

void init1(int N)
{
	zero=0;
	Ecou=0;
	for(int i=1;i<=N;++i)
	{
		head[i]=-1;
		dp[i]=0;
	}
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int rem[MaxN];						// 递归调用的时候这个数组被修改了，所以！！！WTF。

int dfs(int u,int pre,bool can)
{
	int cou1=0,cou2=0;
	int zong=0;
	int t;
	long long fang=1;
	int temp=0;

	int son=0;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
			++son;

	for(int i=0;i<=10;++i)
		rem[i]=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
		{
			t=dfs(E[i].to,u,son==1);
			(fang*=dp[E[i].to])%=mod;
			if(t==1) ++cou1;
			else
			{
				rem[++cou2]=t;
				temp+=t;
				cout<<t<<"@\n";
			}

			zong+=t;
		}

	cout<<u<<' '<<zong<<' ';
	for(int i=0;i<=cou2;++i)
		cout<<rem[i]<<' ';
	cout<<"|\n";

	if(zong>=1 && can)
		(fang*=2)%=mod;

	if(cou2>2)
		fang=0;
	if(cou2==2)
	{
	//	if(temp!=rem[0]+rem[3]+rem[1]+rem[2]) { cout<<temp<<' '<<rem[1]<<' '<<rem[2]<<endl; exit(0);}
		(fang*=2*jie[zong-rem[1]-rem[2]])%=mod;
	}
	if(cou2==1)
	{
		(fang*=jie[zong-rem[1]])%=mod;
		if(zong-rem[1])
			(fang*=2)%=mod;
	}
	if(cou2==0)
		(fang*=jie[zong])%=mod;

//	cout<<u<<' '<<pre<<' '<<can<<' '<<zong<<' '<<cou1<<' '<<cou2<<' '<<fang<<endl;

	dp[u]=fang;

	if(fang==0) zero=1;

	return zong+1;
}

int getans()
{
	dfs(1,-1,1);
	if(zero)
		dp[1]=0;
	return (int)dp[1];
}

void init()
{
	jie[0]=1;
	for(int i=1;i<=100003;++i)
	{
		jie[i]=i*jie[i-1];
		jie[i]%=mod;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int a,b;

	scanf("%d",&T);

	init();

	while(T--)
	{
		scanf("%d",&N);
		init1(N);

		for(int i=1;i<N;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}
		
		printf("Case #%d: %d\n",cas++,getans());
	}
	
	return 0;
}
