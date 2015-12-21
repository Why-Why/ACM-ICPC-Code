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
// Created Time  : 2015年07月27日 星期一 11时39分08秒
// File Name     : 2112_1.cpp

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

	void _erase(int &x,int k)
	{
		if(!x)
			return;

		if(key[x]==k)
			if(cou[x]>1)
				--cou[x];
			else
			{
				if(ch[x][0]==0 && ch[x][1]==0)
				{
					x=0;
					return;
				}

				int t=pri[ch[x][0]]>pri[ch[x][1]];
				rotate(x,t);
				_erase(x,k);
			}
		else
			_erase(ch[x][key[x]<k],k);

		update(x);
	}

	void insert(int id,int k)
	{
		_insert(root[id],k);
	}

	void erase(int id,int k)
	{
		_erase(root[id],k);
	}

	int min(int id)
	{
		int u=root[id];

		while(ch[u][0])
			u=ch[u][0];

		return key[u];
	}

	int max(int id)
	{
		int u=root[id];

		while(ch[u][1])
			u=ch[u][1];

		return key[u];
	}

	int countMin(int id,int k)
	{
		int u=root[id];
		int ret=0;

		while(u)
		{
			if(key[u]==k)
				return ret+cou[u]+size[ch[u][0]];

			if(key[u]<k)
			{
				ret+=cou[u]+size[ch[u][0]];
				u=ch[u][1];
			}
			else
				u=ch[u][0];
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

void erase(int ip,int it,int L,int R,int po)
{
	tree.erase(po,it);

	if(L==R)
		return;

	int M=(L+R)>>1;

	if(ip<=M)
		erase(ip,it,lson);
	else
		erase(ip,it,rson);
}

int query_min(int ql,int qr,int L,int R,int po)
{
	if(ql<=L && qr>=R)
		return tree.min(po);

	int M=(L+R)>>1;

	if(qr<=M)
		return query_min(ql,qr,lson);
	else if(ql>M)
		return query_min(ql,qr,rson);

	return min(query_min(ql,qr,lson),query_min(ql,qr,rson));
}

int query_max(int ql,int qr,int L,int R,int po)
{
	if(ql<=L && qr>=R)
		return tree.max(po);

	int M=(L+R)>>1;

	if(qr<=M)
		return query_max(ql,qr,lson);
	else if(ql>M)
		return query_max(ql,qr,rson);

	return max(query_max(ql,qr,lson),query_max(ql,qr,rson));
}

int query_bound(int ql,int qr,int qt,int L,int R,int po)
{
	if(ql<=L && qr>=R)
	{
		int t=tree.countMin(po,qt);
		return t;
	}

	int M=(L+R)>>1;

	if(qr<=M)
		return query_bound(ql,qr,qt,lson);
	else if(ql>M)
		return query_bound(ql,qr,qt,rson);

	return query_bound(ql,qr,qt,lson)+query_bound(ql,qr,qt,rson);
}

int query(int ql,int qr,int k)
{
	int L=query_min(ql,qr,1,N,1),R=query_max(ql,qr,1,N,1),M;
	int t;

	while(R>L)
	{
		M=(L+R)>>1;
		t=query_bound(ql,qr,M,1,N,1);

		if(t>=k)
			R=M;
		else
			L=M+1;
	}

	return L;
}

int num[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int M,a,b,c;
	char ts[10];

	while(~scanf("%d",&N))
	{
		tree.init();
		build(1,N,1);

		for(int i=1;i<=N;++i)
		{
			scanf("%d",&num[i]);
			insert(i,num[i],1,N,1);
		}

		scanf("%d",&M);

		while(M--)
		{
			scanf("%s",ts);

			if(ts[0]=='1')
			{
				scanf("%d %d",&a,&b);
				erase(a,num[a],1,N,1);
				insert(a,b,1,N,1);
				num[a]=b;
			}
			else
			{
				scanf("%d %d %d",&a,&b,&c);
				printf("%d\n",query(a,b,c));
			}
		}
	}
	
	return 0;
}
