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
// Created Time  : 2015年07月30日 星期四 16时51分36秒
// File Name     : 1008_1.cpp

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

int N;

void getans(int &a,int &b,int &c)
{
		for(b=1;b<=1000;++b)
			for(a=b;a+b<=100000;++a)
				if((N-a*b-a-b)%(b+a+1)==0)
				{
					c=(N-a*b-a-b)/(b+a+1);
					return;
				}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;

	while(~scanf("%d",&N))
	{
		getans(a,b,c);

		printf("%d\n",a+b+c);

		printf("1");
		for(int i=2;i<=a;++i)
			printf(" %d",1);
		for(int i=1;i<=b;++i)
			printf(" %d",2);
		for(int i=1;i<=c;++i)
			printf(" %d",3);
		puts("");
	}
	
	return 0;
}
