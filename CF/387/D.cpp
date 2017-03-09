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
// Created Time  : 2017年01月16日 星期一 14时56分44秒
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

using namespace std;

const int MaxN=200006;

int N,K;
int t[MaxN];

int rem[MaxN];
int rcou;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&K);

	int fcou=0;
	int last=-1;
	for(int i=1;i<=N;++i) {
		scanf("%d",t+i);
		if(t[i]<0) ++fcou;

		if(t[i]>=0 && t[i-1]<0) last=i;
		else if(t[i]<0 && t[i-1]>=0 && last!=-1) rem[++rcou]=i-last;
	}
	sort(rem+1,rem+rcou+1);

	if(fcou>K) {
		puts("-1");
		return 0;
	}
	fcou=K-fcou;

	if(last==-1) {
		if(t[N]>=0) puts("0");
		else puts("1");

		return 0;
	}

	int ans=0,sum=0,tans=0;

	for(int i=1;i<=rcou;++i)
		if(sum+rem[i]<=fcou) sum+=rem[i],++tans;
		else break;

	ans=2*(rcou+1-tans);

	if(t[N]<0) --ans;
	else {
		fcou-=N+1-last;
		if(fcou>=0) {
			tans=sum=0;
			for(int i=1;i<=rcou;++i)
				if(sum+rem[i]<=fcou) sum+=rem[i],++tans;
				else break;

			ans=min(ans,2*(rcou+1-tans)-1);
		}
	}
	printf("%d\n",ans);

	return 0;
}
