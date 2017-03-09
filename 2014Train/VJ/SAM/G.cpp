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
// Created Time  : 2016年10月23日 星期日 23时11分56秒
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

// par为parent树中的父亲，maxn是节点最大长度。

const int MaxNode=200005;

struct State {
	//State * par,* go[27];
	int par,go[26];
	int maxn;
	int v;

	State(int _maxn=0):par(0),maxn(_maxn) {
		memset(go,0,sizeof(go));
		v=0;
	}
};

//State * root,* last;
int root,last;
State buf[MaxNode];
int bcou;

inline int newState(int maxn) {
	++bcou;
	buf[bcou]=State(maxn);
	return bcou;
}

void init() {
	bcou=0;
	root=last=newState(0);
}

inline void extend(int w,int v) {
	int p=last;
	int np=newState(buf[p].maxn+1);

	//np->v=v;
	buf[np].v=v;

	while(p && buf[p].go[w]==0) //p->go[w]=np,p=p->par;
		buf[p].go[w]=np,p=buf[p].par;

	if(p==0) buf[np].par=root; //np->par=root;
	else {
		//State * q=p->go[w];
		int q=buf[p].go[w];

		//if(p->maxn+1==q->maxn) np->par=q;
		if(buf[p].maxn+1==buf[q].maxn) buf[np].par=q;
		else {
			//State * nq=newState(p->maxn+1);
			int nq=newState(buf[p].maxn+1);

			//memcpy(nq->go,q->go,sizeof(q->go));
			memcpy(buf[nq].go,buf[q].go,sizeof(buf[q].go));

			//nq->par=q->par;
			buf[nq].par=buf[q].par;
			//q->par=nq;
			buf[q].par=nq;
			//np->par=nq;
			buf[np].par=nq;

			//while(p && p->go[w]==q)
				//p->go[w]=nq,p=p->par;

			while(p && buf[p].go[w]==q)
				buf[p].go[w]=nq,p=buf[p].par;
		}
	}

	last=np;
}

int topocou[100005];
int topo[MaxNode];

void topoSort(int len) {
	memset(topocou,0,sizeof(topocou));			//
	for(int i=1;i<=bcou;++i) ++topocou[buf[i].maxn];
	for(int i=1;i<=len;++i) topocou[i]+=topocou[i-1];
	for(int i=1;i<=bcou;++i) topo[--topocou[buf[i].maxn]]=i;
}

///////////////////////

long long ans;
char s[100005];

void solve(char s[]) {
	int p=root;
	int t=0;

	for(int i=0;s[i];++i) {
		if(buf[p].go[s[i]-'a']) {
			++t;
			p=buf[p].go[s[i]-'a'];
			buf[p].v=max(buf[p].v,t);

			continue;
		}

		while(p && buf[p].go[s[i]-'a']==0) p=buf[p].par;

		if(p==0) t=0,p=root;
		else {
			t=min(t,buf[p].maxn);
			++t;
			p=buf[p].go[s[i]-'a'];

			buf[p].v=max(buf[p].v,t);
		}
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int N;
	scanf("%d",&T);

	while(T--) {
		int len=0;

		scanf("%d",&N);
		scanf("%s",s);

		init();
		for(int i=0;s[i];++i,++len) extend(s[i]-'a',0);

		ans=0;

		while(N--) {
			//extend(26,0);
			scanf("%s",s);
			solve(s);
			//for(int i=0;s[i];++i,++len) extend(s[i]-'a',2);
		}

		topoSort(len);
		for(int i=bcou-1;i>=0;--i)
			if(buf[topo[i]].par)
				buf[buf[topo[i]].par].v=max(buf[buf[topo[i]].par].v,buf[topo[i]].v);

		for(int i=1;i<=bcou;++i)
			if(buf[i].par)
				//ans+=buf[i].maxn-buf[buf[i].par].maxn;
				ans+=max(0,buf[i].maxn-max(buf[buf[i].par].maxn,buf[i].v));

		printf("Case %d: %I64d\n",cas++,ans);
	}

	return 0;
}
