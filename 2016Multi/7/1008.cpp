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
// Created Time  : 2016年08月09日 星期二 14时56分39秒
// File Name     : 1008.cpp

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

int P,N,M;
int X[23];

long long shang[23];
long long jie[23];
long long C[23][23];

int cou1[(1<<20)+5],sum[(1<<20)+5];

long long pu[23][23];
long long tpu[]={1,1,0,1,1,0,1,2,1,0,0,2,3,1,0,0,2,5,4,1,0,0,0,5,9,5,1,0,0,0,5,14,14,6,1,0,0,0,0,14,28,20,7,1,0,0,0,0,14,42,48,27,8,1,0,0,0,0,0,42,90,75,35,9,1,0,0,0,0,0,42,132,165,110,44,10,1,0,0,0,0,0,0,132,297,275,154,54,11,1,0,0,0,0,0,0,132,429,572,429,208,65,12,1,0,0,0,0,0,0,0,429,1001,1001,637,273,77,13,1,0,0,0,0,0,0,0,429,1430,2002,1638,910,350,90,14,1,0,0,0,0,0,0,0,0,1430,3432,3640,2548,1260,440,104,15,1,0,0,0,0,0,0,0,0,1430,4862,7072,6188,3808,1700,544,119,16,1,0,0,0,0,0,0,0,0,0,4862,11934,13260,9996,5508,2244,663,135,17,1,0,0,0,0,0,0,0,0,0,4862,16796,25194,23256,15504,7752,2907,798,152,18,1,0,0,0,0,0,0,0,0,0,0,16796,41990,48450,38760,23256,10659,3705,950,170,19,1};

inline bool judge(int S,int sta) {
	int have=0,zhong=1;

	for(int i=1;i<=S;) {
		if(zhong>=S) return 1;
		have=0;
		for(;i<=zhong;++i) if(sta&(1<<(i-1))) ++have;

		if(have) zhong+=2*have;
		else return 0;
	}

	if(zhong>=S) return 1;
	return 0;
}

void dfs(int S,int p,int A,int a,int sta) {
	if(a>=A) {
		if(judge(S,sta)) ++pu[S][A];
		return;
	}
	if(p>S) return;

	dfs(S,p+1,A,a+1,sta|(1<<(p-1)));
	dfs(S,p+1,A,a,sta);
}

long long getpu(int S,int A) {
	pu[S][A]=0;
	dfs(S,1,A,0,0);
	return pu[S][A];
}

void init() {
	jie[0]=1;
	for(int i=1;i<=20;++i)
		jie[i]=jie[i-1]*i;

	for(int i=0;i<=20;++i) C[i][0]=1;
	for(int i=1;i<=20;++i)
		for(int j=1;j<=i;++j)
			C[i][j]=C[i-1][j]+C[i-1][j-1];

	int cou=0;
	for(int i=1;i<=20;++i)
		for(int j=0;j<=i;++j)
			pu[i][j]=tpu[cou++];
}

long long gcd(long long a,long long b) {
	if(!a) return b;
	return gcd(b%a,a);
}

inline long long getnum(int S,int A,int B) {
	return jie[A]*pu[S][A]*shang[B]*jie[B];
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	int T,t;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d %d",&P,&N,&M);
		for(int i=1;i<=M;++i) scanf("%d",X+i);
		memset(shang,0,sizeof(shang));

		cou1[0]=0;
		sum[0]=0;
		for(int i=1;i<=M;++i) sum[1<<(i-1)]=X[i];
		for(int i=1;i<(1<<M);++i) {
			t=i-(i&(-i));
			cou1[i]=cou1[t]+1;
			sum[i]=sum[t]+sum[i&(-i)];

			if(sum[i]>=P) ++shang[cou1[i]];
		}

		long long A=0,B=jie[N+M],tt;
		for(int i=0;i<=N;++i) {
			t=min(N+M,1+i*2);
			A+=C[N][i]*getnum(t,i,t-i)*jie[N+M-t];
		}

		tt=gcd(A,B);
		printf("%I64d/%I64d\n",A/tt,B/tt);
	}

	return 0;
}
