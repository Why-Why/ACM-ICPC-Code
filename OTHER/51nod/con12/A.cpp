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
// Created Time  : 2016年04月15日 星期五 20时41分52秒
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

const int MaxN=100005;

typedef pair<int,int> pii;

int N;
long long K;
pii num[MaxN],rem[MaxN];
int rcou;

bool judge(int M) {
	rcou=0;
	for(int i=1;i+M-1<=N;++i) {
		if(num[i+M-1].first!=num[i].first) continue;
		rem[++rcou]=pii(num[i].second,N-num[i+M-1].second+1);
	}
	sort(rem+1,rem+rcou+1);

	long long sum=0;
	long long maxn=rem[rcou].second,rrr=rcou;

	for(int i=rcou-1;i>=1;--i) {
		if(maxn<rem[i].second) {
			sum+=maxn*(rem[rrr].first-rem[i].first);
			rrr=i;
			maxn=rem[i].second;
		}
	}
	sum+=maxn*rem[rrr].first;

	return sum>=K;
}

int getans() {
	int L=1,R=N,M;

	while(R>L) {
		M=(L+R+1)>>1;
		if(judge(M)) L=M;
		else R=M-1;
	}
	return L;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a;

	scanf("%d %lld",&N,&K);
	for(int i=1;i<=N;++i) {
		scanf("%d",&num[i].first);
		num[i].second=i;
	}
	sort(num+1,num+N+1);

	printf("%d\n",getans());
	
	return 0;
}
