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
// Created Time  : 2016年08月29日 星期一 23时03分13秒
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

const int MaxN=200005;
const int mod=1000000007;

struct Edge {
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
int du[MaxN];
int N;

void addEdge(int u,int v) {
	++du[v];
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

bool vis[MaxN],ncan[MaxN];
queue <int> que;

int dfs(int u) {
	int ret=1;

	if(du[u]==1) ncan[u]=1,que.push(u);

	vis[u]=1;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(vis[E[i].to]==0)
			ret+=dfs(E[i].to);

	return ret;
}

long long _pow(int t) {
	long long ret=1,base=2;

	while(t) {
		if(t&1) (ret*=base)%=mod;
		(base*=base)%=mod;
		t>>=1;
	}

	return ret;
}

int getans() {
	long long ans=1;
	int t,z,n;

	for(int i=1;i<=N;++i)
		if(!vis[i]) {
			while(!que.empty()) que.pop();
			z=dfs(i);
			n=0;

			while(!que.empty()) {
				t=que.front();
				que.pop();
				++n;

				for(int j=head[t];j!=-1;j=E[j].next) {
					--du[E[j].to];
					if(ncan[E[j].to]==0 && du[E[j].to]==1) {
						que.push(E[j].to);
						ncan[E[j].to]=1;
					}
				}
			}

			(ans*=(_pow(z)-_pow(n+1)+mod)%mod)%=mod;
		}

	return ans;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	memset(head,-1,sizeof(head));
	Ecou=0;

	int a;

	scanf("%d",&N);
	for(int i=1;i<=N;++i) {
		scanf("%d",&a);
		addEdge(a,i);
		addEdge(i,a);
	}

	printf("%d\n",getans());

	return 0;
}
