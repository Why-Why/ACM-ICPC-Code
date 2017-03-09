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
// Created Time  : 2016年04月16日 星期六 14时20分18秒
// File Name     : C.cpp

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
const int mod=1000000007;

int N;
int num[MaxN];

long long ppp[MaxN];
long long C[MaxN];

inline int lowbit(int x) {
	return x&(-x);
}

inline void add(int x,long long d) {
	for(;x<=N;x+=lowbit(x)) C[x]+=d;
}

inline long long sum(int x) {
	long long ret=0;
	for(;x;x-=lowbit(x)) (ret+=C[x])%=mod;
	return ret;
}

inline long long getans(int p) {
	long long t=sum(num[p]-1);
	if(p!=1)
	add(num[p],ppp[p-1]);

	return (t*ppp[N-p])%mod;
}

inline long long getans1(int p) {
	long long t=sum(num[p]-1);
	add(num[p],ppp[N-p]);
	return (t*ppp[p-1])%mod;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);
	
	ppp[0]=1;
	for(int i=1;i<MaxN;++i) ppp[i]=(ppp[i-1]*2)%mod;

	while(T--) {
		scanf("%d",&N);
		for(int i=1;i<=N;++i) scanf("%d",num+i);

		long long ans=0;

		memset(C,0,sizeof(C));
		for(int i=1;i<=N;++i) (ans+=getans(i))%=mod;
		memset(C,0,sizeof(C));
		for(int i=N;i>1;--i) (ans+=getans1(i))%=mod;
		for(int i=2;i<=N;++i) if(num[i]!=num[1]) (ans+=2*ppp[N-i])%=mod;
		printf("%lld\n",ans);
	}
	
	return 0;
}
