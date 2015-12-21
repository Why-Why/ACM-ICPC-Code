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
// Created Time  : 2015年09月26日 星期六 19时03分24秒
// File Name     : 1001.cpp

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

int remX[MaxN],remY[MaxN];
int N,M;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int K,Q;
	int a,b,c,d;

	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d %d",&N,&M,&K,&Q);
		for(int i=0;i<=N;++i) remX[i]=0;
		for(int i=0;i<=M;++i) remY[i]=0;

		while(K--)
		{
			scanf("%d %d",&a,&b);
			remX[a]=1;
			remY[b]=1;
		}

		for(int i=1;i<=N;++i) remX[i]+=remX[i-1];
		for(int i=1;i<=M;++i) remY[i]+=remY[i-1];

		while(Q--)
		{
			scanf("%d %d %d %d",&a,&b,&c,&d);
			if(remX[c]-remX[a-1]==c-a+1 || remY[d]-remY[b-1]==d-b+1)
				puts("Yes");
			else puts("No");
		}
	}
	
	return 0;
}
