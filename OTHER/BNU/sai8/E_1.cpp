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
// Created Time  : 2016年10月07日 星期五 13时50分42秒
// File Name     : E_1.cpp

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

const int MaxN=103;

int id[MaxN],cou;
long long val[MaxN];
int n,m,k,T;

struct OPE {
	int t,a,b;
}ope[MaxN];

inline void solve() {
	for(int i=1;i<=k;++i)
		if(ope[i].t==1)
			++val[ope[i].a];
		else if(ope[i].t==2)
			val[ope[i].a]=0;
		else {
			swap(val[ope[i].a],val[ope[i].b]);
			if(ope[i].a!=ope[i].b) {
				if(id[ope[i].a]==ope[i].a) ++cou;
				if(id[ope[i].a]==ope[i].b) --cou;
				if(id[ope[i].b]==ope[i].b) ++cou;
				if(id[ope[i].b]==ope[i].a) --cou;
				swap(id[ope[i].a],id[ope[i].b]);
			}
		}

	//for(int i=1;i<=n;++i) cout<<id[i]<<' ';
	//cout<<endl<<cou<<endl;
}

long long tval[MaxN];

inline void solve(long long val[]) {
	for(int i=1;i<=k;++i)
		if(ope[i].t==1) ++val[ope[i].a];
		else if(ope[i].t==2) val[ope[i].a]=0;
		else swap(val[ope[i].a],val[ope[i].b]);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char s[10];

	while(~scanf("%d %d %d",&n,&m,&k) && n+m+k) {
		for(int i=1;i<=n;++i) id[i]=i,val[i]=tval[i]=0;
		cou=0;

		for(int i=1;i<=k;++i) {
			scanf("%s %d",s,&ope[i].a);
			if(s[0]=='g') ope[i].t=1;
			else if(s[0]=='e') ope[i].t=2;
			else {
				ope[i].t=3;
				scanf("%d",&ope[i].b);
			}
		}

		for(T=1;;++T) {
			solve();
			if(cou==0) break;
		}
		for(int i=1;i<=n;++i) tval[i]=val[i];
		for(int i=1;i<=T;++i) solve(val);

		int d=m/T,r=m%T;

		if(d) for(int i=1;i<=n;++i) val[i]=tval[i]+(val[i]-tval[i])*(d-1);
		else for(int i=1;i<=n;++i) val[i]=0;
		while(r--) solve(val);

		for(int i=1;i<n;++i) printf("%lld ",val[i]);
		printf("%lld\n",val[n]);
	}

	return 0;
}
