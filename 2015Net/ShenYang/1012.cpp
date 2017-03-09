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
// Created Time  : 2015年09月19日 星期六 12时22分03秒
// File Name     : 1012.cpp

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

const int MaxN=5000006;

int N,A,B;
int t;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long maxn,minn,pmax,pmin,amin;
	int r1,r2,r3,r4,r5;

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d %d",&N,&A,&B);
		maxn=-100000000;
		pmax=maxn;
		minn=100000000;
		pmin=minn;
		amax=-100000000;
		amin=100000000;

		for(int i=1;i<=N;++i)
		{
			scanf("%d",&t);
			if(maxn<t) { r3=r1; r1=i; pmax=maxn; maxn=t; }
			else if(pmax<t) pmax=t,r3=i;
			if(minn>t) { r4=r2; r2=i; pmin=minn; minn=t;}
			else if(pmin>t) pmin=t,r4=i;
			if(amin>abs(t))
			{
				amin=abs(t);
				r5=i;
			}
		}

		long long ans;

		ans=a*maxn

		if(a==0)
		{
			if(b>=0) ans=maxn*b;
			else ans=minn*b;
		}
		else if(a>0)
		{

		}
	}
	
	return 0;
}
