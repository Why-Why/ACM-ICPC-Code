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
// Created Time  : 2015年07月25日 星期六 09时39分29秒
// File Name     : 1003.cpp

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

int w1,w2,w0,b1,b2,b0;
int rem[10000];
int N;

void chuli(int a,int b,int c,int type)
{
	int i;
	
	for(i=1;i<=c+1;++i)
		printf("%d %d %d\n",rem[i],rem[i+1],type);
	b-=2;
	++i;

	while(b)
	{
		printf("%d %d %d\n",rem[i],rem[i+1],type);
		i+=2;
		b-=2;
	}
}

void quan()
{
	if(N&1)
		for(int i=1,p=1;i<=N;++i)
		{
			rem[i]=p;
			p+=2;
			
			if(p>N)
				p-=N;
		}
	else
	{
		int p=3;
		int i=1;

		rem[i++]=1;

		while(p!=1)
		{
			rem[i++]=p;
			p+=2;

			if(p>N)
				p-=N;
		}

		p=N;
		rem[i++]=2;

		while(p!=2)
		{
			rem[i++]=p;
			p-=2;

			if(p<1)
				p+=N;
		}
	}
}

void getans()
{
	if(w1 & 1 || b1 & 1)
	{
		puts("-1");
		return;
	}

	if(N==4)
	{
		puts("4");
		puts("1 2 0");
		puts("2 3 0");
		puts("3 4 1");
		puts("4 1 1");
		return;
	}

	printf("%d\n",w1/2+w2+b1/2+b2);

	for(int i=1;i<=N;++i)
		rem[i]=i;
	chuli(w0,w1,w2,0);
	quan();
	chuli(b0,b1,b2,1);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d %d %d %d %d",&w0,&w1,&w2,&b0,&b1,&b2);
		N=w0+w1+w2;

		getans();
	}
	
	return 0;
}
