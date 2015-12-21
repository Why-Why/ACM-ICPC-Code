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
// Created Time  : 2015年11月14日 星期六 13时42分29秒
// File Name     : 1005.cpp

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

const int step[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int map1[13][13];
int N,M;
bool have[13];

bool bian[13][13];
int cou[13],fu[13][201];

void fugai(int k,bool dvis[][13])
{
	int x,y;

	for(int i=0;i<cou[k];++i)
	{
		x=fu[k][i]/100;
		y=fu[k][i]-x*100;
		dvis[x][y]=1;
	}
}

///////////////////////

const int MaxU=111;
const int MaxV=111;
const int MaxM=MaxU*MaxV;
const int INF=10e8;

struct Edge
{
	int to,next;
};

Edge E[MaxM];
int head[MaxU],Ecou=0;
bool vis[MaxV];
int linker[MaxV];

bool find(int u)
{
	int v;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(!vis[v])
		{
			vis[v]=1;

			if(linker[v]==-1 || find(linker[v]))
			{
				linker[v]=u;

				return 1;
			}
		}
	}

	return 0;
}

int Hungary(int uN)
{
	int ret=0;

	for(int i=1;i<=uN;++i)
	{
		memset(vis,0,sizeof(vis));

		if(find(i))
			++ret;
	}

	return ret;
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou;
	++Ecou;
}

void initer(int uN,int vN)
{
	Ecou=0;

	for(int i=1;i<=uN;++i)
		head[i]=-1;

	for(int i=1;i<=vN;++i)
		linker[i]=-1;
}

////////////////////////////

int dian1[111],dian2[111];

int getans(int sta)
{
	int ret=0;
	bool dvis[13][13]={0};

	bool use[13]={0};
	for(int i=0;i<10;++i)
		if(sta & (1<<i))
			if(have[i]) use[i]=1,fugai(i,dvis),++ret;
			else return 0;

	for(int i=0;i<10;++i)
		for(int j=0;j<10;++j)
			if(i!=j && use[i] && use[j] && bian[i][j])
				return 0;

	int cou1=0,cou2=0;
	int ji[13][13]={};
	int x,y,tx,ty;

	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			if(map1[i][j]==-1 && dvis[i][j]==0)
				if((i+j)&1) dian1[++cou1]=i*100+j,ji[i][j]=cou1;
				else dian2[++cou2]=i*100+j,ji[i][j]=cou2;

	initer(cou1,cou2);
	for(int i=1;i<=cou1;++i)
	{
		x=dian1[i]/100;
		y=dian1[i]-x*100;

		for(int k=0;k<4;++k)
		{
			tx=x+step[k][0];
			ty=y+step[k][1];

			if(tx>0 && ty>0 && tx<=N && ty<=M && map1[tx][ty]==-1 && dvis[tx][ty]==0)
				addEdge(i,ji[tx][ty]);
		}
	}

	return ret+cou1+cou2-Hungary(cou1);
}

void init()
{
	int ti,tj;
	memset(cou,0,sizeof(cou));

	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			if(map1[i][j]!=-1)
				for(int k=0;k<4;++k)
				{
					ti=i+step[k][0];
					tj=j+step[k][1];
					if(ti>0 && tj>0 && ti<=N && tj<=M && map1[ti][tj]!=-1)
						bian[map1[i][j]][map1[ti][tj]]=bian[map1[ti][tj]][map1[i][j]]=1;
				}
			else
				for(int k=0;k<4;++k)
				{
					ti=i+step[k][0];
					tj=j+step[k][1];
					if(ti>0 && tj>0 && ti<=N && tj<=M && map1[ti][tj]!=-1)
						fu[map1[ti][tj]][cou[map1[ti][tj]]++]=i*100+j;
				}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	char s[20];
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);
		memset(have,0,sizeof(have));
		memset(bian,0,sizeof(bian));
		for(int i=1;i<=N;++i)
		{
			scanf("%s",s+1);
			for(int j=1;j<=M;++j)
				if(s[j]=='.') map1[i][j]=-1;
				else map1[i][j]=s[j]-'0',have[s[j]-'0']=1;
		}
		init();

		int ans=0;
		for(int i=0;i<1024;++i)
			ans=max(ans,getans(i));

		printf("Case #%d: %d\n",cas++,ans);
	}
	
	return 0;
}
