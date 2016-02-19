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
// Created Time  : 2015年12月25日 星期五 20时31分26秒
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
const int mod=1000000007;

int N;
long long sum[MaxN];
long long A[MaxN];
long long f[MaxN],d[MaxN];
long long jie[MaxN];

void init() {
	jie[0]=1;
	for(int i=1;i<MaxN;++i)
		jie[i]=(jie[i-1]*i)%mod;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	scanf("%d",&N);
	int a;
	for(int i=1;i<=N;++i) {
		scanf("%d",&a);
		++sum[a];
	}

	A[0]=sum[0];
	for(int i=1;i<=N;++i)
		A[i]=((A[i-1]+sum[i]-1)%mod+mod)%mod;

	long long temp=A[0];
	f[0]=jie[N];
	for(int i=1;i<=N;++i) {
		f[i]=(jie[N-i]*temp)%mod;
		(temp*=A[i])%=mod;
	}

	long long ans=0;

	for(int i=1;i<=N+1;++i) {
		d[i]=((f[i-1]-f[i])%mod+mod)%mod;
		(ans+=(d[i]*(i-1))%mod)%=mod;
	}
	printf("%d\n",(int)ans);

	
	return 0;
}
