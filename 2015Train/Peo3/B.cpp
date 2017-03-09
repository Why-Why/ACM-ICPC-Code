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
// Created Time  : 2015年09月23日 星期三 20时14分04秒
// File Name     : B.cpp

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

int N,A,B;

struct State
{
	int g,a,b;
	int id;

	bool operator < (const State & x) const
	{
		return a*x.b>b*x.a;
	}
};

State sta[MaxN];

double ans[MaxN]={0};

double eps=1e-10;

int main()
{
	freopen("burrito.in","r",stdin);
	freopen("burrito.out","w",stdout);

	scanf("%d %d %d",&N,&A,&B);
	for(int i=1;i<=N;++i)
	{
		scanf("%d %d %d",&sta[i].g,&sta[i].a,&sta[i].b);
		sta[i].id=i;
	}
	sort(sta+1,sta+N+1);

	double sumA=0;
	double sumB=0;
	for(int i=1;i<=N;++i)
	{
		if(sumB+sta[i].g*sta[i].b<=B+eps)
		{
			ans[sta[i].id]=sta[i].g;
			sumA+=sta[i].g*sta[i].a;
			sumB+=sta[i].g*sta[i].b;
		}
		else
		{
			ans[sta[i].id]=(double)(B-sumB)/(double)sta[i].b;
			sumA+=ans[sta[i].id]*sta[i].a;
			sumB=B;
		}
	}

	if(sumA>=A)
	{
		printf("%.10f %.10f\n",sumA,sumB);
		printf("%.10f",ans[1]);
		for(int i=2;i<=N;++i)
			printf(" %.10f",ans[i]);
		puts("");
	}
	else puts("-1 -1");

	return 0;
}
