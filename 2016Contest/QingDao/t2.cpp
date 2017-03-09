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
// Created Time  : 2017年02月28日 星期二 19时23分35秒
// File Name     : t2.cpp

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

int sub2Leaf[MaxN],sub2Lcou;
int sub2LL[MaxN],sub2RR[MaxN];
int sub2Dep[MaxN];
int sub2AnsL[MaxN],sub2AnsR[MaxN];

struct SubTree2 {
	int N,root;
	int tid;

	int sub2L,sub2R;

	void dfs(int u,int pre,int dep) {
		int ok=1;

		sub2Dep[u]=dep;
		sub2LL[u]=sub2Lcou+1;

		for(int i=head[u];i!=-1;i=E[i].next)
			if(belong[E[i].id] && E[i].to!=pre) {
				dfs(E[i].to,u,dep+E[i].len);
				ok=1;
			}

		if(ok) sub2Leaf[++sub2Lcou]=u;
		sub2RR[u]=sub2Lcou;
	}

	void solve() {
		sub2L=sub2Lcou+1;
		dfs(root,-1,0);
		sub2R=sub2Lcou;

		sub2AnsL[sub2L]=sub2Dep[sub2Leaf[sub2L]];
		for(int i=sub2L+1;i<=sub2R;++i)
			sub2AnsL[i]=max(sub2AnsL[i-1],sub2Dep[sub2Leaf[i]]);

		sub2AnsR[sub2R]=sub2Dep[sub2Leaf[sub2R]];
		for(int i=sub2R-1;i>=sub2L;--i)
			sub2AnsR[i]=max(sub2AnsR[i+1],sub2Dep[sub2Leaf[i]]);
	}

	int erase(int u) {
		int L=sub2LL[u],R=sub2RR[u];
		int ret=0;

		if(L>sub2L) ret=max(ret,sub2AnsL[L-1]);
		if(R<sub2R) ret=max(ret,sub2AnsR[R+1]);
		return ret;
	}

	int divid(int eid) {
		int a=remEu[eid],b=remEv[eid];
		if(sub2Dep[a]>sub2Dep[b]) swap(a,b);

		return max(sub2Dep[a],erase(b));
	}
};

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	return 0;
}
