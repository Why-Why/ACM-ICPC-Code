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
// Created Time  : 2015年12月02日 星期三 11时05分00秒
// File Name     : G.cpp

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

struct Treap
{
	int tot,root;
	int ch[MaxN][2];				// 儿子。
	int key[MaxN],pri[MaxN];		// 键值，优先值。
	int cou[MaxN],size[MaxN];		// 节点值的个数，他及其子树节点的总数。

	void init()
	{
		tot=1;
		root=0;
		pri[0]=INT_MAX;				// 不能是INF。
		size[0]=0;
	}

	void update(int x)				// 维护size。
	{
		size[x]=size[ch[x][0]]+cou[x]+size[ch[x][1]];
	}

	void rotate(int &x,int t)		// 节点x按照t方向旋转，0为左。
	{
		int y=ch[x][t];

		ch[x][t]=ch[y][1-t];
		ch[y][1-t]=x;

		update(x);
		update(y);

		x=y;
	}

	void _insert(int &x,int k)
	{
		if(x)
		{
			if(key[x]==k)
				++cou[x];
			else
			{
				int t=key[x]<k;

				_insert(ch[x][t],k);

				if(pri[ch[x][t]]<pri[x])
					rotate(x,t);
			}
		}
		else
		{
			x=tot++;
			key[x]=k;
			cou[x]=1;
			pri[x]=rand();			// !!!
			ch[x][0]=ch[x][1]=0;
		}

		update(x);
	}

	void insert(int k)
	{
		_insert(root,k);
	}

	int getmax(int k) {
		int ret=0,u=root;

		while(u) {
			if(key[u]==k) return ret+size[ch[u][1]];
			if(key[u]>k) ret+=size[ch[u][1]]+cou[u],u=ch[u][0];
			else u=ch[u][1];
		}

		return ret;
	}

	int getmin(int k) {
		int ret=0,u=root;

		while(u) {
			if(key[u]==k) return ret+size[ch[u][0]];
			if(key[u]<k) ret+=size[ch[u][0]]+cou[u],u=ch[u][1];
			else u=ch[u][0];
		}

		return ret;
	}
}tree;

int N,M;

struct OPE {
	int type,a,b,id;
}ope[MaxN];

typedef long long LL;

LL ans[MaxN],zans;
int num[MaxN],wei[MaxN];
LL rem[MaxN];

bool cmp(const OPE &a,const OPE &b) {
	return wei[a.a]<wei[b.a];
}

bool cmp1(const OPE & a,const OPE & b) {
	return a.id<b.id;
}

void solve(int L,int M,int R) {
	LL tans=0;
	tree.init();
	sort(ope+L,ope+R+1,cmp);

	for(int i=L;i<=R;++i)
		if(ope[i].id<=M && ope[i].type==2) {
			tans+=rem[wei[ope[i].a]]-ope[i].b;
			tree.insert(ope[i].a);
		}
		else if(ope[i].id>M && ope[i].type==2)
			ope[i].b+=tree.getmax(ope[i].a);

	tree.init();
	for(int i=R;i>=L;--i)
		if(ope[i].id<=M && ope[i].type==2) tree.insert(ope[i].a);
		else if(ope[i].id>M && ope[i].type==2) ope[i].b+=tree.getmin(ope[i].a);

	sort(ope+L,ope+R+1,cmp1);
	for(int i=M+1;i<=R;++i) if(ope[i].type==1) ans[ope[i].a]+=tans;
}

void CDQ(int L,int R) {
	if(L==R) return;

	int M=(L+R)>>1;
	CDQ(L,M);
	solve(L,M,R);
	CDQ(M+1,R);
}

void init() {
	tree.init();
	zans=0;
	for(int i=1;i<=N;++i) {
		rem[i]+=tree.getmax(num[i]);
		zans+=rem[i];
		tree.insert(num[i]);
	}
	tree.init();
	for(int i=N;i>=1;--i) {
		rem[i]+=tree.getmin(num[i]);
		tree.insert(num[i]);
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int len=0;

	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;++i) {
		scanf("%d",num+i);
		wei[num[i]]=i;
	}
	init();
	for(int i=1;i<=M;++i) {
		ope[++len].type=1;
		ope[len].a=i;
		ope[len].id=len;
		ope[++len].type=2;
		ope[len].id=len;
		ope[len].b=0;
		scanf("%d",&ope[len].a);
	}
	CDQ(1,len);
	for(int i=1;i<=M;++i)
		printf("%lld\n",zans-ans[i]);
	
	return 0;
}
