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
// Created Time  : 2016年08月02日 星期二 15时53分54秒
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

int K,W;
long long ans[2003][2003];

long long getans(int K,int W) {
	if(K==0) return 0;
	if(W==1) return K*(K+1)/2+K;
	if(ans[K][W]!=-1) return ans[K][W];

	for(int i=1;i<=K;++i)
		if(ans[K][W]!=-1) ans[K][W]=min(getans(K-i,W)+getans(i-1,W-1),ans[K][W]);
		else ans[K][W]=getans(K-i,W)+getans(i-1,W-1);
	ans[K][W]+=K+1;
	return ans[K][W];
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&K,&W)) {
		memset(ans,-1,sizeof(ans));
		printf("%.6f\n",(double)getans(K,W)/(K+1.0));
	}

	return 0;
}
