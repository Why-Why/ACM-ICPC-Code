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
// Created Time  : 2016年04月20日 星期三 23时22分35秒
// File Name     : D.cpp

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
#include <bitset>

using namespace std;

const int MaxN=1005;

bool vis[2000005];

int N,num[MaxN];
int ans=0;
int rcou=0;

bitset <MaxN> can,zans,tcan,have;
bitset <MaxN> rrr[MaxN];

void init() {
	vis[1]=1;
	for(int i=2;i<=2000000;++i)
		if(!vis[i])
			for(int j=i+i;j<=2000000;j+=i) vis[j]=1;

	for(int i=1;i<=N;++i) {
		rrr[i].set();
		for(int j=i+1;j<=N;++j)
			if(vis[num[i]+num[j]]) rrr[i].reset(j);
	}
}

void dfs(int p) {
	if(p>N) {
		if(ans<rcou) { ans=rcou; zans=have; }
		return;
	}
	if(N-p+1+rcou<=ans) return;

	if(can[p]) {
		++rcou;
		tcan=can;
		have[p]=1;
		can&=rrr[p];
		dfs(p+1);
		--rcou;
		have[p]=0;
		can=tcan;
	}
	dfs(p+1);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<=N;++i) scanf("%d",num+i);

	have.reset();
	can.set();
	init();
	dfs(1);

	printf("%d\n",ans);
	for(int i=1;i<=N;++i) if(zans[i]) printf("%d ",num[i]);
	puts("");
	
	return 0;
}
