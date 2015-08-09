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
// Created Time  : 2015年07月17日 星期五 14时44分13秒
// File Name     : 1195.cpp

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

const int MaxN=1100;

int C[MaxN][MaxN];
int N;

inline int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int y,int d)
{
	int t;

	while(x<=N)
	{
		t=y;

		while(t<=N)
		{
			C[x][t]+=d;
			t+=lowbit(t);
		}

		x+=lowbit(x);
	}
}

int query(int x,int y)
{
	int ret=0;
	int t;

	while(x>0)
	{
		 t=y;

		 while(t>0)
		 {
			 ret+=C[x][t];
			 t-=lowbit(t);
		 }

		 x-=lowbit(x);
	}

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c,d,e;

	while(1)
	{
		scanf("%d",&a);

		if(a==1)
		{
			scanf("%d %d %d",&b,&c,&d);
			add(b+1,c+1,d);
		}
		else if(a==2)
		{
			scanf("%d %d %d %d",&b,&c,&d,&e);
			printf("%d\n",query(d+1,e+1)-query(d+1,c)-query(b,e+1)+query(b,c));
		}
		else if(a==0)
		{
			scanf("%d",&N);
			memset(C,0,sizeof(C));
		}
		else
			break;
	}
	
	return 0;
}
