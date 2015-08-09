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
// Created Time  : 2015年07月30日 星期四 15时44分17秒
// File Name     : 1008.cpp

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

long long rem[100005];

void init()
{
	for(long long i=1;i<=100000;++i)
		rem[i]=i*(i+1LL)/2LL;
}

long long judge(long long x)
{
	if(x<1)
		return 0;

	long long t=8*x+1;
	long long t1=sqrt((double)t);

	if(t1*t1!=t || !(t1&1))
		return 0;

	return (t1-1)>>1;
}

bool judge1(long long x,int t,long long &a,long long &b)
{
	long long temp;

	for(int i=0;i<=t;++i)
	{
		temp=judge(x-rem[i]);
		
		if(temp && temp>=t+t)
		{
			a=temp;
			b=i;
			return 1;
		}
	}

	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();
	int N;
	long long a,b,c;
	int x,y,d;
	int cou;

	while(~scanf("%d",&N))
	{
/*		if(N<=100000)
		{
			printf("%d\n",N);
			printf("1");
			for(int i=2;i<=N;++i)
				printf(" 1");
			puts("");

			continue;
		}
*/
		for(int i=0;i<=100000;++i)
			if(judge1(N+rem[i],i,a,b))
			{
				c=i;
				break;
			}

		x=c;
		d=b;
		y=a-x;
		cou=0;

		cout<<a<<' '<<b<<' '<<c<<endl<<x<<' '<<y<<' '<<d<<endl;

		printf("%d\n",x+y);

		for(int i=1;i<=y;++i)
		{
			if(cou)
				printf(" ");
			++cou;
			printf("%d",i);
		}

		for(int i=1;i<=d;++i)
		{
			if(cou)
				printf(" ");
			++cou;
			printf("%d",i);
		}

		for(int i=d+1;i<=x;++i)
		{
			if(cou)
				printf(" ");
			++cou;
			printf("%d",i-d);
		}

		puts("");
	}
	
	return 0;
}
