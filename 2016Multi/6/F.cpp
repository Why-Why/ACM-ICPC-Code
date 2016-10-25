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
// Created Time  : 2016年09月16日 星期五 21时57分08秒
// File Name     : F.cpp

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

int N;
int A[100005];
int n0[23][23];

inline long long getans(int sta) {
	long long n[23]={};

	for(int i=19;i>=0;--i) {
		if(sta&(1<<i)) n[i]-=n0[i][i];
		else n[i]+=n0[i][i];

		for(int j=0;j<i;++j)
			if(((sta>>j)^(sta>>i))&1) n[j]-=n0[i][j];
			else n[j]+=n0[i][j];
	}

	long long ret=0,base=1;
	for(int i=0;i<20;++i,base<<=1)
		ret+=n[i]*base;
	return ret;
}

inline void solve(int a,int b) {
	if(a==b) return;

	int c=a^b,t=-1;
	for(int i=19;i>=0;--i)
		if(c&(1<<i)) {
			t=i;
			break;
		}

	for(int i=t;i>=0;--i)
		if((c&(1<<i)) && (a&(1<<i))) ++n0[t][i];
		else --n0[t][i];
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		memset(n0,0,sizeof(n0));

		scanf("%d",A+1);
		for(int i=2;i<=N;++i) {
			scanf("%d",A+i);
			solve(A[i],A[i-1]);
		}

		int x;
		long long ans=1000000000000000LL,t;
		for(int i=0;i<(1<<20);++i) {
			t=getans(i);
			if(t<ans) ans=t,x=i;
		}
		printf("%d %I64d\n",x,ans);
	}

	return 0;
}
