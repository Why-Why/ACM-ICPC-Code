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
// Created Time  : 2015年12月03日 星期四 11时31分39秒
// File Name     : J.cpp

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

const int MaxN=500005*2;
const int INF=0x3f3f3f3f;

struct Treap
{
	int tot,root;
	int ch[MaxN][2];				// 儿子。
	int key[MaxN],pri[MaxN];		// 键值，优先值。
	int cou[MaxN],size[MaxN];		// 节点值的个数，他及其子树节点的总数。
	int rem1[MaxN],rem2[MaxN];
	int nr1[MaxN],nr2[MaxN];		// !!!
	int tV1,tV2;

	void init()
	{
		tot=1;
		root=0;
		pri[0]=INT_MAX;				// 不能是INF。
		size[0]=0;
		rem1[0]=rem2[0]=INF;
		nr1[0]=nr2[0]=INF;
	}

	void update(int x)				// 维护size。
	{
		size[x]=size[ch[x][0]]+cou[x]+size[ch[x][1]];
		rem1[x]=min(nr1[x],min(rem1[ch[x][0]],rem1[ch[x][1]]));
		rem2[x]=min(nr2[x],min(rem2[ch[x][0]],rem2[ch[x][1]]));
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
			if(key[x]==k) {
				++cou[x];
				nr1[x]=min(nr1[x],tV1);
				nr2[x]=min(nr2[x],tV2);
				rem1[x]=min(rem1[x],tV1);
				rem2[x]=min(rem2[x],tV2);
			}
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
			nr1[x]=rem1[x]=tV1;
			nr2[x]=rem2[x]=tV2;
		}

		update(x);
	}

	void insert(int k,int V1,int V2)
	{
		tV1=V1;
		tV2=V2;
		_insert(root,k);
	}

	int getmin(int k) {
		int ret=INF,u=root;

		while(u) {
			if(key[u]==k) return min(ret,min(nr1[u],rem1[ch[u][0]]));
			if(key[u]>k) u=ch[u][0];
			else {
				ret=min(ret,min(nr1[u],rem1[ch[u][0]]));
				u=ch[u][1];
			}
		}

		return ret;
	}
	
	int getmax(int k) {
		int ret=INF,u=root;

		while(u) {
			if(key[u]==k) return min(ret,rem2[ch[u][1]]);
			if(key[u]<k) u=ch[u][1];
			else {
				ret=min(ret,min(nr2[u],rem2[ch[u][1]]));
				u=ch[u][0];
			}
		}

		return ret;
	}
}tree;

///////////////////////////////////

struct OPE {
	int type,id,x,y;
}ope[MaxN];

int ans[MaxN];

inline bool cmp(const OPE & a,const OPE & b) {
	return a.x<b.x;
}

inline bool cmp1(const OPE & a,const OPE & b) {
	return a.id<b.id;
}

inline void solve(int L,int M,int R) {
	sort(ope+L,ope+R+1,cmp);

	tree.init();
	for(int i=L;i<=R;++i)
		if(ope[i].id>M && ope[i].type==2)
			ans[ope[i].id]=min(ans[ope[i].id],min(tree.getmin(ope[i].y)+ope[i].x+ope[i].y,tree.getmax(ope[i].y)+ope[i].x-ope[i].y));
		else if(ope[i].id<=M && ope[i].type==1)
			tree.insert(ope[i].y,-ope[i].x-ope[i].y,ope[i].y-ope[i].x);

	tree.init();
	for(int i=R;i>=L;--i)
		if(ope[i].id>M && ope[i].type==2) 
			ans[ope[i].id]=min(ans[ope[i].id],min(tree.getmin(ope[i].y)+ope[i].y-ope[i].x,tree.getmax(ope[i].y)-ope[i].y-ope[i].x));
		else if(ope[i].id<=M && ope[i].type==1) 
			tree.insert(ope[i].y,-ope[i].y+ope[i].x,ope[i].x+ope[i].y);

	sort(ope+L,ope+R+1,cmp1);
}

void CDQ(int L,int R) {
	if(L==R) return;

	int M=(L+R)>>1;
	CDQ(L,M);
	solve(L,M,R);
	CDQ(M+1,R);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,M,len=0;
	memset(ans,0x3f,sizeof(ans));

	scanf("%d %d",&N,&M);
	while(N--) {
		++len;
		scanf("%d %d",&ope[len].x,&ope[len].y);
		ope[len].id=len;
		ope[len].type=1;
	}
	while(M--) {
		++len;
		scanf("%d %d %d",&ope[len].type,&ope[len].x,&ope[len].y);
		ope[len].id=len;
	}

	CDQ(1,len);
	for(int i=1;i<=len;++i)
		if(ans[i]!=INF) printf("%d\n",ans[i]);
	
	return 0;
}
