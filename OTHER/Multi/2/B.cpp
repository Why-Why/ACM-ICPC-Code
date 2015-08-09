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
// Created Time  : 2015年07月23日 星期四 13时19分47秒
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

int N,M,X,Y;
int a[10];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d %d %d",&N,&M,&X,&Y))
	{
		a[0]=X-1;
		a[2]=N-X;
		a[1]=Y-1;
		a[3]=M-Y;

		int t1=max(a[0]+1,min(a[2],(a[1]+a[3]+2)/2));
		int t2=max(a[2]+1,min(a[0],(a[1]+a[3]+2)/2));
		int t3=max(a[1]+1,min(a[3],(a[0]+a[2]+2)/2));
		int t4=max(a[3]+1,min(a[1],(a[0]+a[2]+2)/2));

		printf("%d\n",min(max(max(a[0],a[1]),max(a[2],a[3])),min(min(t1,t2),min(t3,t4))));
	}
	
	return 0;
}
