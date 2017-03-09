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
// Created Time  : 2015年12月08日 星期二 21时00分50秒
// File Name     : C.cpp

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

char map1[15][15];
int N,M;

inline int pos(unsigned int sta,int p) {
	return (sta & (3<<(p<<1)))>>(p<<1);
}

inline unsigned int set(unsigned int sta,int p,int v) {
	return (sta & (~(3<<(p<<1)))) | (v<<(p<<1));
}

inline int find(unsigned int sta,int p,int step,int f) {
	int cou=0,t;
	for(int i=p;;i+=step) {
		t=pos(sta,i);
		if(cou==0 && t==f) return i;
		if(t==1) ++cou;
		if(t==2) --cou;
	}
}

void getans_X(int y,int flag) {
	unsigned int sta;
	long long v;

	for(int i=0;i<dp[flag].Hcou;++i) {
		sta=dp[flag].key[i];
		v=dp[flag].val[i];
		if(!pos(sta,y-1) && !pos(sta,y))
			dp[flag^1].insert(sta,v);
	}
}

void getans_O(int y,int flag) {
	unsigned int sta,nsta;
	long long v;
	int a,b,c,t;

	for(int i=0;i<dp[flag].Hcou;++i) {
		sta=dp[flag].key[i];
		v=dp[flag].val[i];
		a=pos(sta,y-1);
		b=pos(sta,y);
		c=pos(sta,M+1);

		if(c==1) continue;
		if(!a && !b) {
			sta=set(sta,y-1,1);
			sta=set(sta,y,2);
			dp[flag^1].insert(sta,v);
		}
		else if(a==1 && b==1) {
			t=find(sta,y+1,1,2);
			sta=set(sta,t,1);
			sta=set(sta,y-1,0);
			sta=set(sta,y,0);
			dp[flag^1].insert(sta,v);
		}
		else if(a==1 && b==2) {
			sta=set(sta,M+1,1);
			sta=set(sta,y-1,0);
			sta=set(sta,y,0);
			dp[flag^1].insert(sta,v);
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
			dp[flag^1].insert(sta,v);
			sta=set(sta,y-1,0);
			sta=set(sta,y,a+b);
			dp[flag^1].insert(sta,v);
		}
	}
}

void getans_Star(int y,int flag) {
	unsigned int sta,nsta;
	long long v;
	int a,b,c,t;

	for(int i=0;i<dp[flag].Hcou;++i) {
		sta=dp[flag].key[i];
		v=dp[flag].val[i];
		a=pos(sta,y-1);
		b=pos(sta,y);
		c=pos(sta,M+1);

		if(c==1) {
			if(a || b) continue;
			dp[flag^1].insert(sta,v);
		}
		else {
			if(!a && !b) {
				dp[flag^1].insert(sta,v);
				sta=set(sta,y-1,1);
				sta=set(sta,y,2);
				dp[flag^1].insert(sta,v);
			}
			else if(a==1 && b==1) {
				t=find(sta,y+1,1,2);
				sta=set(sta,t,1);
				sta=set(sta,y-1,0);
				sta=set(sta,y,0);
				dp[flag^1].insert(sta,v);
			}
			else if(a==1 && b==2) {
				sta=set(sta,M+1,1);
				sta=set(sta,y-1,0);
				sta=set(sta,y,0);
				dp[flag^1].insert(sta,v);
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
				dp[flag^1].insert(sta,v);
				sta=set(sta,y-1,0);
				sta=set(sta,y,a+b);
				dp[flag^1].insert(sta,v);
			}
		}
	}
}

void solve() {
	int flag=0;
	int t;
	unsigned int sta;
	long long v;
	dp[0].init();
	dp[0].insert(0,1);

	for(int i=1;i<=N;++i) {
		dp[flag^1].init();
		for(int j=0;j<dp[flag].Hcou;++j) {
			sta=dp[flag].key[j];
			v=dp[flag].val[j];
			if(!pos(sta,M)) {
				t=pos(sta,M+1);
				sta=set(sta,M+1,0);
				sta<<=2;
				sta=set(sta,M+1,t);
				dp[flag^1].insert(sta,v);
			}
		}
		flag^=1;

		for(int j=1;j<=M;++j) {
			dp[flag^1].init();
			if(map1[i][j]=='X') getans_X(j,flag);
			else if(map1[i][j]=='O') getans_O(j,flag);
			else getans_Star(j,flag);
			flag^=1;
		}
	}

	printf("%I64d\n",dp[flag].find(set(0,M+1,1)));
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&M);
		for(int i=1;i<=N;++i) scanf("%s",map1[i]+1);
		printf("Case %d: ",cas++);
		solve();
	}
	
	return 0;
}
