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
// Created Time  : 2015年08月18日 星期二 12时16分33秒
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

const int MaxN=100005;

int zuo2[MaxN],zuo1[MaxN];
int num[MaxN];
int N,d1,d2;
long long ans[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d %d",&N,&d1,&d2))
	{
		for(int i=1;i<=N;++i)
		{
			zuo1[i]=zuo2[i]=ans[i]=0;
			scanf("%d",&num[i]);
		}
		zuo1[1]=zuo2[1]=1;

		for(int i=2;i<=N;++i)
		{
			if(num[i]-num[i-1]==d1)
				zuo1[i]=zuo1[i-1]+1;
			else zuo1[i]=1;

			if(num[i]-num[i-1]==d2)
				zuo2[i]=zuo2[i-1]+1;
			else zuo2[i]=1;
		}

		long long t;
		long long zans=1;
		ans[1]=1;
		for(int i=2;i<=N;++i)
		{
			if(d1==d2)
			{
				t=zuo1[i];
				ans[i]=t;
			}
			else
			{
				t=zuo2[i]+zuo1[i+1-zuo2[i]]-1;
				ans[i]=t;
			}
			zans+=ans[i];
		}
		
		printf("%I64d\n",zans);
	}
	
	return 0;
}
