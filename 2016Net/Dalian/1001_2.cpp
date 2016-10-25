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
// Created Time  : 2016年09月10日 星期六 16时02分03秒
// File Name     : 1001_2.cpp

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

const int mod=1000000007;

int N;

long long inv(long long a,long long m) {
	if(a == 1)return 1;
	return inv(m%a,m)*(m-m/a)%m;
}

long long eular(long long n) {
	long long ans = n;
	for(long long i = 2;i*i <= n;i++) {
		if(n % i == 0) {
			ans -= ans/i;
			while(n % i == 0) n /= i;
		}
	}
	if(n > 1)ans -= ans/n;
	return ans;
}

struct Mat {
	long long num[2][2];

	Mat operator * (const Mat & b) const {
		Mat ret;
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j) {
				ret.num[i][j]=0;
				for(int k=0;k<2;++k)
					(ret.num[i][j]+=num[i][k]*b.num[k][j]%mod)%=mod;
			}
		return ret;
	}
};

inline long long getF(int d) {
	Mat base;
	base.num[0][0]=0;
	base.num[1][1]=base.num[0][1]=base.num[1][0]=1;

	Mat ret;
	ret.num[0][0]=ret.num[1][1]=1;
	ret.num[0][1]=ret.num[1][0]=0;

	--d;

	for(;d;d>>=1) {
		if(d&1) ret=ret*base;
		base=base*base;
	}

	return (2*ret.num[0][1]+ret.num[1][1])%mod;
}

inline long long getnum(int i) {
	return eular(N/i)*getF(i)%mod;
}

long long getans(int N) {
	long long ret=0;

	for(long long i=1;i*i<=N;++i)
		if(N%i==0) {
			(ret+=getnum(i))%=mod;
			if(N/i!=i) (ret+=getnum(N/i))%=mod;
		}

	return ret*inv(N,mod)%mod;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N)) {
		if(N==1) puts("2");
		else printf("%d\n",(int)getans(N));
	}

	return 0;
}
