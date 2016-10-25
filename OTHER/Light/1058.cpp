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
// Created Time  : 2016年08月30日 星期二 23时45分31秒
// File Name     : 1058.cpp

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

struct Edge;

inline int cmp1(const Edge & a,const Edge & b);
inline int cmp2(const Edge & a,const Edge & b);
inline int cmp3(const Edge & a,const Edge & b);

struct Edge {
	int dy,dx,x,y;

	bool operator < (const Edge & b) const {
		int t=cmp1(*this,b);
		if(t) return t==-1;

		t=cmp2(*this,b);
		if(t) return t==-1;

		t=cmp3(*this,b);
		return t==-1;
	}

	bool equal1(const Edge & b) const {
		if(cmp1(*this,b)==0 && cmp2(*this,b)==0) return 1;
		return 0;
	}

	bool equal2(const Edge & b) const {
		if(this->equal1(b) && cmp3(*this,b)==0) return 1;
		return 0;
	}
};

inline int cmp1(const Edge & a,const Edge & b) {
	long long t=(a.dx+0LL)*(b.dy+0LL)-(a.dy+0LL)*(b.dx+0LL);
	if(t<0) return -1;
	return t>0 ? 1 : 0;
}

inline int cmp2(const Edge & a,const Edge & b) {
	long long t=(a.dx+0LL)*(a.dx+0LL)+(a.dy+0LL)*(a.dy+0LL)-(b.dx+0LL)*(b.dx+0LL)-(b.dy+0LL)*(b.dy+0LL);
	if(t<0) return -1;
	return t>0 ? 1 : 0;
}

inline int cmp3(const Edge & a,const Edge & b) {
	long long dx=b.x-a.x,dy=b.y-a.y;
	long long t=dx*(a.dy+0LL)-dy*(a.dx+0LL);
	if(t<0) return -1;
	return t>0 ? 1 : 0;
}

Edge E[1000005];
int Ecou;

int N,x[1003],y[1003];

inline void add(int a,int b) {
	if(x[a]==x[b] && y[a]==y[b]) return;

	++Ecou;
	E[Ecou].dx=x[a]-x[b];
	E[Ecou].dy=y[a]-y[b];
	if(E[Ecou].dx<0) {
		E[Ecou].dx=-E[Ecou].dx;
		E[Ecou].dy=-E[Ecou].dy;
	}

	if(x[a]<x[b]) {
		E[Ecou].x=x[a];
		E[Ecou].y=y[a];
	}
	else if(x[a]>x[b]) {
		E[Ecou].x=x[b];
		E[Ecou].y=y[b];
	}
	else {
		E[Ecou].x=x[a];
		E[Ecou].y=min(y[a],y[b]);
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		Ecou=0;
		for(int i=1;i<=N;++i) scanf("%d %d",x+i,y+i);
		for(int i=1;i<=N;++i)
			for(int j=i+1;j<=N;++j)
				add(i,j);

		sort(E+1,E+Ecou+1);

		long long ans=0;

		long long cou=1;
		for(int i=2;i<=Ecou;++i)
			if(E[i].equal1(E[i-1])) ++cou;
			else {
				ans+=cou*(cou-1LL)/2LL;
				cou=1;
			}
		ans+=cou*(cou-1LL)/2LL;

		cou=1;
		for(int i=2;i<=Ecou;++i)
			if(E[i].equal2(E[i-1])) ++cou;
			else {
				ans-=cou*(cou-1LL)/2LL;
				cou=1;
			}

		ans/=2LL;
		printf("Case %d: %lld\n",cas++,ans);
	}

	return 0;
}
