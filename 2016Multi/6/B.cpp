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
// Created Time  : 2016年09月16日 星期五 20时42分15秒
// File Name     : B.cpp

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

const int mod=110119;

inline long long zhuan(long long x,long long y,long long & num) {
	if((x+y-2)%3) return -1;
	long long c=(x+y-2)/3;
	if(x<=c || x>c+c+1) return -1;

	num=x-c;
	return c;
}

long long jie[200000];

inline long long del(long long &a,long long b) {
	a-=b;
	if(a<0) a+=mod;
}

long long inv(long long a,long long m) {
	if(a==1) return 1;
	return inv(m%a,m)*(m-m/a)%m;
}

inline long long getC(long long n,long long m) {
	if(n<m) return 0;
	long long a=n%mod,b=m%mod;
	if(a<b) return 0;

	if(n==0 || m==0) return 1;

	return getC(n/mod,m/mod)*(jie[a]*inv(jie[b],mod)%mod*inv(jie[a-b],mod)%mod)%mod;
}

inline long long getnum(long long c1,long long n1,long long c2,long long n2) {
	long long dc=c2-c1;
	if(dc<0) return 0;
	if(n2<n1 || n2>n1+dc) return 0;

	c2=dc;
	n2=n2-n1;
	return getC(c2,n2);
}

typedef pair<long long,long long> pii;

pii rem[111];
int rcou;

long long n,m,r;
long long dp[111];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cas=1;

	jie[0]=1;
	for(int i=1;i<mod;++i) jie[i]=jie[i-1]*i%mod;

	long long a,b,c,num;

	while(~scanf("%I64d %I64d %I64d",&n,&m,&r)) {
		rcou=0;
		bool ok=0;

		while(r--) {
			scanf("%I64d %I64d",&a,&b);
			c=zhuan(a,b,num);
			if(c==-1) continue;

			if(a==n && b==m) ok=1;
			rem[++rcou]=pii(c,num);
		}
		sort(rem+1,rem+rcou+1);

		c=zhuan(n,m,num);

		if(ok || c==-1) {
			printf("Case #%d: 0\n",cas++);
			continue;
		}
		rem[++rcou]=pii(c,num);

		for(int i=1;i<=rcou;++i) {
			dp[i]=getnum(0,1,rem[i].first,rem[i].second);
			for(int j=1;j<i;++j)
				del(dp[i],dp[j]*getnum(rem[j].first,rem[j].second,rem[i].first,rem[i].second)%mod);
		}
		printf("Case #%d: %d\n",cas++,(int)dp[rcou]);
	}

	return 0;
}
