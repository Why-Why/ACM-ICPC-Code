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
// Created Time  : 2015年07月24日 星期五 20时35分28秒
// File Name     : 1004.cpp

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

const long long INF=10000000000000000LL;
const int MaxN=100005;

int N,K,L;

struct state
{
	int x,a;

	bool operator < (const state &b) const
	{
		return x<b.x;
	}
};

state staL[MaxN],staR[MaxN];
int p1,p2;
int cou1,cou2;

void init()
{
	cou1=cou2=0;
}

long long chuli()
{
	long long ret=0;
	long long sum=0,rem=p1-1;

	for(int i=p1-1;i>=0;--i)
	{
		if(sum+staL[i].a>=K)
		{
			ret+=(staL[rem].x<<1);
			sum=sum+staL[i].a-K;
			
			if(sum+staL[i].a==K)
				rem=i-1;
			else
				rem=i;
		}
		else
			sum+=staL[i].a;
	}

	if(sum)
		ret+=(staL[rem].x<<1);

	sum=0;
	rem=p2-1;

	for(int i=p2-1;i>=0;--i)
	{
		if(sum+staR[i].a>=K)
		{
			ret+=(staR[rem].x<<1);
			sum=sum+staR[i].a-K;

			if(sum+staR[i].a==K)
				rem=i-1;
			else
				rem=i;
		}
		else
			sum+=staR[i].a;
	}

	if(sum)
		ret+=(staR[rem].x<<1);
	
	return ret;
}

long long quan()
{
	long long sum=0;

	while(p1 && p2)
	{
		if(p1==0 || staL[p1-1].x<staR[p2-1].x)
		{
			if(sum+staR[p2-1].a<K)
			{
				sum+=staR[p2-1].a;
				--p2;
			}
			else
			{
				staR[p2-1].a=staR[p2-1].a+sum-K;
				break;
			}
		}
		else
		{
			if(sum+staL[p1-1].a<K)
			{
				sum+=staL[p1-1].a;
				--p1;
			}
			else
			{
				staL[p1-1].a=staL[p1-1].a+sum-K;
				break;
			}
		}
	}

	return L;
}

long long getans()
{
	long long ans=0;
	long long sum=0,minn;

	for(int i=0;i<cou1;++i)
		if(staL[i].a>=K)
		{
			staL[i].a-=K;
			ans+=(staL[i].x<<1);
		}

	for(int i=0;i<cou2;++i)
		if(staR[i].a>=K)
		{
			staR[i].a-=K;
			ans+=(staR[i].x<<1);
		}

	while(p1>0 && staL[p1-1].a==0)
		--p1;

	while(p2>0 && staR[p2-1].a==0)
		--p2;

	minn=INF;

	int cou=0;

	while(p1 && p2)
	{
		minn=min(minn,sum+chuli());
		sum+=quan();

		if(cou>1)
			break;

		++cou;
	}

	minn=min(minn,sum+chuli());

	return ans+minn;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,x;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d %d",&L,&N,&K);
		init();

		for(int i=1;i<=N;++i)
		{
			scanf("%d %d",&x,&a);
			
			if(x==0)
				continue;

			if((x<<1)>L)
			{
				staR[cou2].x=L-x;
				staR[cou2++].a=a;
			}
			else
			{
				staL[cou1].x=x;
				staL[cou1++].a=a;
			}
		}

		sort(staL,staL+cou1);
		sort(staR,staR+cou2);
		p1=cou1;
		p2=cou2;

		printf("%I64d\n",getans());
	}
	
	return 0;
}
