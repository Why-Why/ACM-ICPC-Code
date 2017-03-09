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
// Created Time  : 2015年12月09日 星期三 11时47分07秒
// File Name     : D.cpp

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int INF=0x3f3f3f3f;

struct HASHMAP {
	static const int HASH=30007;
	static const int MaxS=1000000;

	int head[HASH],Hcou,next[MaxS];
	unsigned int key[MaxS];
	int val[MaxS];

	void init() {
		Hcou=0;
		memset(head,-1,sizeof(head));
	}

	void insert(unsigned int k,int v) {
		int h=k%HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(key[i]==k) {
				val[i]=min(val[i],v);
				return;
			}
		key[Hcou]=k;
		val[Hcou]=v;
		next[Hcou]=head[h];
		head[h]=Hcou++;
	}

	int find(unsigned int k) {
		int h=k%HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(key[i]==k) return val[i];
		return INF;
	}
}dp[2];

int N,M;
int map1[13][13][4];
char tmap[23][23];
const int step[4][2]={{-1,0},{0,-1},{1,0},{0,1}};

inline int pos(unsigned int sta,int p) {
	return (sta & (3<<(p<<1)))>>(p<<1);
}

inline unsigned int set(unsigned int sta,int p,int v) {
	return (sta & (~(3<<(p<<1)))) | (v<<(p<<1));
}

inline int find(unsigned int sta,int p,int step,int f) {
	int cou=0,t;
	for(;;p+=step) {
		t=pos(sta,p);
		if(!cou && t==f) return p;
		if(t==1) ++cou;
		if(t==2) --cou;
	}
}

void getans(int x,int y,int flag) {
	unsigned int sta;
	int v,a,b,t;

	for(int i=0;i<dp[flag].Hcou;++i) {
		sta=dp[flag].key[i];
		v=dp[flag].val[i];
		a=pos(sta,y-1);
		b=pos(sta,y);

		if(!a && !b) {
			sta=set(sta,y-1,1);
			sta=set(sta,y,2);
			dp[flag^1].insert(sta,v+map1[x][y][2]+map1[x][y][3]);
		}
		else if(a==1 && b==1) {
			t=find(sta,y+1,1,2);
			sta=set(sta,t,1);
			sta=set(sta,y-1,0);
			sta=set(sta,y,0);
			dp[flag^1].insert(sta,v);
		}
		else if(a==1 && b==2) {
			if(x==N && y==M) {
				sta=set(sta,y-1,0);
				sta=set(sta,y,0);
				dp[flag^1].insert(sta,v);
			}
		}
		else if(a==2 && b==1) {
			sta=set(sta,y-1,0);
			sta=set(sta,y,0);
			dp[flag^1].insert(sta,v);
		}
		else if(a==2 && b==2) {
			t=find(sta,y-2,-1,1);
			sta=set(sta,t,2);
			sta=set(sta,y-1,0);
			sta=set(sta,y,0);
			dp[flag^1].insert(sta,v);
		}
		else {
			sta=set(sta,y-1,a+b);
			sta=set(sta,y,0);
			dp[flag^1].insert(sta,v+map1[x][y][2]);
			sta=set(sta,y-1,0);
			sta=set(sta,y,a+b);
			dp[flag^1].insert(sta,v+map1[x][y][3]);
		}
	}
}

void solve() {
	dp[0].init();
	dp[0].insert(0,0);
	unsigned int sta;
	int v,flag=0;

	for(int i=1;i<=N;++i) {
		dp[flag^1].init();
		for(int j=0;j<dp[flag].Hcou;++j) {
			sta=dp[flag].key[j];
			v=dp[flag].val[j];
			if(!pos(sta,M)) {
				sta<<=2;
				dp[flag^1].insert(sta,v);
			}
		}
		flag^=1;

		for(int j=1;j<=M;++j) {
			dp[flag^1].init();
			getans(i,j,flag);
			flag^=1;
		}
	}

	printf("%I64d\n",dp[flag].find(0));
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&M);
		getchar();
		for(int i=1;i<=((N<<1)|1);++i) gets(tmap[i]+1);
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
				for(int k=0;k<4;++k)
					map1[i][j][k]=tmap[(i<<1)+step[k][0]][(j<<1)+step[k][1]]-'0';

		solve();
	}
	
	return 0;
}
