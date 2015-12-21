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
// Created Time  : 2015年10月31日 星期六 12时20分28秒
// File Name     : 1009.cpp

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

long long cou1[MaxN],cou2[MaxN];
long long rem2[MaxN];

struct State
{
	int a,b;
	int c;
	
	bool operator < (const State & t) const
	{
		if(a==t.a) return b<t.b;
		return a<t.a;
	}
}sta1[MaxN],sta2[MaxN];

int N,M;

long long getans()
{
	long long ret=0;
	int flag=-1;
	int maxn=-1;
	if(N>1 && sta1[N].a>sta1[N-1].a) flag=sta1[N].c;

	for(int i=1;i<=N;++i) ++cou1[sta1[i].c];
	for(int i=M;i>=1;--i)
	{
		++cou2[sta2[i].c];
		if(sta2[i].b>maxn && (i==1 || sta2[i-1].a!=sta2[i].a || sta2[i-1].b!=sta2[i].b))
			++rem2[sta2[i].c];
		maxn=max(maxn,sta2[i].b);
	}

	cout<<flag<<endl;

	for(int i=1;i<5;++i)
		cout<<rem2[i]<<' ';
	cout<<endl;

	if(flag!=-1) ret+=cou2[flag]-rem2[flag];
	for(int i=1;i<=100000;++i)
		ret+=rem2[i]*cou1[i];

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&M);
		memset(cou1,0,sizeof(cou1));
		memset(cou2,0,sizeof(cou2));
		memset(rem2,0,sizeof(rem2));
		for(int i=1;i<=N;++i) scanf("%d %d",&sta1[i].a,&sta1[i].c),sta1[i].b=0;
		for(int i=1;i<=M;++i) scanf("%d %d %d",&sta2[i].a,&sta2[i].b,&sta2[i].c);
		sort(sta1+1,sta1+N+1);
		sort(sta2+1,sta2+M+1);

		printf("Case #%d: %I64d\n",cas++,getans());
	}
	
	return 0;
}
