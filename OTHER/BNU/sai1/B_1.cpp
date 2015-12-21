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
// Created Time  : 2015年10月01日 星期四 14时05分16秒
// File Name     : B_1.cpp

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

int N;
int num[MaxN];
long long tnum[MaxN];
long long T;

bool cmp(int a,int b)
{
	return a%T<b%T;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long ans;

	while(~scanf("%d",&N))
	{
		ans=0;
		for(int i=1;i<=N;++i)
			scanf("%d",num+i);

		T=10;
		int p;
		for(int l=0;l<10;++l)
		{
			p=N;
			for(int i=1;i<=N;++i) tnum[i]=num[i]%T;
			sort(tnum+1,tnum+N+1);

			for(int i=1;i<=N;++i)
			{
				while(p>i && tnum[i]+tnum[p]>=T)
					--p;
				ans+=N-max(i,p);
			}
			T*=10LL;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
