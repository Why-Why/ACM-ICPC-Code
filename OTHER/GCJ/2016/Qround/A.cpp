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
// Created Time  : 2016年04月09日 星期六 18时21分56秒
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

long long getans(long long x) {
	bool vis[10]={};
	int cou=0;
	long long s=0,t;

	while(1) {
		s+=x;
		t=s;
		while(t) {
			if(vis[t%10]==0) vis[t%10]=1,++cou;
			t/=10;
		}
		if(cou==10) return s;
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int N;

	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		printf("Case #%d: ",cas++);
		if(N==0) puts("INSOMNIA");
		else printf("%lld\n",getans(N));
	}
	
	return 0;
}
