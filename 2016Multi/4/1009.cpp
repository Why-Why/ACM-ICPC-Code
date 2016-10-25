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
// Created Time  : 2016年07月28日 星期四 16时53分40秒
// File Name     : 1009.cpp

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

const int MaxN=105;

int N;
char s[MaxN];
int a[MaxN],b[MaxN];

int w[MaxN][MaxN];
int h[MaxN],l[MaxN];
int num[15];

bool vis[MaxN];
int ret;

inline bool judge(int p) {
	int t;
	if(num[s[p]-'0']==1) t=b[s[p]-'0'];
	else t=a[s[p]-'0'];

	if(h[p]+l[p]<=t) return 1;
	return 0;
}

inline void qudiao(int p) {
	int t;
	if(num[s[p]-'0']==1) t=b[s[p]-'0'];
	else t=a[s[p]-'0'];
	--num[s[p]-'0'];

	ret+=t-h[p]-l[p];
	vis[p]=1;

	for(int i=1;i<=N;++i) {
		h[i]-=w[i][p];
		l[i]-=w[p][i];
	}
}

int th[MaxN],tl[MaxN];

inline bool qudiao1(int x) {
	int tret=ret;
	for(int i=1;i<=N;++i) th[i]=h[i],tl[i]=l[i];

	for(int i=1;i<=N;++i)
		if(!vis[i] && s[i]-'0'==x)
			qudiao(i);

	if(ret>=tret) return 1;

	ret=tret;
	for(int i=1;i<=N;++i) h[i]=th[i],l[i]=tl[i];
	return 0;
}

int getans() {
	ret=0;
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j) ret+=w[i][j];
	for(int i=0;i<10;++i)
		if(num[i])
			ret-=a[i]*(num[i]-1)+b[i];

	memset(vis,0,sizeof(vis));

	bool ok;

	while(1) {
		ok=0;
		for(int i=1;i<=N;++i)
			if(vis[i]==0 && judge(i)) {
				ok=1;
				qudiao(i);
			}

		if(!ok) break;
	}

	while(1) {
		ok=0;
		for(int i=0;i<10;++i)
			if(num[i]>1)
				if(qudiao1(i)) ok=1;

		if(!ok) break;
	}

	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;

	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		scanf("%s",s+1);
		for(int i=0;i<10;++i) scanf("%d %d",a+i,b+i);
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j) {
				scanf("%d",&w[i][j]);
				if(i==j) w[i][j]=0;
			}

		memset(num,0,sizeof(num));
		for(int i=1;i<=N;++i) ++num[s[i]-'0'];

		for(int i=1;i<=N;++i) {
			h[i]=l[i]=0;
			for(int j=1;j<=N;++j) {
				h[i]+=w[i][j];
				l[i]+=w[j][i];
			}
		}

		printf("Case #%d: %d\n",cas++,max(0,getans()));
	}

	return 0;
}
