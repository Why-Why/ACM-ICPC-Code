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
// Created Time  : 2017年03月03日 星期五 15时00分56秒
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

const int MaxN=50003;
const int mod=1000000007;

int N,K;
char s[MaxN];
long long num[MaxN][103];

long long sum[MaxN];

long long C[103][103],POW[1001][103];

inline void add(long long &a,long long b) {
	a+=b;
	if(a>=mod) a-=mod;
}

inline long long cal(long long K,long long d,long long f[],int L,int R) {
	long long ret=0;

	for(long long j=0,base=1;j<=K;++j,(base*=d)%=mod)
		add(ret,C[K][j]*base%mod*f[K-j]%mod);

	for(int i=L;i<=R;++i) {
		d=sum[R]-sum[i-1];
		add(ret,POW[d][K]);
	}

	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	for(int i=0;i<103;++i) C[i][0]=1;
	for(int i=1;i<103;++i)
		for(int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;

	for(int i=0;i<1001;++i) {
		POW[i][0]=1;
		for(int j=1;j<103;++j) POW[i][j]=POW[i][j-1]*i%mod;
	}

	int T;
	long long t,d,*f,ans;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&K);
		scanf("%s",s+1);

		if(K==0) {
			printf("1");
			for(int i=2;i<=N;++i) printf(" %d",i);
			puts("");
			continue;
		}

		sum[0]=0;
		for(int i=1;i<=N;++i) sum[i]=sum[i-1]+s[i]-'0';

		for(int i=0;i<=K;++i) num[0][i]=0;

		for(int i=1;i<=N;++i) {
			t=((i-1)/K)*K;
			d=sum[i]-sum[t];

			ans=cal(K,d,num[t],t+1,i);

			if(i%K==0) {
				f=num[i];
				f[K]=ans;
				f[0]=i;
				for(int j=1;j<K;++j) f[j]=cal(j,d,num[t],t+1,i);
			}

			if(i>1) putchar(' ');
			printf("%lld",ans);
		}
		puts("");
	}

	return 0;
}
