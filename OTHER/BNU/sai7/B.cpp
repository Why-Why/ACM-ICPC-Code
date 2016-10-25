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
// Created Time  : 2016年10月03日 星期一 12时22分18秒
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

const int MaxN=203;
const int INF=0x3f3f3f3f;

char map1[MaxN][MaxN];
int N,M;

int wei[MaxN][MaxN];
int ans[MaxN][MaxN];

int que[MaxN*MaxN],first,last;

const int step[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

inline bool judge(int x,int y) {
	if(x>=1 && y>=1 && x<=N && y<=M && map1[x][y]!='#') return 1;
	return 0;
}

void bfs() {
	int nx,ny,t;
	int x,y;

	//first=last=0;
	//que[last++]=x*1000+y;
	//wei[x][y]=0;

	while(last-first) {
		t=que[first++];
		x=t/1000;
		y=t%1000;

		for(int i=0;i<4;++i) {
			nx=x+step[i][0];
			ny=y+step[i][1];
			if(judge(nx,ny) && wei[nx][ny]>wei[x][y]+1) {
				wei[nx][ny]=wei[x][y]+1;
				que[last++]=nx*1000+ny;
			}
		}
	}
}

void bfs1(int x,int y) {
	int nx,ny,t;

	first=last=0;
	que[last++]=x*1000+y;
	ans[x][y]=0;

	while(last-first) {
		t=que[first++];
		x=t/1000;
		y=t%1000;

		for(int i=0;i<4;++i) {
			nx=x+step[i][0];
			ny=y+step[i][1];
			if(judge(nx,ny) && ans[nx][ny]>ans[x][y]+1 && ans[x][y]+1<wei[nx][ny]) {
				ans[nx][ny]=ans[x][y]+1;
				que[last++]=nx*1000+ny;
			}
		}
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;++i) scanf("%s",map1[i]+1);
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j) wei[i][j]=INF,ans[i][j]=INF;

	first=last=0;
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			if(map1[i][j]=='$') {
				que[last++]=i*1000+j;
				wei[i][j]=0;
			}
	bfs();

	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			if(map1[i][j]=='@')
				bfs1(i,j);

	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			if(map1[i][j]=='%')
				if(ans[i][j]!=INF)
					puts("Yes");
				else puts("No");

	return 0;
}
