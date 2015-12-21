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
// Created Time  : 2015年10月04日 星期日 15时41分44秒
// File Name     : E.cpp

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

const int MaxN=10004;

struct Num
{
	long long n;
	int id;

	bool operator < (const Num & b) const
	{
		return n<b.n;
	}

}num[MaxN];

int N;
int ans[MaxN],cou;

void other()
{
	if(num[N].n==1000)
	{
		printf("1\n%d",num[N].id);
		return;
	}

	if(N>=2 && num[1].n * num[2].n==1000000)
	{
		printf("2\n%d %d",min(num[1].id,num[2].id),max(num[1].id,num[2].id));
		return;
	}

	if(N==1)
	{
		printf("1\n%d",num[1].id);
		return;
	}

	long long m1=num[1].n;
	long long m2=m1;

	for(int i=1;i<=N;++i)
		m1=max(m1,num[i].n);

	m2=num[1].n*num[2].n;
	for(int i=1;i+1<=N;++i)
		m2=max(m2,num[i].n*num[i+1].n);

	if(m1*1000>=m2)
	{
		printf("1\n");
		for(int i=1;i<=N;++i)
			if(num[i].n==m1)
			{
				printf("%d",num[i].id);
				return;
			}
	}
	else
	{
		printf("2\n");
		for(int i=1;i+1<=N;++i)
			if(m2==num[i].n*num[i+1].n)
			{
				printf("%d %d",min(num[i].id,num[i+1].id),max(num[i].id,num[i+1].id));
				return;
			}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	double t;

	while(~scanf("%d",&N))
	{
		cou=0;
		for(int i=1;i<=N;++i)
		{
			scanf("%lf",&t);
			num[i].id=i;
			num[i].n=t*1000;
		}

		sort(num+1,num+N+1);

		for(int i=N;i>=1;--i)
			if(num[i].n>1000) ans[cou++]=num[i].id;
			else break;

		for(int i=1;i<=N;i+=2)
			if(num[i].n>=0) break;
			else
			{
				if(i+1>N) break;
				if(num[i].n>=-1000) break;
				if(num[i+1].n>=0) break;

				if(num[i+1].n*num[i].n>1000000)
				{
					ans[cou++]=num[i].id;
					ans[cou++]=num[i+1].id;
				}
			}

		if(cou)
		{
			sort(ans,ans+cou);

			printf("%d\n",cou);
			printf("%d",ans[0]);
			for(int i=1;i<cou;++i)
				printf(" %d",ans[i]);
		}
		else
			other();

		puts("");
	}
	
	return 0;
}
