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
// Created Time  : 2017年02月14日 星期二 21时58分28秒
// File Name     : t.cpp

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

int edg[7][7];
int N;
int rem[10];

inline bool judge() {
	bool vis[10]={};
	for(int i=0;i<6;++i) vis[rem[i]]=1;
	for(int i=1;i<=N;++i)
		if(vis[i]==0) return 0;

	for(int i=0;i<5;++i)
		if(edg[rem[i]][rem[i+1]]==0) return 0;

	if(edg[rem[5]][rem[0]]==0) return 0;
	return 1;
}

set <int> rrr;

int cal() {
	int ret=0;
	for(int i=0;i<6;++i)
		ret=ret*10+rem[i];
	cout<<ret<<endl;
	return ret;
}

void dfs(int p) {
	if(p>=6) {
		if(judge()) rrr.insert(cal());
		return;
	}

	for(int i=1;i<=N;++i) {
		rem[p]=i;
		dfs(p+1);
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	N=5;
	edg[1][2]=edg[2][1]=1;
	edg[2][3]=edg[3][2]=1;
	edg[3][1]=edg[1][3]=1;
	edg[1][4]=edg[4][1]=1;
	edg[1][5]=edg[5][1]=1;
	edg[4][5]=edg[5][4]=1;

	//edg[1][2]=edg[2][1]=1;

	dfs(0);
	cout<<rrr.size()<<endl;

	return 0;
}
