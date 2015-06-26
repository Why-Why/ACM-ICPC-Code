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
// Created Time  : 2015年05月06日 星期三 23时49分25秒
// File Name     : 1840.cpp

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

const int HASH=100019;
const int MaxN=100005;

struct HashMap
{
	int head[HASH],next[MaxN],Hcou;
	long long key[MaxN];
	int cou[MaxN];

	void init()
	{
		Hcou=0;
		memset(head,-1,sizeof(head));
	}

	void insert(long long val)
	{
		int h=val % HASH;

		if(h<0)
			h+=HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(val==key[i])
			{
				++cou[i];
				return;
			}

		key[Hcou]=val;
		cou[Hcou]=1;
		next[Hcou]=head[h];
		head[h]=Hcou++;
	}

	int count(long long val)
	{
		int h=val % HASH;

		if(h<0)
			h+=HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(val==key[i])
				return cou[i];

		return 0;
	}
}sta;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long a,b,c,d,e;
	long long t;
	long long ans=0;

	sta.init();

	scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&e);

	for(int x1=-50;x1<=50;++x1)
	{
		if(x1==0)
			continue;

		for(int x2=-50;x2<=50;++x2)
		{
			if(x2==0)
				continue;

			t=a*x1*x1*x1+b*x2*x2*x2;

			sta.insert(t);
		}
	}

	for(int x3=-50;x3<=50;++x3)
	{
		if(x3==0)
			continue;

		for(int x4=-50;x4<=50;++x4)
		{
			if(x4==0)
				continue;

			for(int x5=-50;x5<=50;++x5)
			{
				if(x5==0)
					continue;

				t=c*x3*x3*x3+d*x4*x4*x4+e*x5*x5*x5;

				ans+=sta.count(t);
			}
		}
	}

	printf("%lld\n",ans);
	
	return 0;
}
