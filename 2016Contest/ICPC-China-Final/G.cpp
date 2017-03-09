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
// Created Time  : 2017年02月21日 星期二 21时34分07秒
// File Name     : G.cpp

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

const int MaxN=200005;
const int INF=0x3f3f3f3f;

struct Edge {
	int u,v,w;

	Edge() {}
	Edge(int a):w(a) {}

	bool operator < (const Edge & b) const {
		return w<b.w;
	}
};

Edge E[MaxN];
int N,M;
int c[MaxN];

int fa[MaxN],ans[MaxN],size[MaxN];
map <int,int> sta[MaxN];

typedef pair<int,int> pii;
vector <pii> tfa[MaxN],tans[MaxN];

int find(int x) {
	if(fa[x]==-1) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

void solve() {
	for(int i=1;i<=N;++i) {
		fa[i]=-1;
		sta[i].clear();
		sta[i][c[i]]=1;
		ans[i]=c[i];
		size[i]=1;

		tfa[i].clear();
		tfa[i].push_back(pii(0,-1));
		tans[i].clear();
		tans[i].push_back(pii(0,ans[i]));
	}

	int a,b;

	for(int i=1;i<=M;++i) {
		a=find(E[i].u);
		b=find(E[i].v);
		if(a==b) continue;

		if(size[b]>size[a]) swap(a,b);

		size[a]+=size[b];
		fa[b]=a;
		for(auto x:sta[b]) {
			sta[a][x.first]+=x.second;
			if(sta[a][x.first]>sta[a][ans[a]] || (sta[a][x.first]==sta[a][ans[a]] && x.first<ans[a]))
				ans[a]=x.first;
		}
		sta[b].clear();

		tfa[b].push_back(pii(E[i].w,fa[b]));
		tans[a].push_back(pii(E[i].w,ans[a]));
	}
}

int find(int x,int time) {
	int t=upper_bound(tfa[x].begin(),tfa[x].end(),pii(time,INF))-tfa[x].begin()-1;
	if(tfa[x][t].second==-1) return x;

	return find(tfa[x][t].second,time);			// 可持久化并查集不能直接压缩路径，另外如果是按照启发式合并的话，并查集深度为logN。

	//tfa[x][t].second=find(tfa[x][t].second,time);
	//return tfa[x][t].second;
}

inline int getans(int x,int time) {
	x=find(x,time);
	int t=upper_bound(tans[x].begin(),tans[x].end(),pii(time,INF))-tans[x].begin()-1;
	return tans[x][t].second;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int Q,a,b;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&M);
		for(int i=1;i<=N;++i) scanf("%d",c+i);
		for(int i=1;i<=M;++i) scanf("%d %d %d",&E[i].u,&E[i].v,&E[i].w);
		sort(E+1,E+M+1);
		solve();

		printf("Case #%d:\n",cas++);

		int last=0;

		scanf("%d",&Q);
		while(Q--) {
			scanf("%d %d",&a,&b);
			a^=last;
			b^=last;
			last=getans(a,b);
			printf("%d\n",last);
		}
	}

	return 0;
}
