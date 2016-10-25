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
// Created Time  : 2016年08月18日 星期四 12时05分37秒
// File Name     : 1001.cpp

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

int N;
long long num[MaxN];

int M,a,b,c,d,s;

inline long long read() {
	char c; int sgn;
	if(c=getchar(),c==EOF) return 0; //EOF
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	sgn=(c=='-')?-1:1;
	long long ret=(c=='-')?0:(c-'0');
	while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
	ret*=sgn;
	return ret;
}

inline long long getnum(int k) {
	if(a>c) swap(a,c),swap(b,d);

	if(c>b) {
		if(b-a+1>=k) return num[a+k-1];
		k-=b-a+1;
		return num[c+k-1];
	}

	if(d<=b) {
		if(k<=c-a) return num[a+k-1];
		k-=c-a;
		if(k<=2*(d-c+1)) return num[c+(k+1)/2-1];
		k-=2*(d-c+1);
		return num[d+k];
	}

	if(k<=c-a) return num[a+k-1];
	k-=c-a;
	if(k<=2*(b-c+1)) return num[c+(k+1)/2-1];
	k-=2*(b-c+1);
	return num[b+k];
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	double ans;
	T=read();

	while(T--) {
		N=read(); M=read();
		for(int i=1;i<=N;++i) num[i]=read();

		while(M--) {
			a=read(); b=read();
			c=read(); d=read();
			s=b-a+1+d-c+1;

			if(s&1) ans=getnum((s+1)>>1);
			else ans=(getnum(s>>1)+0.0+getnum((s>>1)+1))/2.0;
			printf("%.1f\n",ans);
		}
	}

	return 0;
}
