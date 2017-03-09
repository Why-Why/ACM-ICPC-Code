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
// Created Time  : 2017年02月03日 星期五 19时57分31秒
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

const int MaxN=33;

struct Edge {
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
int du[MaxN];

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v) {
	++du[v];
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int N;
//int rx1[MaxN],ry1[MaxN],rx2[MaxN],ry2[MaxN];
int fan[]={2,3,0,1,4};
int step[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

long long ax[MaxN],ay[MaxN];

/*
inline void zhuan1(int p,int f,int &x,int &y) {
	switch(f) {
		case 0:
			x=1,y=ry1[p];
			break;
		case 1:
			x=rx1[p],y=1;
			break;
		case 2:
			x=rx1[p]-rx2[p]-1,y=ry1[p];
			break;
		case 3:
			x=rx1[p],y=ry1[p]-ry2[p]-1;
			break;
	}
}

inline void zhuan2(int p,int f,int &x,int &y) {
	switch(f) {
		case 0:
			x=rx2[p]-rx1[p]+1,y=ry2[p];
			break;
		case 1:
			x=rx2[p],y=ry2[p]-ry1[p]+1;
			break;
		case 2:
			x=-1,y=ry2[p];
			break;
		case 3:
			x=rx2[p],y=-1;
			break;
	}
}
*/

inline void dfs1(int u,int pre,int pp,long long dis) {
	pp=fan[pp];

	for(int i=head[u],j=0;i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			if(j==pp) ++j;

			int v=E[i].to;

			ax[v]=ax[u]+step[j][0]*dis;
			ay[v]=ay[u]+step[j][1]*dis;

			dfs1(E[i].to,u,j,dis>>1);
			++j;
		}
}

/*
inline void dfs1(int u,int pre,int pp) {
	int tx,ty;

	pp=fan[pp];

	for(int i=head[u],j=0;i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			if(j==pp) ++j;
			dfs1(E[i].to,u,j);

			zhuan1(E[i].to,j,tx,ty);
			rx1[u]=min(rx1[u],tx);
			ry1[u]=min(ry1[u],ty);
			rx2[u]=max(rx2[u],tx);
			ry2[u]=max(ry2[u],ty);

			zhuan2(E[i].to,j,tx,ty);
			rx1[u]=min(rx1[u],tx);
			ry1[u]=min(ry1[u],ty);
			rx2[u]=max(rx2[u],tx);
			ry2[u]=max(ry2[u],ty);

			++j;
		}
}

void dfs2(int u,int pre,int pp) {
	int v;
	pp=fan[pp];

	for(int i=head[u],j=0;i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			if(j==pp) ++j;
			v=E[i].to;

			if(j==0) ax[v]=ax[u]+1-rx1[v],ay[v]=ay[u];
			else if(j==1) ax[v]=ax[u],ay[v]=ay[u]+1-ry1[v];
			else if(j==2) ax[v]=

			++j;
		}
}
*/

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	scanf("%d",&N);
	init();

	for(int i=1;i<N;++i) {
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	for(int i=1;i<=N;++i)
		if(du[i]>4) {
			puts("NO");
			return 0;
		}

	dfs1(1,-1,4,1LL<<31);
	//dfs2(1,-1,-1);

	puts("YES");
	for(int i=1;i<=N;++i)
		cout<<ax[i]<<' '<<ay[i]<<endl;

	return 0;
}
