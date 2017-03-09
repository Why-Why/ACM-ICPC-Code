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
// Created Time  : 2016年10月19日 星期三 10时12分18秒
// File Name     : A_1.cpp

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

const int MaxNode=1000005;

struct State {
	State * par,* go[26];
	int maxn,v;

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
	for(int i=0;i<bcou;++i) topo[--topocou[buf[i].maxn]]=buf+i;			// from 0.
}

///////////////////////////////////////

char s[300000];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%s",s)) {
		init();
		for(int i=0;s[i];++i) extend(s[i]-'a',0);

		int ans=0,t=0;
		State * p=root;

		scanf("%s",s);
		for(int i=0;s[i];++i) {
			if(p->go[s[i]-'a']) {
				++t;
				p=p->go[s[i]-'a'];
				ans=max(ans,min(t,p->maxn));

				continue;
			}

			while(p && p->go[s[i]-'a']==0) p=p->par;
			if(p==0) p=root,t=0;
			else {
				t=min(p->maxn,t);
				++t;
				p=p->go[s[i]-'a'];

				ans=max(ans,min(t,p->maxn));
			}
		}

		printf("%d\n",ans);
	}

	return 0;
}
