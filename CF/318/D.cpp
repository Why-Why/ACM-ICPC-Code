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
// Created Time  : 2015年09月06日 星期日 21时46分03秒
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

const int MaxN=100005;
const int INF=0x3f3f3f3f;

int a[MaxN];
int num[MaxN];
int aaa[MaxN];
int minn[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,ans=0;
	
	scanf("%d",&N);

	for(int i=1;i<=N;++i)
		scanf("%d",&a[i]);

	a[0]=a[N+1]=0;
	for(int i=1;i<=N;++i)
		num[i]=min(a[i-1]+1,min(a[i+1]+1,a[i]));

	int ttt=INF;
	
	for(int i=1;i<=N;++i)
	{
		ttt=min(ttt,num[i]-i);
		minn[i]=ttt+i;
	}

	ttt=INF;

	for(int i=N;i>=1;--i)
	{
		ttt=min(ttt,num[i]+i);
		minn[i]=min(minn[i],ttt-i);
	}

	for(int i=1;i<=N;++i)
		ans=max(ans,minn[i]);

	printf("%d\n",ans);
	
	return 0;
}
