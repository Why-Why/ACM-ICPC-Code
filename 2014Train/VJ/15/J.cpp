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
// Created Time  : 2016年09月21日 星期三 12时45分28秒
// File Name     : J.cpp

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

const int MaxN=21;
const int mod=1000000007;

struct NUM {
	long long num,sum,sum2;

	NUM() {
		num=-1;
		sum=sum2=0;
	}

	NUM(long long a,long long b,long long c):num(a),sum(b),sum2(c) {}
};

NUM dp[MaxN][7][7];
int num[MaxN];

long long base10[MaxN];

NUM dfs(int pos,int smod,int cmod,bool lim) {
	if(pos<0) {
		if(smod && cmod) return NUM(1,0,0);
		return NUM(0,0,0);
	}
	if(!lim && dp[pos][smod][cmod].num!=-1) return dp[pos][smod][cmod];

	int u=lim ? num[pos] : 9;
	NUM ret(0,0,0),t;
	long long tt;

	for(int i=0;i<=u;++i)
		if(i!=7) {
			tt=i*base10[pos]%mod;

			t=dfs(pos-1,(smod+i)%7,(cmod*10+i)%7,lim && i==num[pos]);

			(ret.num+=t.num)%=mod;			// !!!
			(ret.sum+=((tt*t.num%mod)+t.sum)%mod)%=mod;
			(ret.sum2+=(t.sum2+2*tt%mod*t.sum%mod+tt*tt%mod*t.num%mod)%mod)%=mod;
		}

	if(!lim) dp[pos][smod][cmod]=ret;
	return ret;
}

long long getans(long long x) {
	int dep=0;
	for(;x;x/=10) num[dep++]=x%10;

	return dfs(dep-1,0,0,1).sum2;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	base10[0]=1;
	for(int i=1;i<MaxN;++i) base10[i]=base10[i-1]*10%mod;

	int T;
	long long L,R;
	scanf("%d",&T);

	while(T--) {
		scanf("%I64d %I64d",&L,&R);
		printf("%I64d\n",(getans(R)-getans(L-1)+mod)%mod);
	}

	return 0;
}
