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
// Created Time  : 2015年09月19日 星期六 14时12分15秒
// File Name     : 1010_1.cpp

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

const int MaxN=300005;
const int mod=530600414;

long long P[MaxN];
long long S[MaxN];
long long len[MaxN];
long long f[MaxN];

void init()
{
	S[1]=0;
	S[2]=0;
	S[3]=1;
	S[4]=3;
	P[1]=P[2]=0;
	P[3]=P[4]=1;
	len[1]=1;
	len[2]=2;
	len[3]=3;
	len[4]=5;
	f[3]=0;
	f[4]=0;

	for(int i=5;i<201500;++i)
	{
		f[i]=f[i-2]+f[i-1];
		f[1]%=mod;
		f[i]+=((S[i-1]+P[i-1]*len[i-2]%mod)%mod)*P[i-2]%mod-S[i-2]*P[i-1]%mod;
		f[i]=(f[i]%mod+mod)%mod;

		len[i]=(len[i-2]+len[i-1])%mod;
		P[i]=(P[i-2]+P[i-1])%mod;

		S[i]=S[i-2]+S[i-1]+P[i-1]*len[i-2]%mod;
		S[i]%=mod;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();
	int T,cas=1,a;

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		printf("Case #%d: %d\n",cas++,(int)f[a]);
	}
	
	return 0;
}
