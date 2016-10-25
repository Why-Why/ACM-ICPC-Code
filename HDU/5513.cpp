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
// Created Time  : 2016年05月02日 星期一 21时43分44秒
// File Name     : 5513.cpp

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

const int HASH=7393;
const int MaxN=400005;
const int mod=1000000007;

typedef unsigned long long ULL;

int ans1;
long long ans2;

struct HASHMAP {
	int head[HASH],next[MaxN],Hcou;

	int key[MaxN];
	int cost[MaxN];
	long long val[MaxN];

	void init() {
		Hcou=0;
		memset(head,-1,sizeof(head));
	}

	void insert(int k,int c,long long v) {
		int h=k%HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(k==key[i]) {
				if(cost[i]==c) (val[i]+=v)%=mod;
				else if(cost[i]>c) {
					cost[i]=c;
					val[i]=v%mod;
				}
				return;
			}

		key[Hcou]=k;
		cost[Hcou]=c;
		val[Hcou]=v;
		next[Hcou]=head[h];			// !!!
		head[h]=Hcou++;
	}
}dp[2];

int map1[805][9];
int map2[805][9];
int N,M;

inline int pos(int sta,int p) {
	return (sta & (7<<((p<<1)+p)))>>((p<<1)+p);
}

inline void decode(int ret[],int sta) {
	for(int i=0;i<=M;++i,sta>>=3) ret[i]=sta&7;
}

inline int encode(int col[]) {
	int ret=0;
	int num[9]={};
	int cou=0;

	for(int i=0;i<=M;++i)
		if(col[i] && num[col[i]]==0) num[col[i]]=++cou;
	for(int i=M;i>=0;--i) {
		ret<<=3;			// !!!
		ret|=num[col[i]];
	}

	return ret;
}

inline int set(int col[],int p1,int v1,int p2,int v2) {
	int t1=col[p1],t2=col[p2];
	col[p1]=v1;
	col[p2]=v2;
	int ret=encode(col);
	col[p1]=t1;
	col[p2]=t2;
	return ret;
}

inline int count(int col[],int c) {
	int cou=0;
	for(int i=0;i<=M;++i)
		if(col[i]==c) ++cou;
	return cou;
}

inline void getnum(int x,int y,int flag) {
	int sta,nsta;
	int c;
	long long v;
	int col[10],tcol[10];
	int a,b;

	for(int i=0;i<dp[flag].Hcou;++i) {
		sta=dp[flag].key[i];
		c=dp[flag].cost[i];
		v=dp[flag].val[i];
		decode(col,sta);

		a=col[y-1];
		b=col[y];

		if(!a && !b) {
			nsta=set(col,y-1,8,y,8);
			dp[flag^1].insert(nsta,c,v);			// !!!

			nsta=set(col,y-1,8,y,0);
			dp[flag^1].insert(nsta,c,v);

			nsta=set(col,y-1,0,y,8);
			dp[flag^1].insert(nsta,c,v);
		}
		else if(!a) {
			if(count(col,b)>1) {
				nsta=set(col,y-1,0,y,0);
				dp[flag^1].insert(nsta,c+map2[x][y],(v*2)%mod);
			}

			nsta=set(col,y-1,b,y,0);
			dp[flag^1].insert(nsta,c+map2[x][y],(v*2)%mod);

			nsta=set(col,y-1,0,y,b);
			dp[flag^1].insert(nsta,c+map2[x][y],(v*2)%mod);

			nsta=set(col,y-1,b,y,b);
			dp[flag^1].insert(nsta,c+map2[x][y],(v*2)%mod);
		}
		else if(!b) {
			if(count(col,a)>1) {
				nsta=set(col,y-1,0,y,0);
				dp[flag^1].insert(nsta,c+map1[x][y],(v*2)%mod);
			}

			nsta=set(col,y-1,a,y,0);
			dp[flag^1].insert(nsta,c+map1[x][y],(v*2)%mod);

			nsta=set(col,y-1,0,y,a);
			dp[flag^1].insert(nsta,c+map1[x][y],(v*2)%mod);

			nsta=set(col,y-1,a,y,a);
			dp[flag^1].insert(nsta,c+map1[x][y],(v*2)%mod);
		}
		else if(a==b) continue;
		else {
			for(int i=0;i<=M;++i)
				if(col[i]==b) tcol[i]=a;
				else tcol[i]=col[i];

			if(count(tcol,a)>2) {
				nsta=set(col,y-1,0,y,0);
				dp[flag^1].insert(nsta,c+map1[x][y]+map2[x][y],(v*3)%mod);
			}

			nsta=set(tcol,y-1,a,y,0);			// !!!
			dp[flag^1].insert(nsta,c+map1[x][y]+map2[x][y],(v*3)%mod);

			nsta=set(tcol,y-1,0,y,a);
			dp[flag^1].insert(nsta,c+map1[x][y]+map2[x][y],(v*3)%mod);

			nsta=set(tcol,y-1,a,y,a);
			dp[flag^1].insert(nsta,c+map1[x][y]+map2[x][y],(v*3)%mod);
		}
	}
}

inline void show(int sta) {
	int col[10];
	decode(col,sta);
	for(int i=0;i<=M;++i)
		cout<<col[i]<<' ';
	cout<<"# ";
}

inline void show(int i,int j,int flag) {
			cout<<i<<' '<<j<<endl;
			for(int k=0;k<dp[flag].Hcou;++k) {
				show(dp[flag].key[k]);
				cout<<dp[flag].cost[k]<<' '<<dp[flag].val[k]<<endl;
			}
			cout<<endl;
}

inline void getans() {
	int flag=0;
	int sta,c;
	long long v;

	dp[0].init();
	dp[0].insert(0,0,1);

	for(int i=1;i<=N;++i) {
		dp[flag^1].init();

		for(int j=0;j<dp[flag].Hcou;++j) {
			sta=dp[flag].key[j];
			c=dp[flag].cost[j];
			v=dp[flag].val[j];
			if(!pos(sta,M) && (i==1 || sta)) dp[flag^1].insert(sta<<3,c,v);
		}
		flag^=1;

		for(int j=1;j<=M;++j) {
			dp[flag^1].init();
			getnum(i,j,flag);
			flag^=1;
		//cout<<dp[flag].Hcou<<endl;
		}

	}

	int oksta=0;
	for(int i=0;i<M;++i) {			// !!!
		oksta<<=3;
		oksta|=1;
	}

	ans1=0x3f3f3f3f;
	ans2=0;
	for(int i=0;i<dp[flag].Hcou;++i) {
		if(dp[flag].key[i]!=oksta) continue;

		if(dp[flag].cost[i]<ans1) {
			ans1=dp[flag].cost[i];
			ans2=dp[flag].val[i];
		}
		else if(dp[flag].cost[i]==ans1)
			ans2+=dp[flag].val[i];
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&M);
		for(int i=1;i<=N;++i)
			for(int j=2;j<=M;++j) scanf("%d",&map1[i][j]);
		for(int i=2;i<=N;++i)
			for(int j=1;j<=M;++j) scanf("%d",&map2[i][j]);

		getans();
		printf("Case #%d: %d %d\n",cas++,ans1,(int)ans2);
	}
	
	return 0;
}
