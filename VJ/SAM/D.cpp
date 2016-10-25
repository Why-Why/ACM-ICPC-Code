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
// Created Time  : 2016年10月20日 星期四 23时53分15秒
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

// par为parent树中的父亲，maxn是节点最大长度。

const int MaxNode=1000005;

struct State {
	State * par,* go[26];

	State * gg[26];
	char cc[26];
	int cou;

	int maxn;
	long long v;

	State(int _maxn=0):par(0),maxn(_maxn) {
		memset(go,0,sizeof(go));
		v=0;
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

inline void extend(int w,int v) {
	State * p=last;
	State * np=newState(p->maxn+1);

	np->v=v;			//

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
	for(int i=0;i<bcou;++i) topo[--topocou[buf[i].maxn]]=buf+i;			// from 0, 0是根。
}

////////////////////////////////

char s[90004];

long long dfs(State * p) {
	long long ret=1;

	p->cou=0;

	for(int i=0;i<26;++i) 
		if(p->go[i]) {
			p->cc[p->cou]='a'+i;
			p->gg[p->cou++]=p->go[i];
			ret+=dfs(p->go[i]);
		}

	p->v=ret;

	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%s",s);
	init();

	int len=0;
	for(int i=0;s[i];++i,++len) extend(s[i]-'a',0);

	topoSort(len);
	for(int i=bcou-1;i>=0;--i) {
		topo[i]->cou=0;
		topo[i]->v=1;

		for(int j=0;j<26;++j)
			if(topo[i]->go[j]) {
				topo[i]->cc[topo[i]->cou]='a'+j;
				topo[i]->gg[topo[i]->cou++]=topo[i]->go[j];

				topo[i]->v+=topo[i]->go[j]->v;
			}
	}

	//dfs(root);

	int Q,a;
	scanf("%d",&Q);

	State * p;

	while(Q--) {
		scanf("%d",&a);
		p=root;

		while(a)
			for(int i=0;i<p->cou;++i) {
				if(p->gg[i]->v>=a) {
					putchar(p->cc[i]);
					--a;
					p=p->gg[i];
					break;
				}
				else a-=p->gg[i]->v;
			}

		puts("");
	}

	return 0;
}
