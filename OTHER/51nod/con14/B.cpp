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
// Created Time  : 2016年05月27日 星期五 20时50分01秒
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

bool vis[1000005];
int fac[1000005][11][2],fcou[1000005];
long long A[1000005];

inline long long read() {
	long long ret=0;
	char ch=getchar();
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret;
}

void init() {
	for(int i=2;i<=1000000;++i)
		if(vis[i]==0) {
			for(int j=i;j<=1000000;j+=i) {
				vis[j]=1;
				fac[j][fcou[j]++][1]=i;
			}
		}

	int t,tt;

	for(int i=2;i<=1000000;++i) {
		for(int j=0;j<fcou[i];++j) {
			t=fac[i][j][1];
			tt=i;
			while(tt%t==0) ++fac[i][j][0];
		}
	}
}

inline long long getans(long long x) {
	int cou=1;
	for(int i=0;i<fcou[x];++i) cou*=fac[x][i][0]+1;
	long long ret=0;
	for(int i=0;i<fcou[x];++i) ret+=A[fac[x][i][1]]*(cou-cou/(fac[x][i][0]+1));
	ret+=A[1]*cou;
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long n,q;
	long long a,b,c;

	init();
	cerr<<"gasdg";

	n=read();
	q=read();

	while(q--) {
		a=read();
		b=read();

		if(a==1) {
			c=read();
			A[b]+=c;
		}
		else printf("%lld\n",getans(b));
	}
	
	return 0;
}
