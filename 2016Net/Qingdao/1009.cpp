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
// Created Time  : 2016年09月17日 星期六 15时48分47秒
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

const int MaxN=100005;

struct Edge {
	int to,next,w;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;

int N;

void init() {
	Ecou=0;
	for(int i=1;i<=N;++i) head[i]=-1;
}

inline void addEdge(int u,int v,int w) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	E[Ecou].w=w;
	head[u]=Ecou++;
}

int len1[MaxN],remlen1[MaxN],len2[MaxN],remlen2[MaxN],len3[MaxN],remlen3[MaxN];
int slen[MaxN];

int zi[MaxN],nzi[MaxN];
int zz1[MaxN],remzz1[MaxN],zz2[MaxN];

long long ans=0;

void dfs(int u,int pre) {
	int t;

	len1[u]=len2[u]=len3[u]=0;
	remlen1[u]=remlen2[u]=remlen3[u]=-1;

	zz1[u]=zz2[u]=0;
	remzz1[u]=-1;

	zi[u]=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			dfs(E[i].to,u);

			t=len1[E[i].to]+E[i].w;
			if(t>=len1[u]) {
				len3[u]=len2[u];
				len2[u]=len1[u];
				len1[u]=t;
				remlen3[u]=remlen2[u];
				remlen2[u]=remlen1[u];
				remlen1[u]=E[i].to;
			}
			else if(t>=len2[u]) {
				len3[u]=len2[u];
				len2[u]=t;
				remlen3[u]=remlen2[u];
				remlen2[u]=E[i].to;
			}
			else if(t>=len3[u]) {
				len3[u]=t;
				remlen3[u]=E[i].to;
			}

			t=zi[E[i].to];
			if(t>=zz1[u]) {
				zz2[u]=zz1[u];
				zz1[u]=t;
				remzz1[u]=E[i].to;
			}
			else if(t>=zz2[u]) zz2[u]=t;

			zi[u]=max(zi[u],zi[E[i].to]);
		}

	zi[u]=max(zi[u],len1[u]+len2[u]);
}

/*
int stku[MaxN],stkpre[MaxN],stkw[MaxN];
int top;

void dfs(int u,int pre) {
	top=0;
	stku[top]=u;
	stkpre[top]=pre;
	++top;

	while(top) {

	int t;

	len1[u]=len2[u]=len3[u]=0;
	remlen1[u]=remlen2[u]=remlen3[u]=-1;

	zz1[u]=zz2[u]=0;
	remzz1[u]=-1;

	zi[u]=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			dfs(E[i].to,u);

			t=len1[E[i].to]+E[i].w;
			if(t>=len1[u]) {
				len3[u]=len2[u];
				len2[u]=len1[u];
				len1[u]=t;
				remlen3[u]=remlen2[u];
				remlen2[u]=remlen1[u];
				remlen1[u]=E[i].to;
			}
			else if(t>=len2[u]) {
				len3[u]=len2[u];
				len2[u]=t;
				remlen3[u]=remlen2[u];
				remlen2[u]=E[i].to;
			}
			else if(t>=len3[u]) {
				len3[u]=t;
				remlen3[u]=E[i].to;
			}

			t=zi[E[i].to];
			if(t>=zz1[u]) {
				zz2[u]=zz1[u];
				zz1[u]=t;
				remzz1[u]=E[i].to;
			}
			else if(t>=zz2[u]) zz2[u]=t;

			zi[u]=max(zi[u],zi[E[i].to]);
		}

	zi[u]=max(zi[u],len1[u]+len2[u]);

	}
}
*/

int que[MaxN],first,last;
int vis[MaxN],flag;

inline void cal(int u,int pre,int dis) {
	int t;
	if(remlen1[pre]==u) t=len2[pre];
	else t=len1[pre];

	slen[u]=max(slen[pre],t)+dis;

	if(remzz1[pre]==u) t=zz2[pre];
	else t=zz1[pre];

	nzi[u]=max(nzi[pre],t);

	/*
	int tt[4],tcou=0;

	tt[tcou++]=slen[pre];
	if(remlen1[pre]!=u) tt[tcou++]=len1[pre];
	if(remlen2[pre]!=u) tt[tcou++]=len2[pre];
	if(remlen3[pre]!=u) tt[tcou++]=len3[pre];

	int t2;
	t=t2=0;
	for(int i=0;i<tcou;++i)
		if(tt[i]>t) {
			t2=t;
			t=tt[i];
		}
		else if(tt[i]>t2)
			t2=tt[i];
	*/

	t=0;
	if(remlen1[pre]!=u) {
		t+=len1[pre];
		if(remlen2[pre]!=u) t+=max(slen[pre],len2[pre]);
		else t+=max(slen[pre],len3[pre]);
	}
	else {
		t+=len2[pre];
		t+=max(len3[pre],slen[pre]);
	}

	nzi[u]=max(nzi[u],t);

	ans+=max(nzi[u],zi[u]);
}

void dfs1(int u,int pre,int dis) {
	first=last=0;
	++flag;

	que[last++]=u;
	slen[u]=nzi[u]=0;

	vis[u]=flag;

	while(last-first) {
		pre=que[first++];

		for(int i=head[pre];i!=-1;i=E[i].next)
			if(vis[E[i].to]!=flag) {
				vis[E[i].to]=flag;
				que[last++]=E[i].to;

				u=E[i].to;
				dis=E[i].w;

				cal(u,pre,dis);
			}
	}
}

/*
void dfs1(int u,int pre,int dis) {
	if(pre==-1) slen[u]=0,nzi[u]=0;
	else {
		int t;
		if(remlen1[pre]==u) t=len2[pre];
		else t=len1[pre];

		slen[u]=max(slen[pre],t)+dis;

		if(remzz1[pre]==u) t=zz2[pre];
		else t=zz1[pre];

		nzi[u]=max(nzi[pre],t);

		int tt[4],tcou=0;

		tt[tcou++]=slen[pre];
		if(remlen1[pre]!=u) tt[tcou++]=len1[pre];
		if(remlen2[pre]!=u) tt[tcou++]=len2[pre];
		if(remlen3[pre]!=u) tt[tcou++]=len3[pre];

		int t2;
		t=t2=0;
		for(int i=0;i<tcou;++i)
			if(tt[i]>t) {
				t2=t;
				t=tt[i];
			}
			else if(tt[i]>t2)
				t2=tt[i];

		t=0;
		if(remlen1[pre]!=u) {
			t+=len1[pre];
			if(remlen2[pre]!=u) t+=max(slen[pre],len2[pre]);
			else t+=max(slen[pre],len3[pre]);
		}
		else {
			t+=len2[pre];
			t+=max(len3[pre],slen[pre]);
		}

		nzi[u]=max(nzi[u],t);

		ans+=max(nzi[u],zi[u]);
	}

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
			dfs1(E[i].to,u,E[i].w);
}
*/

inline int read() {
	char c=0;
	while(c<'0' || c>'9') c=getchar();
	int ret=c-'0';
	while(c=getchar(),c>='0' && c<='9') ret=ret*10+c-'0';
	return ret;
}

inline void out(long long x) {
	if(x>9) out(x/10);
	putchar(x%10+'0');
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b,c;
	T=read();

	while(T--) {
		N=read();
		ans=0;
		init();
		for(int i=1;i<N;++i) {
			a=read(); b=read(); c=read();
			addEdge(a,b,c);
			addEdge(b,a,c);
		}

		dfs(1,-1);
		dfs1(1,-1,0);

		out(ans);
		puts("");
	}

	return 0;
}
