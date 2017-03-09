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
// Created Time  : 2017年02月23日 星期四 15时50分11秒
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

long long gcd(long long a,long long b,long long &x,long long &y) {
	if(a==0 && b==0) return -1;
	if(b==0) { x=1; y=0; return a; }
	long long d=gcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

inline long long mul(long long a,long long b,long long m) {			// !!!
	long long ret=0;
	if(b<0) b=-b,a=-a;
	for(;b;b>>=1,a=(a+a)%m)
		if(b&1) ret=(ret+a)%m;
	return ret;
}

struct State {
	long long a,b;

	State() {}
	State(long long a,long long b):a(a),b(b) {}

	State operator + (const State & sec) const {
		if(a==-1 || sec.a==-1) return State(-1,0);

		long long da=sec.a-a;
		long long b1=b,b2=-sec.b;
		long long t,x,y,k;

		t=gcd(b1,b2,x,y);
		if(da%t) return State(-1,0);
		k=da/t;

		State ret;

		ret.b=abs(b1/t*b2);
		//ret.a=(a%ret.b+x*b1%ret.b*k%ret.b)%ret.b;
		ret.a=(a%ret.b+mul(mul(x,b,ret.b),k,ret.b))%ret.b;

		da=max(a,sec.a);
		if(ret.a>da) ret.a-=((ret.a-da)/ret.b)*ret.b;
		else ret.a+=((da-ret.a+ret.b-1)/ret.b)*ret.b;

		return ret;
	}
};

//////////////////

const int MaxN=203;

State dp[MaxN][MaxN][9][9];
int logN[MaxN];

int N,M;

void init() {
	logN[0]=-1;
	for(int i=1;i<MaxN;++i) logN[i]=((i&(i-1))==0) ? logN[i-1]+1 : logN[i-1];

	for(int ii=0;ii<=logN[N];++ii)
		for(int jj=0;jj<=logN[M];++jj)
			if(ii+jj)
				for(int i=1;i+(1<<ii)-1<=N;++i)
					for(int j=1;j+(1<<jj)-1<=M;++j)
						if(ii)
							dp[i][j][ii][jj]=dp[i][j][ii-1][jj]+dp[i+(1<<(ii-1))][j][ii-1][jj];
						else
							dp[i][j][ii][jj]=dp[i][j][ii][jj-1]+dp[i][j+(1<<(jj-1))][ii][jj-1];
}

long long RMQ(int x1,int y1,int x2,int y2) {
	int k1=logN[x2-x1+1],k2=logN[y2-y1+1];

	x2=x2-(1<<k1)+1;
	y2=y2-(1<<k2)+1;

	return (dp[x1][y1][k1][k2]+dp[x1][y2][k1][k2]+dp[x2][y1][k1][k2]+dp[x2][y2][k1][k2]).a;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int Q,x1,x2,y1,y2;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&M);
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
				scanf("%I64d",&dp[i][j][0][0].a);
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
				scanf("%I64d",&dp[i][j][0][0].b);

		init();

		printf("Case #%d:\n",cas++);

		scanf("%d",&Q);
		while(Q--) {
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			printf("%I64d\n",RMQ(x1,y1,x2,y2));
		}
	}

	return 0;
}
