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
// Created Time  : 2017年02月05日 星期日 23时18分18秒
// File Name     : F.cpp

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

int C[27][1003][1003];
int N,M;

inline int lowbit(int x) {
	return x&(-x);
}

inline void add(int (&C)[1003][1003],int x,int y,int d) {
	for(int i=x;i<=N;i+=lowbit(i))
		for(int j=y;j<=M;j+=lowbit(j))
			C[i][j]+=d;
}

inline int sum(int (&C)[1003][1003],int x,int y) {
	int ret=0;
	for(int i=x;i;i-=lowbit(i))
		for(int j=y;j;j-=lowbit(j))
			ret+=C[i][j];
	return ret;
}

inline void update(int x1,int y1,int x2,int y2,int t) {
	add(C[t],x1,y1,1);
	add(C[t],x2+1,y1,-1);
	add(C[t],x1,y2+1,-1);
	add(C[t],x2+1,y2+1,1);
}

inline int query(int x,int y,int t) {
	return sum(C[t],x,y);
}

char map1[1003][1003];
int num[1003][1003][26];
long long rem[1003][1003][27];
int K;
int ra[300005],rb[300005],rc[300005],rd[300005],rch[300005];

inline void solve(int num[],int x,int y) {
	long long ts=0,tcou;

	for(int i=0;i<26;++i) {
		num[i]=query(x,y,i);
		ts+=num[i];
	}
	num[map1[x][y]-'a']+=K-ts;

	ts=tcou=0;
	for(int i=0;i<26;++i) {
		rem[x][y][i]+=tcou*i-ts;
		tcou+=num[i];
		ts+=num[i]*i;
	}

	ts=tcou=0;
	for(int i=25;i>=0;--i) {
		rem[x][y][i]+=ts-tcou*i;
		tcou+=num[i];
		ts+=num[i]*i;
	}

	rem[x][y][26]=rem[x][y][map1[x][y]-'a'];
}

long long base,ans;

inline long long getans(int x1,int y1,int x2,int y2,int t) {
	long long ret=rem[x2][y2][t]-rem[x1-1][y2][t]-rem[x2][y1-1][t]+rem[x1-1][y1-1][t];
	t=26;
	return ret-(rem[x2][y2][t]-rem[x1-1][y2][t]-rem[x2][y1-1][t]+rem[x1-1][y1-1][t]);

}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char s[10];

	scanf("%d %d %d",&N,&M,&K);

	for(int i=1;i<=N;++i) scanf("%s",map1[i]+1);
	for(int i=1;i<=K;++i) {
		scanf("%d %d %d %d %s",ra+i,rb+i,rc+i,rd+i,s);
		rch[i]=s[0]-'a';
		update(ra[i],rb[i],rc[i],rd[i],s[0]-'a');
	}

	int ts;

	for(int x=1;x<=N;++x)
		for(int y=1;y<=M;++y)
			solve(num[x][y],x,y);

	for(int x=1;x<=N;++x)
		for(int y=1;y<=M;++y)
			for(int i=0;i<27;++i)
				rem[x][y][i]+=rem[x-1][y][i]+rem[x][y-1][i]-rem[x-1][y-1][i];

	ans=100000000000000000LL;
	base=rem[N][M][26];

	for(int i=1;i<=K;++i) ans=min(ans,getans(ra[i],rb[i],rc[i],rd[i],rch[i]));
	printf("%I64d\n",base+ans);

	return 0;
}
