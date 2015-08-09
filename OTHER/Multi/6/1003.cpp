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
// Created Time  : 2015年08月06日 星期四 12时19分10秒
// File Name     : 1003.cpp

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

const int MaxN=100005;

int vis[MaxN];
int flag=0;

int ans[12][MaxN],cou[15];

int zong;
long long sum;
int N,M;

/*
bool dfs(int x,long long res)
{
	cou=0;

	long long zsum=0;

	if(res<x)
		return 0;

	for(int i=x;i>=1;--i)
	{
		if(res==0)
			break;

		if(vis[i]!=flag && i<=res)
		{
			res-=i;
			vis[i]=flag;
			ans[cou++]=i;

			if(res==0)
				break;
			
			if(res<i && vis[res]!=flag)
			{
				vis[res]=flag;
				ans[cou++]=res;
				res=0;
				break;
			}
		}
	}

	if(res)
	{
		cerr<<endl<<zong<<endl;
		cerr<<endl<<res<<endl;
		exit(1);
	}

	printf("%d",cou);
	++zong;

	for(int i=0;i<cou;++i)
	{
		zsum+=ans[i];
		printf(" %d",ans[i]);
	}

	if(zsum!=sum)
	{
		cerr<<zong<<endl;
		cerr<<"weaiurheaskfyhkasdf";
		exit(1);
	}

	puts("");
}*/

bool dfs(int x,long long res,int ceng,int dep)
{
	if(ceng>M)
		return 1;

	if(res==0)
	{
		cou[ceng]=dep;
		return dfs(min(sum,(long long)N),sum,ceng+1,0);
	}

	for(int i=x;i>=1;--i)
		if(vis[i]!=flag && res>=i)
		{
			vis[i]=flag;
			ans[ceng][dep]=i;
			if(dfs(i-1,res-i,ceng,dep+1))
				return 1;
			vis[i]=0;
		}

	return 0;
}

bool getans()
{
	return dfs(N,sum,1,0);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		zong=0;
		scanf("%d %d",&N,&M);
		sum=(N+1LL)*N/2LL;
		
		if(sum%M || N>sum/M)
		{
			puts("NO");
			continue;
		}

		sum/=M;
		++flag;
		memset(cou,0,sizeof(cou));

		if(getans())
		{
			puts("YES");
			for(int i=1;i<=M;++i)
			{
				printf("%d",cou[i]);
				for(int j=0;j<cou[i];++j)
					printf(" %d",ans[i][j]);
				puts("");
			}
		}
		else
			puts("NO");
	}
	
	return 0;
}
