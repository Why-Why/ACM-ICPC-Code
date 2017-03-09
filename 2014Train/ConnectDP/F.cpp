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
// Created Time  : 2015年12月09日 星期三 22时29分46秒
// File Name     : F.cpp

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
	long long val[MaxS];

	void init() {
		Hcou=0;
		memset(head,-1,sizeof(head));
	}

	void insert(unsigned int k,long long v) {
		int h=k%HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(key[i]==k) {
				val[i]+=v;
				return;
			}
		key[Hcou]=k;
		val[Hcou]=v;
		next[Hcou]=head[h];
		head[h]=Hcou++;
	}

	long long find(unsigned int k) {
		int h=k%HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(key[i]==k) return val[i];
		return 0;
	}
}dp[2];

int N,M;
char map1[11][11];
int endnum;

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
			dp[flag^1].insert(sta,v);
		}
		else if((a==1 || a==3) && b==1) {
			t=find(sta,y+1,1,2);
			sta=set(sta,t,a);
			sta=set(sta,y-1,0);
			sta=set(sta,y,0);
			dp[flag^1].insert(sta,v);
		}
		else if(a==3 && b==3) {
			if(x*100+y==endnum) {
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
		else if(a==2 && (b==2 || b==3)) {
			t=find(sta,y-2,-1,1);
			sta=set(sta,t,b);
			sta=set(sta,y-1,0);
			sta=set(sta,y,0);
			dp[flag^1].insert(sta,v);
		}
		else if(!a || !b) {
			sta=set(sta,y-1,a+b);
			sta=set(sta,y,0);
			dp[flag^1].insert(sta,v);
			sta=set(sta,y-1,0);
			sta=set(sta,y,a+b);
			dp[flag^1].insert(sta,v);
		}
	}
}

void getans_block(int y,int flag) {
	unsigned int sta;
	long long v;

	for(int i=0;i<dp[flag].Hcou;++i) {
		sta=dp[flag].key[i];
		v=dp[flag].val[i];

		if(!pos(sta,y-1) && !pos(sta,y))
			dp[flag^1].insert(sta,v);
	}
}

void getans_one(int y,int flag) {
	unsigned int sta;
	long long v;
	int a,b,t;

	for(int i=0;i<dp[flag].Hcou;++i) {
		sta=dp[flag].key[i];
		v=dp[flag].val[i];
		a=pos(sta,y-1);
		b=pos(sta,y);

		if(!a && !b) {
			dp[flag^1].insert(set(sta,y-1,3),v);
			dp[flag^1].insert(set(sta,y,3),v);
		}
		else if(a && b) continue;
		else if(a==3) {
			if(endnum==100+y) {
				sta=set(sta,y-1,0);
				sta=set(sta,y,0);
				dp[flag^1].insert(sta,v);
			}
		}
		else if(a==2) {
			t=find(sta,y-2,-1,1);
			sta=set(sta,t,3);
			sta=set(sta,y-1,0);
			sta=set(sta,y,0);
			dp[flag^1].insert(sta,v);
		}
	}
}

void solve() {
	dp[0].init();
	dp[0].insert(0,1);
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
			if(map1[i][j]=='#') getans_block(j,flag);
			else if(map1[i][j]=='*') getans_one(j,flag);
			else getans(i,j,flag);
			flag^=1;
		}
	}

	printf("%I64d\n",dp[flag].find(0));
}

inline int findend() {
	for(int i=N;i>=1;--i)
		for(int j=M;j>=1;--j)
			if(map1[i][j]=='.') return i*100+j;
	return -1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&N,&M) && N+M) {
		for(int i=N;i>=1;--i) scanf("%s",map1[i]+1);
		endnum=findend();
		if(endnum==-1 || map1[1][1]=='#' || map1[1][M]=='#') puts("0");
		else {
			map1[1][1]=map1[1][M]='*';
			solve();
		}
	}
	
	return 0;
}
