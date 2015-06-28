// ━━━━━━神兽出没━━━━━━
// 　　 ┏┓       ┏┓
// 　　┏┛┻━━━━━━━┛┻┓
// 　　┃           ┃
// 　　┃     ━     ┃
//     ████━████   ┃
// 　　┃           ┃
// 　　┃    ┻      ┃
// 　　┃           ┃
// 　　┗━┓       ┏━┛
// 　　  ┃       ┃
// 　　  ┃       ┃
// 　　　┃       ┗━━━┓
// 　　　┃           ┣┓
// 　　　┃           ┏┛
// 　　　┗┓┓┏━━━━━┳┓┏┛
// 　　　 ┃┫┫     ┃┫┫
// 　　　 ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年06月27日 星期六 23时35分20秒
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

const int MaxN=300000;
const int INF=0x3f3f3f3f;

struct stt
{
	int n1,n2;

	bool operator < (const stt &b) const
	{
		if(n1!=b.n1)
			return n1<b.n1;

		return n2<b.n2;
	}

	bool operator == (const stt &b) const
	{
		return n1==b.n1 && n2==b.n2;
	}
};

struct Treap
{
	int tot,root;
	int ch[MaxN][2];				// 儿子。
	stt key[MaxN];
	int pri[MaxN];		// 键值，优先值。
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

	void _insert(int &x,const stt & k)
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

	int _getKth(int &x,int k)			// 第k大元素。
	{
		if(k<=size[ch[x][0]])
			return _getKth(ch[x][0],k);

		k-=size[ch[x][0]]+cou[x];

		if(k<=0)
			return key[x];

		return _getKth(ch[x][1],k);
	}

	void insert(const stt & k)
	{
		_insert(root,k);
	}

	int getKth(int k)
	{
		return _getKth(root,k);
	}
};

Treap tree1,tree2;
int ans[MaxN];
int N,Q;

int cou1,cou2;

struct state
{
	int x,y;
	bool type;
};

state remQ[MaxN];

int find(int x)
{
	int L=1,R=cou,M;

	if(cou==0)
		return 0;

	if(tree.getKth(1)>x)
		return 0;

	while(R>L)
	{
		M=(L+R+1)>>1;

		if(tree.getKth(M)<=x)
			L=M;
		else
			R=M-1;
	}

	return tree.getKth(L);
}

int getnum1(state & rQ)
{
	
}

void getans1()
{
	int t;
	stt ttt;

	tree1.init();
	tree2.init();
	cou1=0;
	cou2=0;

	for(int i=1;i<=Q;++i)
		if(remQ[i].type==1)
		{
			t=getnum2(remQ[i]);
			ans[i]=t;

			++cou1;
			ttt.n1=t;
			ttt.n2=remQ[i].x;
			tree1.insert(ttt);
		}
		else
		{
			t=getnum1(remQ[i]);
			ans[i]=t;

			++cou2;
			ttt.n1=t;
			ttt.n2=remQ[i].y;
			tree2.insert(ttt);
		}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char s[10];

	scanf("%d %d",&N,&Q);

	for(int i=1;i<=Q;++i)
	{
		scanf("%d %d %s",&remQ[i].x,&remQ[i].y,s);
		
		if(s[0]=='U')
			remQ[i].type=1;
		else
			remQ[i].type=0;
	}

	getans1();

	for(int i=1;i<=Q;++i)
		printf("%d\n",ans[i]);
	
	return 0;
}
