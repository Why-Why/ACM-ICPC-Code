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
// Created Time  : 2015年06月30日 星期二 23时19分48秒
// File Name     : 2828.cpp

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

const int MaxN=666605;

int C[MaxN];
int N;

inline int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int d)
{
	while(x<=N)
	{
		C[x]+=d;
		x+=lowbit(x);
	}
}

int sum(int x)
{
	int ret=0;

	while(x>0)
	{
		ret+=C[x];
		x-=lowbit(x);
	}

	return ret;
}

int rema[MaxN],remb[MaxN];
int ans[MaxN];
int t;

int find(int x)
{
	int L=1,R=N,M;
	int t;

	while(R>L)
	{
		M=(1+L+R)>>1;

		t=sum(M);
		
		if(ans[M]==-1 && t==x)
			return M;

		if(t<x)
			L=M;
		else
			R=M-1;
	}

	return L;
}

int main()
{
	while(~scanf("%d",&N))
	{
		for(int i=1;i<=N;++i)
			scanf("%d %d",&rema[i],&remb[i]);

		memset(C,0,sizeof(C));
		memset(ans,-1,sizeof(ans));

		for(int i=1;i<=N;++i)
			add(i,1);

		for(int i=N;i>=1;--i)
		{
			++rema[i];
			t=find(rema[i]);
			ans[t]=remb[i];
			add(t,-1);
		}

		for(int i=1;i<=N;++i)
			printf("%d ",ans[i]);
		printf("\n");
	}
	
	return 0;
}
