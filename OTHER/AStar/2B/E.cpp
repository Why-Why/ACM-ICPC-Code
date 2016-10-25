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
// Created Time  : 2016年05月22日 星期日 15时21分05秒
// File Name     : E.cpp

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

int N,K,M;
int num[MaxN];
pii rrr[MaxN];
long long sum[MaxN];
int C[MaxN];

inline int lowbit(int x) {
	return x&(-x);
}

inline void add(int p) {
	for(;p<=N;p+=lowbit(p)) ++C[p];
}

inline int find(int x) {
	int ans=0,sum=0;
	for(int i=18;i>=0;--i) {
		ans+=(1<<i);
		if(ans>N || sum+C[ans]>=x) ans-=(1<<i);
		else sum+=C[ans];
	}
	return ans+1;
}

inline long long getans(int id) {
	int p=find(K);
	if(p<=id) return sum[id]-sum[p-1];
	return 0;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d %d",&N,&K,&M)) {
		sum[0]=0;
		memset(C,0,sizeof(C));
		for(int i=1;i<=N;++i) scanf("%d",num+i),sum[i]=sum[i-1]+num[i];
		for(int i=1;i<=M;++i) scanf("%d %d",&rrr[i].second,&rrr[i].first);
		sort(rrr+1,rrr+M+1);
		int p=M;
		long long ans=0;

		for(int i=N;i>=1;--i) {
			while(p>=1 && rrr[p].first>=i) {
				add(rrr[p].second);
				--p;
			}
			ans=max(ans,getans(i));
		}
		printf("%I64d\n",ans);
	}
	
	return 0;
}
