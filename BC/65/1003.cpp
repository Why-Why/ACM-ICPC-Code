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
// Created Time  : 2015年12月05日 星期六 19时19分37秒
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

const int MaxN=50005;

int C[MaxN];
int N;
int num[MaxN];
int ans[MaxN];

inline int lowbit(int x) {
	return x&(-x);
}

void add(int x,int d) {
	for(;x<=N;x+=lowbit(x)) C[x]+=d;
}

int find(int x)		// 寻找树状数组中和为x的第一个位置。
{
	int ans=0,sum=0;

	for(int i=18;i>=0;--i)
	{
		ans+=(1<<i);

		if(ans>N || sum+C[ans]>=x)
			ans-=(1<<i);
		else
			sum+=C[ans];
	}

	return ans+1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		int t,t1;
		scanf("%d",&N);
		num[0]=0;
		for(int i=1;i<=N;++i) scanf("%d",num+i);
		for(int i=1;i<=N;++i) add(i,1);

		for(int i=N;i>=1;--i) {
			t=num[i]-num[i-1];
			++t;
			t1=find(t);
			ans[i]=N+1-t1;
			add(t1,-1);
		}

		printf("%d",ans[1]);
		for(int i=2;i<=N;++i)
			printf(" %d",ans[i]);
		printf("\n");
	}
	
	return 0;
}
