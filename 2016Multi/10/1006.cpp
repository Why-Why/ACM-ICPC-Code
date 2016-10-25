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
// Created Time  : 2016年08月18日 星期四 15时07分32秒
// File Name     : 1006.cpp

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
const int MaxNode=MaxN*20;
const int INF=0x3f3f3f3f;

struct TreapForest
{
	int tot;
	int root[MaxN<<2];						// !!!!!!!!!!
	int ch[MaxNode][2];
	int key[MaxNode],pri[MaxNode];
	int cou[MaxNode],size[MaxNode];

	void init()
	{
		pri[0]=INT_MAX;						// Yes?
		size[0]=0;
		tot=1;
	}

	void update(int x)
	{
		size[x]=size[ch[x][0]]+size[ch[x][1]]+cou[x];
	}

	void rotate(int &x,int t)
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
			pri[x]=rand();
			ch[x][0]=ch[x][1]=0;
		}

		update(x);
	}

	void insert(int id,int k)
	{
		_insert(root[id],k);
	}

	int countMax(int id,int k)
	{
		int u=root[id];
		int ret=0;

		while(u)
		{
			if(key[u]==k)
				return ret+cou[u]+size[ch[u][1]];

			if(key[u]>k)
			{
				ret+=cou[u]+size[ch[u][1]];
				u=ch[u][0];
			}
			else
				u=ch[u][1];
		}

		return ret;
	}

}tree;

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

int N;

void build(int L,int R,int po)
{
	tree.root[po]=0;

	if(L==R)
		return;

	int M=(L+R)>>1;

	build(lson);
	build(rson);
}

void insert(int ip,int it,int L,int R,int po)
{
	tree.insert(po,it);

	if(L==R)
		return;
	
	int M=(L+R)>>1;

	if(ip<=M)
		insert(ip,it,lson);
	else
		insert(ip,it,rson);
}

long long query(int ql,int qr,int qt,int L,int R,int po) {
	if(ql<=L && qr>=R) return tree.countMax(po,qt);

	int M=(L+R)>>1;
	if(qr<=M) return query(ql,qr,qt,lson);
	if(ql>M) return query(ql,qr,qt,rson);

	return query(ql,qr,qt,lson)+query(ql,qr,qt,rson);
}

//////////////////////////////

struct QUE {
	int x,y1,y2;

	bool operator < (const QUE & b) const {
		return x<b.x;
	}
};

struct NUM {
	int x,h,r;

	bool operator < (const NUM & b) const {
		return x<b.x;
	}
};

QUE que[MaxN];
NUM num[MaxN];
int qcou,ncou;

int hcou,hnum[MaxN*3];

inline int hash1(int x) {
	return lower_bound(hnum+1,hnum+hcou+1,x)-hnum;
}

inline void add(int p) {
	insert(hash1(num[p].h),num[p].r,1,hcou,1);
}

inline long long getans(int p) {
	return query(hash1(que[p].y1),hash1(que[p].y2),que[p].x,1,hcou,1);
}

inline int read() {
	char c; int sgn;
	if(c=getchar(),c==EOF) return 0; //EOF
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	sgn=(c=='-')?-1:1;
	int ret=(c=='-')?0:(c-'0');
	while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
	ret*=sgn;
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b,c,d;
	T=read();

	while(T--) {
		N=read();
		qcou=ncou=0;
		hcou=0;

		for(int i=1;i<=N;++i) {
			a=read(); b=read(); c=read(); d=read();
			if(a==c) {
				que[++qcou].x=a;
				if(b>d) swap(b,d);
				que[qcou].y1=b;
				que[qcou].y2=d;

				hnum[++hcou]=b;
				hnum[++hcou]=d;
			}
			else {
				if(a>c) swap(a,c);
				num[++ncou].h=b;
				num[ncou].x=a;
				num[ncou].r=c;

				hnum[++hcou]=b;
			}
		}
		sort(que+1,que+qcou+1);
		sort(num+1,num+ncou+1);

		sort(hnum+1,hnum+hcou+1);
		hcou=unique(hnum+1,hnum+hcou+1)-hnum-1;

		build(1,hcou,1);

		long long ans=0;
		int p=1;

		for(int i=1;i<=qcou;++i) {
			while(p<=ncou && num[p].x<=que[i].x) {
				add(p);
				++p;
			}
			ans+=getans(i);
		}
		printf("%I64d\n",ans);
	}

	return 0;
}
