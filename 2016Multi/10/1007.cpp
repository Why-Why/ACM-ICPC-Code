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
// Created Time  : 2016年08月31日 星期三 18时29分35秒
// File Name     : 1007.cpp

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

int N,M,K;

struct Mat {
	long long num[13][13];

	Mat operator * (const Mat & b) const {
		Mat ret;
		long long t;

		for(int i=0;i<=M;++i)
			for(int j=0;j<=M;++j) {
				t=0;
				for(int k=0;k<=M;++k) (t+=(num[i][k]*b.num[k][j])%mod)%=mod;
				ret.num[i][j]=t;
			}

		return ret;
	}

	void show() {
		cout<<"$$$$$\n";
		for(int i=0;i<=M;++i,cout<<endl)
			for(int j=0;j<=M;++j)
				cout<<num[i][j]<<' ';
	}
};

long long getans() {
	Mat base,ret;

	for(int i=0;i<=M;++i)
		for(int j=0;j<=M;++j) base.num[i][j]=0,ret.num[i][j]=0;
	for(int i=0;i<=M;++i) base.num[0][i]=K*(K-1),ret.num[i][i]=1;
	for(int i=1;i<=M;++i) base.num[i][i-1]=K;

	for(int n=N;n;n>>=1,base=base*base)
		if(n&1)
			ret=ret*base;

	long long ans=0;
	for(int i=0;i<=M;++i)
		(ans+=ret.num[i][0])%=mod;
	return ans;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d %d",&N,&M,&K);
		long long ans=getans();
		--M;
		ans-=getans();
		if(ans<0) ans+=mod;
		printf("%d\n",(int)ans);
	}

	return 0;
}
