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
// Created Time  : 2015年08月06日 星期四 16时07分18秒
// File Name     : 1010.cpp

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

const int mod=1000000007;
const int MaxN=2010;

long long hui[MaxN];
long long fang[MaxN];

int N,M;

long long huiwei(int N,int M)
{
	hui[0]=1;
	fang[0]=1;

	for(int i=1;i<=N;++i)
	{
		fang[i]=(fang[i-1]*M)%mod;

		if(i&1)
			hui[i]=(hui[i-1]*M)%mod;
		else
			hui[i]=fang[i/2];
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);
		huiwei(N,M);

		while(cin>>a)
			cout<<hui[a]<<endl;
	}
	
	return 0;
}
