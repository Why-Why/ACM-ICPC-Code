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
// Created Time  : 2016年04月09日 星期六 18时53分38秒
// File Name     : B1.cpp

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

const int MaxN=11;

int vis[MaxN][(1<<MaxN)+5];
int N;
char s[MaxN];
queue<int>que;

inline int change(int u,int len) {
	int ret=0;
	int a,b;

	for(int i=0,j=len-1;i<=j;++i,--j) {
		a=(u&(1<<i)) ? 0 : 1;
		b=(u&(1<<j)) ? 0 : 1;
		ret|=(a<<j);
		ret|=(b<<i);
	}
	ret|=u&(~((1<<len)-1));
	return ret;
}

inline void show(int x) {
	for(int i=0;i<4;++i,x>>=1)
		if(x&1) putchar('+');
		else putchar('-');
	puts("");
}

void bfs(int x) {
	int u=(1<<x)-1,v;
	while(!que.empty()) que.pop();

	que.push(u);
	vis[x][u]=1;
	while(!que.empty()) {
		u=que.front();
		que.pop();

		for(int i=0;i<x;++i) {
			v=change(u,i+1);
			if(vis[x][v]==0) {
				vis[x][v]=vis[x][u]+1;
				que.push(v);
			}
		}
	}
}

void init() {
	for(int i=1;i<MaxN;++i) bfs(i);
}

inline int zhuan(char s[]) {
	int ret=0;
	for(int i=strlen(s)-1;i>=0;--i)
		ret=(ret<<1)+(s[i]=='+' ? 1 : 0);
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();
	int T,cas=1;
	//for(int i=0;i<(1<<4);++i) {
		//cout<<vis[4][i]-1<<' ';
		//show(i);
	//}

	scanf("%d",&T);
	while(T--) {
		scanf("%s",s);
		printf("Case #%d: ",cas++);
		printf("%d\n",vis[strlen(s)][zhuan(s)]-1);
	}

	
	return 0;
}
