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
// Created Time  : 2016年04月06日 星期三 22时22分12秒
// File Name     : F.cpp

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

const int MaxN=40005;

struct Edge {
	int to,next;
}E[MaxN<<1];

int head[MaxN],Ecou;
int N,M,blen;
int val[MaxN];
int lrem[MaxN];
int num[MaxN<<2],ncou;

const int MaxM=100005;

inline int zhuan(int x) {
	return (x-1)/blen;
}

struct QUE {
	int L,R,id;

	bool operator < (const QUE &b) const {
		int x=zhuan(L),y=zhuan(b.L);
		return x==y ? R<b.R : x<y;
	}
}que[MaxM];

int ans[MaxM];

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs(int u,int pre) {
	num[++ncou]=val[u];
	lrem[u]=ncou;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			dfs(E[i].to,u);
			num[++ncou]=val[u];
		}
	num[++ncou]=val[u];
}

void solve() {
	ncou=0;
	dfs(1,-1);
}

int tans=0;

struct HASHMAP {
	static const int HASH=100003;

	int head[HASH],Hcou,next[MaxN];
	int key[MaxN],val[MaxN];

	void init() {
		memset(head,-1,sizeof(head));
		Hcou=0;
	}

	void change(int p) {
		cerr<<p<<endl;
		int h=p%HASH;
		for(int i=head[h];i!=-1;i=next[i])
			if(key[i]==p) {
				if(val[i]) --tans;
				else ++tans;
				val[i]=!val[i];
				return;
			}
		++tans;
		val[Hcou]=1;
		key[Hcou]=p;
		next[Hcou]=head[h];
		head[h]=Hcou++;
	}
}rem;

inline void update(int p,int t) {
	rem.change(num[p]);
}

void getans() {
	int dL=1,dR=1;
	rem.change(num[1]);

	for(int i=1;i<=M;++i) {
		if(dR<que[i].R) for(int j=dR+1;j<=que[i].R;++j) update(j,1);
		else for(int j=dR;j>que[i].R;--j) update(j,-1);
		dR=que[i].R;

		if(dL<que[i].L) for(int j=dL;j<que[i].L;++j) update(j,-1);
		else for(int j=dL-1;j>=que[i].L;--j) update(j,1);
		dL=que[i].L;

		ans[que[i].id]=tans;
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	scanf("%d %d",&N,&M);
	rem.init();
	for(int i=1;i<=N;++i) scanf("%d",val+i);
	init();
	for(int i=1;i<N;++i) {
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	solve();
	blen=sqrt((double)ncou);

	for(int i=1;i<=M;++i) {
		scanf("%d %d",&que[i].L,&que[i].R);
		que[i].id=i;
		que[i].L=lrem[que[i].L];
		que[i].R=lrem[que[i].R];
		if(que[i].L>que[i].R) swap(que[i].L,que[i].R);
	}
	sort(que+1,que+M+1);
		cout<<"@ "<<que[1].L<<' '<<que[1].R<<endl;
	getans();

	for(int i=1;i<=ncou;++i) cout<<num[i]<<' ';
	cout<<endl;

	for(int i=1;i<=M;++i) printf("%d\n",ans[i]);
	
	return 0;
}
