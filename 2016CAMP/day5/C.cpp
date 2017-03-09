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
// Created Time  : 2017年02月17日 星期五 22时51分26秒
// File Name     : C.cpp

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
// 直接dfs会超时，需要标记是否走过。

const int MaxNode=1000005;

struct State {
	State * par,* go[26];
	int maxn,v;

	State(int _maxn=0):par(0),maxn(_maxn) {
		memset(go,0,sizeof(go));
		v=-1;
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
	for(int i=0;i<=len;++i) topocou[i]=0;
	for(int i=0;i<bcou;++i) ++topocou[buf[i].maxn];
	for(int i=1;i<=len;++i) topocou[i]+=topocou[i-1];
	for(int i=0;i<bcou;++i) topo[--topocou[buf[i].maxn]]=buf+i;			// from 0, 0是根。
}

///////////////////////

char s[300005];
int N;

int rem[300005][26];

inline int cal(int L,int R,int c) {
	if(L>R) return 0;
	++L,++R;
	return rem[R][c]-rem[L-1][c];
}

inline long long getans(const State & p) {
	long long ret=0;

	for(int i=0;i<26;++i)
		if(p.go[i])
			ret+=cal(p.v-p.maxn+1,p.v-(p.par->maxn+2)+1,i);
	if(p.par->go[s[p.v-(p.par->maxn)]-'a']) ++ret;

	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%s",s);
	N=strlen(s);

	for(int i=1;i<=N;++i) {
		for(int j=0;j<26;++j) rem[i][j]=rem[i-1][j];
		++rem[i][s[i-1]-'a'];
	}

	init();
	for(int i=0;s[i];++i) extend(s[i]-'a',i);
	topoSort(N);
	for(int i=bcou-1;i>=0;--i) if(topo[i]!=root) topo[i]->par->v=topo[i]->v;

	long long ans=0;
	for(int i=1;i<bcou;++i) ans+=getans(buf[i]);
	printf("%lld\n",ans);

	return 0;
}
