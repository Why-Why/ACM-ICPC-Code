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
// Created Time  : 2015年08月13日 星期四 15时56分06秒
// File Name     : 1007.cpp

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

const int MaxN=110;

int N,M;
int col1[MaxN][MaxN];
int col2[MaxN][MaxN];
int hang[MaxN][MaxN],lie[MaxN][MaxN];

int ans[510];
int anscou;

int H,L;
int Hnum[MaxN],Lnum[MaxN];

int tH,tL;
int Htemp[MaxN],Ltemp[MaxN];

int ocouL[MaxN],ocouH[MaxN];

bool vis[510];

int gethang(int h,int Lcou,int num[])
{
	int ret=-2;

	for(int i=1;i<=Lcou;++i)
		if(ret==-2)
			ret=col2[h][num[i]];
		else if(ret!=col2[h][num[i]])
			return -1;

	if(ret==-2) ret=-1;

	return ret;
}

int getlie(int l,int Hcou,int num[])
{
	int ret=-2;

	for(int i=1;i<=Hcou;++i)
		if(ret==-2)
			ret=col2[num[i]][l];
		else if(ret!=col2[num[i]][l])
			return -1;

	if(ret==-2) ret=-1;

	return ret;
}

void getans()
{
	int t;

	if(H==0 || L==0)
		return;

	tH=tL=0;

	for(int i=1;i<=H;++i)
	{
		if(ocouH[Hnum[i]]==0) continue;

		t=gethang(Hnum[i],L,Lnum);
		if(t==-1 || hang[Hnum[i]][t]==0) Htemp[++tH]=Hnum[i];
		else ans[anscou++]=hang[Hnum[i]][t],vis[hang[Hnum[i]][t]]=1;
	}

	for(int i=1;i<=L;++i)
	{
		if(ocouL[Lnum[i]]==0) continue;

		t=getlie(Lnum[i],tH,Htemp);
		if(t==-1 || lie[Lnum[i]][t]==0) Ltemp[++tL]=Lnum[i];
		else ans[anscou++]=lie[Lnum[i]][t],vis[lie[Lnum[i]][t]]=1;
	}

	H=tH,L=tL;
	for(int i=1;i<=H;++i)
		Hnum[i]=Htemp[i];
	for(int i=1;i<=L;++i)
		Lnum[i]=Ltemp[i];

	getans();
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	char s[10];
	int a,b;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				scanf("%d",&col1[i][j]);
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				scanf("%d",&col2[i][j]);

		memset(hang,0,sizeof(hang));
		memset(lie,0,sizeof(lie));
		memset(ocouH,0,sizeof(ocouH));
		memset(ocouL,0,sizeof(ocouL));

		memset(vis,0,sizeof(vis));

		for(int i=1;i<=M;++i)
		{
			scanf("%s %d %d",s,&a,&b);
			if(b>N)
				exit(1);
			if(s[0]=='L') lie[a][b]=i,++ocouL[a];
			else hang[a][b]=i,++ocouH[a];
		}

		anscou=0;
		H=L=N;
		for(int i=1;i<=N;++i) Hnum[i]=Lnum[i]=i;
		getans();

		for(int i=1;i<=M;++i)
			if(vis[i]==0)
				ans[anscou++]=i;

		for(int i=anscou-1;i>=1;--i)
			printf("%d ",ans[i]);
		printf("%d\n",ans[0]);
	}
	
	return 0;
}
