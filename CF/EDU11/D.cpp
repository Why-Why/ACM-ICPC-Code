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
// Created Time  : 2016年04月09日 星期六 00时03分27秒
// File Name     : D.cpp

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

const int MaxN=2005;
const double eps=1e-8;

int X[MaxN],Y[MaxN];

inline int sgn(double x) {
	return x<-eps ? -1 : x>eps;
}

struct State {
	long double dist;
	long long x,y;

	bool operator < (const State & b) const {
		if(dist==b.dist) return y*b.x<b.y*x;
		return sgn(dist-b.dist)<0;
	}
	bool operator == (const State &b) const {
		return sgn(dist-b.dist)==0 && y*b.x==x*b.y;
	}
}sta[MaxN*MaxN];

int N;
int cou=0;

inline long double dist(int a,int b) {
	long double dx=X[a]-X[b],dy=Y[a]-Y[b];
	return dx*dx+dy*dy;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<=N;++i) {
		scanf("%d %d",X+i,Y+i);
		for(int j=1;j<i;++j) {
			sta[cou].dist=dist(i,j);
			sta[cou].x=X[i]-X[j];
			sta[cou].y=Y[i]-Y[j];
			if(sta[cou].x<0) sta[cou].x=-sta[cou].x,sta[cou].y=-sta[cou].y;
			else if(sta[cou].x==0) sta[cou].y=abs(sta[cou].y);
			++cou;
		}
	}
	sort(sta,sta+cou);

	long long ans=0;
	int ttt=1;
	for(int i=1;i<=cou;++i) {
		if(i==cou || !(sta[i]==sta[i-1])) {
			ans+=ttt*(ttt-1LL)/2;
			ttt=1;
		}
		else ++ttt;
	}

	cout<<ans/2<<endl;
	
	return 0;
}
