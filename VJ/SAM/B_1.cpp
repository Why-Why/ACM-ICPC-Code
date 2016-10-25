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
// Created Time  : 2016年10月19日 星期三 22时35分48秒
// File Name     : B_1.cpp

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

const int MaxNode=200005;
const int INF=0x3f3f3f3f;

struct State {
	State * par,* go[26];
	int maxn,v,v1;

	State(int _maxn=0):par(0),maxn(_maxn) {
		memset(go,0,sizeof(go));
		v1=0;
		v=INF;
	}
};

State * root,* last;
State buf[MaxNode];
int bcou;

inline State * newState(int maxn) {
	buf[bcou]=State(maxn);
	++bcou;
	return buf+bcou-1;
}

void init() {
	bcou=0;
	root=last=newState(0);
}

inline void extend(int w) {
	State * p=last;
	State * np=newState(p->maxn+1);

	while(p && p->go[w]==0) p->go[w]=np,p=p->par;

	if(p==0) np->par=root;
	else {
		State * q=p->go[w];

		if(p->maxn+1==q->maxn) np->par=q;
		else {
			State * nq=newState(p->maxn+1);
			memcpy(nq->go,q->go,sizeof(q->go));

			nq->par=q->par;
			q->par=nq;
			np->par=nq;

			while(p && p->go[w]==q)
				p->go[w]=nq,p=p->par;
		}
	}

	last=np;
}

int topocou[MaxNode];
State * topo[MaxNode];

void topoSort(int len) {
	memset(topocou,0,sizeof(topocou));			//
	for(int i=0;i<bcou;++i) ++topocou[buf[i].maxn];
	for(int i=1;i<=len;++i) topocou[i]+=topocou[i-1];
	for(int i=0;i<bcou;++i) topo[--topocou[buf[i].maxn]]=buf+i;			// from 0.
}

/////////////////////////////////////////////////

char s[MaxNode];

inline void solve(char s[]) {
	//for(int i=0;i<bcou;++i) buf[i].v1=0;
	State * p=root;
	int t=0;

	for(int i=0;s[i];++i) {
		if(p->go[s[i]-'a']) {
			++t;
			p=p->go[s[i]-'a'];
			//p->v=max
			p->v1=max(p->v1,t);

			continue;
		}

		while(p && p->go[s[i]-'a']==0) p=p->par;

		if(p==0) p=root,t=0;
		else {
			t=min(t,p->maxn);
			++t;
			p=p->go[s[i]-'a'];

			//
			p->v1=max(p->v1,t);
		}
	}

	for(int i=bcou-1;i>=0;--i)			// !!!
		if(topo[i]->par)
			topo[i]->par->v1=max(topo[i]->par->v1,topo[i]->v1);

	for(int i=0;i<bcou;++i) {
		buf[i].v=min(buf[i].v,buf[i].v1);			// !!!
		buf[i].v1=0;
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();
	scanf("%s",s);
	for(int i=0;s[i];++i) extend(s[i]-'a');

	topoSort(strlen(s));

	while(~scanf("%s",s))
		solve(s);

	int ans=0;
	for(int i=0;i<bcou;++i)
		ans=max(ans,min(buf[i].maxn,buf[i].v));

	printf("%d\n",ans);

	return 0;
}
