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
// Created Time  : 2015年10月12日 星期一 17时59分57秒
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

using namespace std;

const int MaxN=4010;

int N;
int P[MaxN];
int D[MaxN],V[MaxN];

bool vis[MaxN];
int que[MaxN];
int first,last;

int ans[MaxN],cou=0;

void getans(int x)
{
	last=first=0;

	vis[x]=1;
	ans[cou++]=x;

	for(int i=x+1;i<=N && V[x]>0;++i)
		if(vis[i]==0)
		{
			P[i]-=V[x];
			--V[x];						// !!!!!!!!!!
			if(P[i]<0)
			{
				vis[i]=1;
				que[last++]=i;
			}
		}

	int u;

	while(last-first)
	{
		u=que[first++];
		for(int i=u+1;i<=N;++i)
			if(vis[i]==0)
			{
				P[i]-=D[u];
				if(P[i]<0)
				{
					vis[i]=1;
					que[last++]=i;
				}
			}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	first=last=0;

	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%d %d %d",V+i,D+i,P+i);

	cou=0;
	for(int i=1;i<=N;++i)
		if(vis[i]==0)
			getans(i);

	printf("%d\n%d",cou,ans[0]);
	for(int i=1;i<cou;++i)
		printf(" %d",ans[i]);
	puts("");
	
	return 0;
}
