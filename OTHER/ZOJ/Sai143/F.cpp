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
// Created Time  : 2015年10月14日 星期三 22时30分47秒
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

const int MaxN=100005;

priority_queue <int> que;
int N,M,K;
long long ans;
int num[MaxN];

int stack[MaxN],top;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out1.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d %d",&N,&M,&K);
		for(int i=1;i<=N;++i) scanf("%d",num+i);
		sort(num+1,num+N+1);

		while(!que.empty()) que.pop();
		ans=0;

		int p=1;
		top=0;

		for(int i=N;i>=1;--i)
		{
			while(p<i && num[p]+num[i]<=K) stack[top++]=num[p++];
			if(top) que.push(stack[--top]*num[i]);
			if(p>=i) break;
		}
		while(top>1) que.push(stack[--top]*stack[--top]);

		while(M && !que.empty())
		{
			ans+=que.top();
			que.pop();
			--M;
		}

		printf("%lld\n",ans);
	}
	
	return 0;
}
