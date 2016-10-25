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
// Created Time  : 2016年07月15日 星期五 17时15分47秒
// File Name     : C.cpp

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

const int MaxN=1005;

struct REM {
	long long u,v;
	long long w;

	REM() {}
	REM(long long a,long long b,long long c):u(a),v(b),w(c) {}
};

REM rem[MaxN<<1];
int cou;

inline long long ceng(long long x) {
	long long ret=0;
	while(x) {
		++ret;
		x>>=1;
	}
	return ret;
}

inline long long lca(long long u,long long v) {
	if(u>v) swap(u,v);
	int t=ceng(v)-ceng(u);
	v>>=t;
	for(int i=0;i<64;++i)
		if((u>>i)==(v>>i)) return u>>i;
}

long long getans(long long u,long long v) {
	long long t,ans=0;

	for(int i=0;i<cou;++i) {
		t=lca(rem[i].u,u);
		t=ceng(t)-max(ceng(rem[i].v),ceng(v));
		if(t<0) t=0;

		ans+=t*rem[i].w;
	}

	return ans;
}

long long getans() {
	long long u,v,e;
	cin>>u>>v;
	e=lca(u,v);

	return getans(u,e)+getans(v,e);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long a,b,c,d,e;
	int N;

	cin>>N;
	for(int i=1;i<=N;++i) {
		cin>>a;
		if(a==1) {
			cin>>b>>c>>d;
			e=lca(b,c);

			rem[cou++]=REM(b,e,d);
			rem[cou++]=REM(c,e,d);
		}
		else cout<<getans()<<endl;
	}

	return 0;
}
