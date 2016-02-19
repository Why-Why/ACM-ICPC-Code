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
// Created Time  : 2016年01月11日 星期一 18时42分23秒
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
#include <climits>

using namespace std;

const int MaxN=100005;

struct Treap {
	int tot,root;
	int ch[MaxN][2];				// 儿子。
	int pri[MaxN];		// 键值，优先值。
	long long key[MaxN];
	int cou[MaxN],size[MaxN];		// 节点值的个数，他及其子树节点的总数。

	void init() {
		tot=1;
		root=0;
		pri[0]=INT_MAX;				// 不能是INF。
		size[0]=0;
	}

	void update(int x) {				// 维护size。
		size[x]=size[ch[x][0]]+cou[x]+size[ch[x][1]];
	}

	void rotate(int &x,int t) {		// 节点x按照t方向旋转，0为左。
		int y=ch[x][t];

		ch[x][t]=ch[y][1-t];
		ch[y][1-t]=x;

		update(x);
		update(y);

		x=y;
	}

	void _insert(int &x,long long k) {
		if(x) {
			if(key[x]==k) ++cou[x];
			else {
				int t=key[x]<k;

				_insert(ch[x][t],k);
				if(pri[ch[x][t]]<pri[x]) rotate(x,t);
			}
		}
		else {
			x=tot++;
			key[x]=k;
			cou[x]=1;
			pri[x]=rand();			// !!!
			ch[x][0]=ch[x][1]=0;
		}
		update(x);
	}

	long long find(long long k) {
		long long ret=0;
		int u=root;

		while(u) {
			if(key[u]==k) return ret+cou[u]+size[ch[u][1]];
			if(key[u]>k) { ret+=cou[u]+size[ch[u][1]]; u=ch[u][0]; }
			else u=ch[u][1];
		}

		return ret;
	}

	void insert(long long k) {
		_insert(root,k);
	}
}tree;

int N;
long long P;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	long long a,sum;
	long long ans;

	scanf("%d",&T);
	while(T--) {
		scanf("%d %lld",&N,&P);
		sum=0;
		ans=0;
		tree.init();
		tree.insert(0);

		for(int i=1;i<=N;++i) {
			scanf("%lld",&a);
			sum+=a;
			ans+=tree.find(sum-P);
			tree.insert(sum);
		}
		printf("Case #%d: %lld\n",cas++,ans);
	}
	
	return 0;
}
