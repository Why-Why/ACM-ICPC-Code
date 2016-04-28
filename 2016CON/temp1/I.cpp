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
// Created Time  : 2016年04月22日 星期五 20时30分01秒
// File Name     : I.cpp

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

const int mod=1000003;
const int MaxN=1005;

int N;
int cou[100];
long long ans[MaxN];

long long C[MaxN][MaxN];

void init() {
	for(int i=0;i<MaxN;++i) C[i][0]=1;
	for(int i=1;i<MaxN;++i)
		for(int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
}

inline void process(int x) {
	int t=0;
	while(x) {
		if(x&1) ++cou[t];
		++t;
		x>>=1;
	}
}

inline long long getnum(int x,int K) {
	long long ret=0;
	int y=N-x;
	for(int i=1;i<=K && i<=x;i+=2) {
		if(K-i>y) continue;
		(ret+=(C[x][i]*C[y][K-i])%mod)%=mod;
	}
	return ret;
}

inline void getans(int p,int K) {
	long long base=1LL<<p;
	base%=mod;

	(ans[K]+=(base*getnum(cou[p],K))%mod)%=mod;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a;

	init();

	while(~scanf("%d",&N)) {
		memset(cou,0,sizeof(cou));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=N;++i) {
			scanf("%d",&a);
			process(a);
		}

		for(int i=0;i<31;++i)
			for(int j=1;j<=N;++j)
				getans(i,j);

		printf("%I64d",ans[1]);
		for(int i=2;i<=N;++i)
			printf(" %I64d",ans[i]);
		puts("");
	}
	
	return 0;
}
