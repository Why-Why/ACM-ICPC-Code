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
// Created Time  : 2016年07月15日 星期五 19时35分21秒
// File Name     : E.cpp

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

struct Mat {
	long long num[2][2];

	Mat() {
		num[0][0]=num[1][1]=1;
		num[0][1]=num[1][0]=0;
	}

	Mat operator * (const Mat & b) const {
		Mat ret;
		ret.num[0][0]=(num[0][0]*b.num[0][0]%mod+num[0][1]*b.num[1][0]%mod);
		ret.num[0][1]=(num[0][0]*b.num[0][1]%mod+num[0][1]*b.num[1][1]%mod);
		ret.num[1][0]=(num[1][0]*b.num[0][0]%mod+num[1][1]*b.num[1][0]%mod);
		ret.num[1][1]=(num[1][0]*b.num[0][1]%mod+num[1][1]*b.num[1][1]%mod);
		if(ret.num[0][0]>=mod) ret.num[0][0]-=mod;
		if(ret.num[0][1]>=mod) ret.num[0][1]-=mod;
		if(ret.num[1][0]>=mod) ret.num[1][0]-=mod;
		if(ret.num[1][1]>=mod) ret.num[1][1]-=mod;
		return ret;
	}
};

long long K;

inline void pow1(Mat & x,long long & y,long long K) {
	Mat ans,base;
	long long ans1=1,base1=y;

	base=x;

	while(K) {
		if(K&1) ans=ans*base,(ans1*=base1)%=mod;
		base=base*base;
		(base1*=base1)%=mod;
		K>>=1;
	}

	x=ans;
	y=ans1;
}

const int ni=(mod+1)/2;

inline long long read() {
	int c;
	long long ret=0;

	if(c=getchar(),c==-1) return 0;
	while(c<'0' || c>'9') c=getchar();
	ret=c-'0';
	while(c=getchar(),c>='0' && c<='9') ret=ret*10+(c-'0');

	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;
	Mat ans1;
	long long ans2=2;

	ans1.num[0][0]=ans1.num[1][0]=1;
	ans1.num[0][1]=2;
	ans1.num[1][1]=0;

	N=read();
	while(N--) {
		K=read();
		pow1(ans1,ans2,K);
	}

	long long s,x;

	s=((ans1.num[0][0]-ans1.num[1][0])%mod+mod)%mod*ni%mod;
	x=ans2*ni%mod;
	cout<<s<<'/'<<x<<endl;

	return 0;
}
