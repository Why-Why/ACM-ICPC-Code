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
// Created Time  : 2016年01月09日 星期六 09时28分42秒
// File Name     : A.cpp

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

const int MaxN=2003;

int N;
typedef pair<int,int> pii;
pii P[MaxN];

long long dis[MaxN],dcou;

long long dist(pii &a,pii &b) {
	return (a.first-b.first)*(a.first-b.first+0LL)+(a.second-b.second+0LL)*(a.second-b.second+0LL);
}

long long getans() {
	sort(dis,dis+dcou);
	long long ret=0,cou=1;
	dis[dcou]=100000000000000000LL;
	for(int i=1;i<=dcou;++i)
		if(dis[i]==dis[i-1]) ++cou;
		else {
			ret+=cou*(cou-1)/2;
			cou=1;
		}
	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		for(int i=1;i<=N;++i) scanf("%d %d",&P[i].first,&P[i].second);

		long long ans=0;
		for(int i=1;i<=N;++i) {
			dcou=0;
			for(int j=1;j<=N;++j)
				dis[dcou++]=dist(P[i],P[j]);
			ans+=getans();
		}
		printf("Case #%d: %lld\n",cas++,ans);
	}
	
	return 0;
}
