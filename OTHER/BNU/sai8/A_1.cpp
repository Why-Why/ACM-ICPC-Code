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
// Created Time  : 2016年10月07日 星期五 23时59分49秒
// File Name     : A_1.cpp

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

const int mod=100000007;
const int maxn=2003;

long long c[maxn][maxn];

inline void add(long long & a,long long b) {
	a+=b;
	if(a>=mod) a-=mod;
}

inline long long C(int a,int b) {
	return c[a][b];
}

inline int getans(int X,int Y,int x,int y) {
	if(x==0) return 1;

	int a=x,b=Y-y,c=X-x,d=y;
	int minn=min(min(a,b),min(c,d));
	long long ret=0;

	for(int i=1;i<=minn;++i) {
		add(ret,C(a-1,i-1)*C(b,i)%mod*C(c,i)%mod*C(d,i)%mod);
		add(ret,C(a-1,i)*C(b,i)%mod*C(c,i)%mod*C(d,i)%mod);
		add(ret,C(a-1,i)*C(b,i+1)%mod*C(c,i)%mod*C(d,i)%mod);
		add(ret,C(a-1,i)*C(b,i+1)%mod*C(c,i+1)%mod*C(d,i)%mod);
	}

	add(ret,1);
	add(ret,b);
	add(ret,b*c%mod);

	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	for(int i=0;i<maxn;++i) c[i][0]=1;
	for(int i=1;i<maxn;++i)
		for(int j=1;j<=i;++j)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;

	int N,a,b,c,d;
	scanf("%d",&N);

	while(N--) {
		scanf("%d %d %d %d",&a,&b,&c,&d);
		printf("%d\n",getans(a,b,c,d));
	}

	return 0;
}
