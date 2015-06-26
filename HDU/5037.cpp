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
// Created Time  : 2015年05月17日 星期日 14时07分04秒
// File Name     : 5037.cpp

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

long long num[300005];
int N;
long long M,L;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int ans;
	long long p;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %lld %lld",&N,&M,&L);

		for(int i=1;i<=N;++i)
			scanf("%lld",&num[i]);

		num[++N]=M;

		sort(num+1,num+N+1);
		ans=0;
		p=0;

		for(int i=1;i<=N;)
		{
			while(i<=N && num[i]-p<=L)
				++i;
			--i;

			if(num[i]==p)
			{
				p=num[i]+((num[i+1]-p)/(L+1))*(L+1);
				ans+=2*((p-num[i])/(L+1));
			}
			else
			{
				++ans;
				p=num[i];
			}

			if(p==M)
				break;
		}

		printf("Case #%d: %d\n",cas++,ans);
	}
	
	return 0;
}
