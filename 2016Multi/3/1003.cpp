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
// Created Time  : 2016年07月26日 星期二 13时27分31秒
// File Name     : 1003.cpp

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

int N,M,type;

const int step[3][2]={{0,1},{1,0},{1,1}};

inline int getval1(int ans[MaxN][MaxN],int i,int j) {
	int nx,ny;

	for(int k=0;k<3;++k) {
		nx=i+step[k][0];
		ny=j+step[k][1];
		if(nx<=N && ny<=M)
			if(ans[nx][ny]==0) return 1;
	}

	return 0;
}

const int step1[][2]={{1,2},{2,1}};

inline int getval3(int ans[MaxN][MaxN],int i,int j) {
	int nx,ny;
	bool ok=0,ook=0;

	for(int k=0;k<2;++k) {
		nx=i+step1[k][0];
		ny=j+step1[k][1];

		if(nx<=N && ny<=M) {
			ook=1;
			if(ans[nx][ny]==0)
				return 1;
			else if(ans[nx][ny]==-1) ok=1;
		}
	}

	if(!ook) return -1;
	if(ok) return -1;
	return 0;
}

void getval1(int ans[MaxN][MaxN]) { 
	ans[N][M]=0;
	for(int i=N;i>=1;--i)
		for(int j=M;j>=1;--j)
			ans[i][j]=getval1(ans,i,j);
}

void getval2(int ans[MaxN][MaxN]) {
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			ans[i][j]=1;

	for(int i=N,j=M;i>=1 && j>=1;--i,--j)
		ans[i][j]=0;
}

void getval3(int ans[MaxN][MaxN]) { 
	ans[N][M]=0;
	for(int i=N;i>=1;--i)
		for(int j=M;j>=1;--j)
			if(i!=N || j!=M)
				ans[i][j]=getval3(ans,i,j);
}

bool vis1[2005],vis2[2005],vis3[2005];
int rem[MaxN];

void getval4(int ans[MaxN][MaxN]) {
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j) ans[i][j]=1;
	ans[N][M]=0;

	vis1[N]=vis2[M]=vis3[N-M+1000]=1;
	rem[M]=N;

	int num[5],ncou,t;

	for(int i=M-1;i>=1;--i) {
		ncou=0;

		if(i+1<=M) num[ncou++]=rem[i+1]-2;
		if(i+2<=M) num[ncou++]=rem[i+2]-1,num[ncou++]=rem[i+2]-3;
		if(i+3<=M) num[ncou++]=rem[i+3]-2;

		t=-1;
		sort(num,num+ncou,greater<int>());
		for(int j=0;j<ncou;++j) {
			if(num[j]>0 && vis1[num[j]]==0 && vis3[num[j]-i+1000]==0) {
				t=num[j];
				break;
			}
		}
		if(t==-1) break;

		rem[i]=t;
		vis1[t]=vis3[t-i+1000]=1;

		ans[t][i]=0;
	}

	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			if(ans[i][j]==0 || ans[j][i]==0) ans[i][j]=ans[j][i]=0;
}

int ans[4][MaxN][MaxN];

inline void init() {
	memset(ans,-1,sizeof(ans));

	getval1(ans[0]);
	getval2(ans[1]);
	getval3(ans[2]);
	getval4(ans[3]);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	N=M=1000;
	init();

	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d %d",&type,&N,&M);
		int t=ans[type-1][1001-N][1001-M];
		if(t==-1) puts("D");
		else if(t) puts("B");
		else puts("G");
	}

	return 0;
}
