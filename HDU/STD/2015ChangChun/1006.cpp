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
// Created Time  : 2015年11月01日 星期日 13时03分22秒
// File Name     : 1006.cpp

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

int N;
int num[MaxN];
bool rem1[MaxN],rem2[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);
		for(int i=1;i<=N;++i) scanf("%d",num+i);

		rem1[N]=rem2[N]=1;
		for(int i=N-1;i>=1;--i)
		{
			if(rem1[i+1] && num[i]<=num[i+1]) rem1[i]=1;
			else rem1[i]=0;
			if(rem2[i+1] && num[i]>=num[i+1]) rem2[i]=1;
			else rem2[i]=0;
		}

		bool r1=1,r2=1;
		bool ans=0;

		rem1[N+1]=rem2[N+1]=1;
		for(int i=1;i<=N;++i)
		{
			if(r1 && rem1[i+1] && (i==N || i==1 || num[i-1]<=num[i+1])) ans=1;
			if(r2 && rem2[i+1] && (i==N || i==1 || num[i-1]>=num[i+1])) ans=1;
			if(i>1 && num[i]<num[i-1]) r1=0;
			if(i>1 && num[i]>num[i-1]) r2=0;
		}

		if(ans) puts("YES");
		else puts("NO");
	}
	
	return 0;
}
