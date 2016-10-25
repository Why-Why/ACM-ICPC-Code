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
// Created Time  : 2016年08月28日 星期日 17时36分14秒
// File Name     : D.cpp

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

const int MaxN=50005;

int T=80;

int N,M,Q;
set <int> E[MaxN];
set <int> ::iterator iter;

int headx,headd;
int ll[MaxN],rr[MaxN],num[MaxN];

int ans[MaxN];
bool vis[MaxN];

inline void addd(int p) {
	ll[p]=-1;
	rr[p]=headd;
	headd=p;
}

inline void addx(int p) {
	ll[p]=-1;
	rr[p]=headx;
	headx=p;
}

inline void deld(int p) {
	if(ll[p]==-1) headd=rr[p];
	else rr[ll[p]]=rr[p];

	if(rr[p]!=-1) ll[rr[p]]=ll[p];
}

inline void delx(int p) {
	if(ll[p]==-1) headx=rr[p];
	else rr[ll[p]]=rr[p];

	if(rr[p]!=-1) ll[rr[p]]=ll[p];
}

inline void online(int x) {
	vis[x]=1;
	if(num[x]>T) return;

	for(iter=E[x].begin();iter!=E[x].end();++iter)
		++ans[*iter];
}

inline void offline(int x) {
	vis[x]=0;
	if(num[x]>T) return;

	for(iter=E[x].begin();iter!=E[x].end();++iter)
		--ans[*iter];
}

inline void add_friend(int x,int y) {
	++num[x];

	if(num[x]==T+1 && vis[x]) {
		delx(x);
		addd(x);

		for(iter=E[x].begin();iter!=E[x].end();++iter)
			--ans[*iter];
	}

	if(num[x]<=T && vis[x]) ++ans[y];
	E[x].insert(y);
}

inline void del_friend(int x,int y) {
	if(num[x]<=T && vis[x]) --ans[y];
	E[x].erase(y);
	--num[x];

	if(num[x]==T && vis[x]) {
		deld(x);
		addx(x);

		for(iter=E[x].begin();iter!=E[x].end();++iter)
			++ans[*iter];
	}
}

inline int getans(int x) {
	int ret=ans[x];

	for(int i=headd;i!=-1;i=rr[i])
		if(vis[i] && E[x].count(i)) ++ret;

	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,x,y;
	char s[5];

	headd=headx=-1;

	scanf("%d %d %d",&N,&M,&Q);
	scanf("%d",&a);
	while(a--) {
		scanf("%d",&x);
		vis[x]=1;
	}

	while(M--) {
		scanf("%d %d",&x,&y);
		E[x].insert(y);
		E[y].insert(x);
		++num[x];
		++num[y];
	}

	for(int i=1;i<=N;++i)
		if(num[i]>T) addd(i);
		else {
			addx(i);

			if(vis[i]) {
				for(iter=E[i].begin();iter!=E[i].end();++iter) ++ans[*iter];
			}
		}

	while(Q--) {
		scanf("%s %d",s,&x);
		if(s[0]=='O') online(x);
		else if(s[0]=='F') offline(x);
		else if(s[0]=='A') {
			scanf("%d",&y);
			add_friend(x,y);
			add_friend(y,x);
		}
		else if(s[0]=='D') {
			scanf("%d",&y);
			del_friend(x,y);
			del_friend(y,x);
		}
		else if(s[0]=='C') printf("%d\n",getans(x));
	}

	return 0;
}
