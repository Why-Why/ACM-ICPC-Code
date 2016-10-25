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
// Created Time  : 2016年09月01日 星期四 21时12分35秒
// File Name     : 1010.cpp

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
const int MaxM=3005;

struct Edge {
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;

int N,M,root;
int val[MaxN],base;
bool tvis[MaxN];

bool up[MaxN];
double pp[MaxN];

void init() {
	Ecou=0;
	base=0;
	for(int i=1;i<=N;++i) {
		head[i]=-1;
		tvis[i]=up[i]=0;
	}
}

inline void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

const int pian=3001;

int stk[MaxM],top;
double rem[MaxM][MaxM<<1];
int rcou;

int dfs(int u,int pre,int jian) {
	int ret=val[u];
	int rtop=top;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
			ret=max(ret,dfs(E[i].to,u,jian-(up[u] ? 1 : 0)));

	if(up[u]==0) return ret;

	double *trem=rem[rcou];

	if(top==rtop) {
		for(int i=jian;i<=ret-base;++i) trem[i+pian]=0;
		for(int i=max(jian,ret-base+1);i<=M;++i) trem[i+pian]=1;
		if(ret-base>=jian) trem[ret-base+pian]=(1-pp[u]);
		goto End;
	}

	double x,y;

	for(int i=jian;i<=M;++i) {
		trem[i+pian]=0;
		if(i+base<ret) trem[i+pian]=0;
		else if(i+base>ret) {
			x=pp[u];
			y=1-pp[u];
			for(int j=rtop;j<top;++j) {
				x*=rem[stk[j]][i-1+pian];
				y*=rem[stk[j]][i+pian];
			}
			trem[i+pian]=x+y;
		}
		else {
			x=1-pp[u];
			for(int j=rtop;j<top;++j) x*=rem[stk[j]][i+pian];
			trem[i+pian]=x;
		}
	}

End:
	++rcou;
	top=rtop;
	stk[top++]=rcou-1;

	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	double c;

	while(~scanf("%d %d",&N,&M)) {
		init();
		for(int i=1;i<N;++i) {
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
			tvis[a]=1;
		}

		for(int i=1;i<=N;++i) {
			scanf("%d",val+i);
			if(tvis[i]==0) root=i;
			base=max(base,val[i]);
		}

		up[root]=1;
		pp[root]=0;
		for(int i=1;i<=M;++i) {
			scanf("%d %lf",&a,&c);
			up[a]=1;
			pp[a]=c;
		}

		top=rcou=0;
		dfs(root,-1,-1);

		double ans=0,*trem=rem[rcou-1];
		for(int i=0;i<=M;++i) {
			ans+=(base+i)*(trem[i+pian]-trem[i-1+pian]);
		}
		printf("%.6f\n",ans);
	}

	return 0;
}
