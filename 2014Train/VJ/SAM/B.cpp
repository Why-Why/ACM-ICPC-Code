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
// Created Time  : 2016年10月18日 星期二 00时12分43秒
// File Name     : A.cpp

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

const int MaxN=3000031;

struct State {
	State * par, * go[37];
	int maxn,v1;

	State(int _maxn=0):par(0),maxn(_maxn) {
		memset(go,0,sizeof(go));
		v1=0;
	}
};

State * root,* last;

State buf[MaxN];
int bcou;

int topocou[MaxN];

inline State * newState(int maxn) {
	++topocou[maxn];

	buf[bcou]=State(maxn);
	++bcou;
	return buf+bcou-1;
}

void init() {
	bcou=0;
	root=last=newState(0);
}

inline void extend(int w,int v) {
	State * p=last;
	State * np=newState(p->maxn+1);

	np->v1=v;

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

State * topo[MaxN];

void topoSort(int len) {
	for(int i=1;i<=len;++i) topocou[i]+=topocou[i-1];
	for(int i=0;i<bcou;++i) topo[--topocou[buf[i].maxn]]=buf+i;
}

char s[300000];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int len=0;
	init();

	int cou=0;

	while(gets(s)) {
		for(int i=0;s[i];++i,++len) extend(s[i]-'a',(1<<cou));
		extend(26+cou,0);
		++len;
		++cou;
	}

	topoSort(len);

	int ans=0;

	for(int i=bcou-1;i>=0;--i) {
		if(topo[i]->par)
			topo[i]->par->v1|=topo[i]->v1;
		if(topo[i]->v1==(1<<cou)-1) ans=max(ans,topo[i]->maxn);
	}

	printf("%d\n",ans);

	return 0;
}
