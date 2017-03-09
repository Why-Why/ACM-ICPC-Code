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
// Created Time  : 2017年02月28日 星期二 17时11分58秒
// File Name     : t.cpp

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
	int to,next,len,id;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
int belong[MaxN];
int N;

void init() {
	for(int i=1;i<=N;++i) head[i]=-1,belong[i]=-1;
	Ecou=0;
}

void addEdge(int u,int v,int len,int id) {
	E[Ecou].to=v;
	E[Ecou].len=len;
	E[Ecou].id=id;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int subFa[MaxN],subSon[MaxN];
int subEidAns[MaxN];

struct SubTree {
	private:
		int tmaxDep,trem;

		int dfs1(int u,int pre,int dep) {
			int ret=dep;

			if(dep>tmaxDep) {
				tmaxDep=dep;
				trem=u;
			}

			for(int i=head[u];i!=-1;i=E[i].next)
				if(belong[E[i].id]==-1 && E[i].to!=pre) {
					subFa[E[i].to]=i^1;
					ret=max(ret,dfs1(E[i].to,u,dep+E[i].len));
				}

			return ret;
		}

	public:
		int N,root;
		int tid;
		int maxDiameter;

		void getDiameter() {
			tmaxDep=-1;
			dfs1(root,-1,0);

			int a=trem,b;
			tmaxDep=-1;
			dfs1(a,-1,0);
			b=trem;

			maxDiameter=0;
			for(int u=b;u!=a;u=E[subFa[u]].to) {
				maxDiameter+=E[subFa[u]].len;
				belong[E[subFa[u]].id]=tid;
				subSon[E[subFa[u]].to]=subFa[u]^1;
			}

			int tmp=0,maxn=0;
			for(int u=b;u!=a;u=E[subFa[u]].to) {
				maxn=max(maxn,dfs1(u,-1,tmp));
				subEidAns[E[subFa[u]].id]=maxn;
				tmp+=E[subFa[u]].len;
			}

			tmp=0;
			maxn=0;
			for(int u=a;u!=b;u=E[subSon[u]].to) {
				maxn=max(maxn,dfs1(u,-1,tmp));
				subEidAns[E[subSon[u]].id]=max(subEidAns[E[subSon[u]].id],maxn);
				tmp+=E[subSon[u]].len;
			}
		}

		int divid(int eid) {
			if(belong[eid]==-1) return maxDiameter;
			return subEidAns[eid];
		}
}tree;

int remEl[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int a,b,c;
	T=1;

	while(T--) {
		scanf("%d",&N);
		init();
		for(int i=1;i<N;++i) {
			scanf("%d %d %d",&a,&b,&c);
			addEdge(a,b,c,i);
			addEdge(b,a,c,i);
			remEl[i]=c;
		}

		tree.N=N;
		tree.root=1;
		tree.tid=1;

		tree.getDiameter();

		long long ans=-1,rem=-1,x,y;

		for(int i=1;i<N;++i) {
			x=remEl[i];
			y=tree.divid(i);

			if(rem==-1 || x*y<ans) {
				ans=x*y;
				rem=i;
			}
		}

		printf("Case #%d: %d\n",cas++,(int)rem);
	}

	return 0;
}
