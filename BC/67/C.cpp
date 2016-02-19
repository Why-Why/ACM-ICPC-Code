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
// Created Time  : 2015年12月26日 星期六 22时01分56秒
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

const int MaxN=300005;
const int MaxS=300005*20;

struct TreapForest {
	int tot,root[MaxN<<2];
	int ch[MaxS][2];
	int key[MaxS],pri[MaxS];
	int cou[MaxS],size[MaxS];

	void init() {
		tot=1;
		memset(root,0,sizeof(root));
		pri[0]=INT_MAX;
		size[0]=0;
	}

	void update(int x) {
		size[x]=size[ch[x][0]]+size[ch[x][1]]+cou[x];
	}

	void rotate(int &x,int t) {
		int y=ch[x][t];

		ch[x][t]=ch[y][1-t];
		ch[y][1-t]=x;
		update(x);
		update(y);
		x=y;
	}

	void _insert(int &x,int k) {
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
			pri[x]=rand();
			ch[x][0]=ch[x][1]=0;
		}
		update(x);
	}

	int find(int id,int L,int R) {
		int ret=0,u=root[id];
		int ret1=0;

		while(u) {
			if(key[u]==L) { ret+=size[ch[u][0]]; break; }
			if(key[u]<L) { ret+=cou[u]+size[ch[u][0]]; u=ch[u][1]; }
			else u=ch[u][0];
		}

		u=root[id];
		while(u) {
			if(key[u]==R) { ret1+=size[ch[u][1]]; break; }
			if(key[u]>R) { ret1+=cou[u]+size[ch[u][1]]; u=ch[u][0]; }
			else u=ch[u][1];
		}

		return size[root[id]]-ret-ret1;
	}

	void insert(int id,int k) {
		_insert(root[id],k);
	}
}tree;

int C[MaxN];

int N;
int remL[MaxN],couL;
int LL[MaxN],RR[MaxN];

inline int lowbit(int x) {
	return x&(-x);
}

void add(int x,int k) {
	for(;x<=couL;x+=lowbit(x)) tree.insert(x,k);
}

int query(int x,int L,int R) {
	if(R<L) return 0;
	int ret=0;
	for(;x;x-=lowbit(x)) ret+=tree.find(x,L,R);
	return ret;
}

inline int hash1(int x) {
	return lower_bound(remL+1,remL+couL+1,x)-remL;
}

inline int hash2(int x) {
	return upper_bound(remL+1,remL+couL+1,x)-remL-1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M;

	while(~scanf("%d %d",&N,&M)) {
		tree.init();
		couL=0;
		for(int i=1;i<=N;++i) {
			scanf("%d %d",LL+i,RR+i);
			remL[++couL]=LL[i];
		}
		sort(remL+1,remL+couL+1);
		couL=unique(remL+1,remL+couL+1)-remL-1;

		for(int i=1;i<=N;++i) add(hash1(LL[i]),RR[i]);
		int MM,a,las=10000000;
		int ans=0;
		while(M--) {
			ans=0;
			las=10000000;
			scanf("%d",&MM);
			while(MM--) {
				scanf("%d",&a);
				ans+=query(hash2(las),las,a-1);
				las=a;
			}
			ans+=query(hash2(a),a,10000000);
			printf("%d\n",ans);
		}
	}
	
	return 0;
}
