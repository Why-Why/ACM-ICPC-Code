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

struct State {
	State * par, * go[27];
	int maxn,v1,v2;

	State(int _maxn=0):par(0),maxn(_maxn) {
		memset(go,0,sizeof(go));
		v1=v2=0;
	}
};

State * root,* last;

State buf[1000006];
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

void extend(int w,int v,int tv) {
	State * p=last;
	State * np=newState(p->maxn+1);

	np->v1=v;
	np->v2=tv;

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

int topocou[1000006];
State * topo[1000006];

void topoSort(int len) {
	memset(topocou,0,sizeof(topocou));
	for(int i=0;i<bcou;++i) ++topocou[buf[i].maxn];
	for(int i=1;i<=len;++i) topocou[i]+=topocou[i-1];
	for(int i=0;i<bcou;++i) topo[--topocou[buf[i].maxn]]=buf+i;
}

char s[300000];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%s",s)) {
		int len=1;

		init();
		for(int i=0;s[i];++i,++len) extend(s[i]-'a',1,0);
		extend(26,0,0);
		scanf("%s",s);
		for(int i=0;s[i];++i,++len) extend(s[i]-'a',2,0);

		topoSort(len);

		int ans=0;

		for(int i=bcou-1;i>=0;--i) {
			if(topo[i]->par) {
				topo[i]->par->v1|=topo[i]->v1;
				//topo[i]->par->v1=max(topo[i]->par->v1,topo[i]->v1);
				//topo[i]->par->v2=max(topo[i]->par->v2,topo[i]->v2);
			}
			if(topo[i]->v1==3) {
				ans=max(ans,topo[i]->maxn);
			}
			//if(topo[i]->v1 && topo[i]->v2) {
				//ans=max(ans,min(topo[i]->maxn,min(topo[i]->v1,topo[i]->v2)));
				//cout<<topo[i]<<endl;
			//}
		}

		printf("%d\n",ans);
	}

	return 0;
}
