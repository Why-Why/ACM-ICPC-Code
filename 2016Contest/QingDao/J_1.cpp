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
// Created Time  : 2017年03月01日 星期三 21时30分14秒
// File Name     : J_1.cpp

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

inline int read() {
	char c=0;
	while(c<'0' || c>'9') c=getchar();
	int ret=c-'0';
	while(c=getchar(),c>='0' && c<='9') ret=ret*10+c-'0';
	return ret;
}

/////////////////////////////

int N;
bool map1[103][103];
int ans;

struct State {
	int a[2000],b[2000],c[2000];
	int top;

	void init() {
		top=0;
	}

	int size() {
		return top;
	}

	void get(int &x,int &y,int &z) {
		x=a[top-1];
		y=b[top-1];
		z=c[top-1];
	}

	void insert(int x,int y,int z) {
		a[top]=x;
		b[top]=y;
		c[top]=z;
		++top;
	}

}sta[13];

inline bool judge(int a,int b,int c) {
	return map1[a][b]+map1[a][c]+map1[b][c]==2;
}

inline bool in(int t,int a,int b,int c) {
	if(t==a) return 1;
	if(t==b) return 1;
	if(t==c) return 1;
	return 0;
}

void dfs(int);

inline void solve(int a,int b,int dep) {
	map1[a][b]=!map1[a][b];
	map1[b][a]=!map1[b][a];

	sta[dep+1].init();

	for(int i=0;i<sta[dep].top;++i)
		if(!in(a,sta[dep].a[i],sta[dep].b[i],sta[dep].c[i]) || !in(b,sta[dep].a[i],sta[dep].b[i],sta[dep].c[i]))
			sta[dep+1].insert(sta[dep].a[i],sta[dep].b[i],sta[dep].c[i]);

	for(int i=1;i<=N;++i)
		if(i!=a && i!=b && judge(a,b,i))
			sta[dep+1].insert(a,b,i);

	dfs(dep+1);

	map1[a][b]=!map1[a][b];
	map1[b][a]=!map1[b][a];
}

void dfs(int dep) {
	if(dep>=ans) return;
	if(sta[dep].size()==0) {
		ans=dep;
		return;
	}
	if(dep>=10) return;
	if(sta[dep].size()>(10-dep)*N) return;

	int a,b,c;
	sta[dep].get(a,b,c);

	solve(a,b,dep);
	solve(a,c,dep);
	solve(b,c,dep);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	T=read();

	while(T--) {
		N=read();
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				map1[i][j]=read();

		sta[0].init();

		for(int i=1;i<=N;++i)
			for(int j=i+1;j<=N;++j)
				for(int k=j+1;k<=N;++k)
					if(judge(i,j,k))
						sta[0].insert(i,j,k);

		ans=100;
		if(sta[0].size()<=10*N) dfs(0);
		if(ans>10) ans=-1;

		printf("Case #%d: %d\n",cas++,ans);
	}

	return 0;
}
