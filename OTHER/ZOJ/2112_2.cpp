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
// Created Time  : 2015年07月27日 星期一 23时43分28秒
// File Name     : 2112_2.cpp

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

const int MaxN=50010+10010;
const int MaxM=10005;
const int MaxNode=2600010;

int Tcou;
int TreeRoot[MaxN];
int lson[MaxNode],rson[MaxNode],BIT[MaxNode];

int BaseTree[MaxN];							// 对于初始序列的前缀建的树的根。

int N;
int num[MaxN];
int Hnum[MaxN],Hcou;							// Hash相关，Hnum数组从1开始。

inline int hash(int x)
{
	return lower_bound(Hnum+1,Hnum+Hcou+1,x)-Hnum;
}

inline int lowbit(int x)
{
	return x&(-x);
}

int insert(int old,int val,int d)				// 在old这个根指向的那棵树上更新一个新的分支，更新的值为val这个数的频率，频率加上d。（线段树的区间是数。）
{
	int newRoot=Tcou++,ret=newRoot;				// newRoot是新建的分支的根节点，并且保存下来用来做返回值。
	int L=1,R=Hcou,M;

	BIT[newRoot]=BIT[old]+d;					// 从这到下就是类似线段树的更新操作了，这一步是更新根节点维护的频率。（BIT数组维护的是数的区间的出现频率总和。）

	while(R>L)									// 就像是线段树，一步步二分找到val所在的那个确切位置，然后沿途更新（新建）节点，而对另一半子树就直接指向原来的就好了。
	{
		M=(L+R)>>1;

		if(val<=M)								// 进入左子树，newRoot的左儿子被新建，然后右儿子指向原来那个，反正值都是一样的。
		{
			lson[newRoot]=Tcou++;
			rson[newRoot]=rson[old];
			newRoot=lson[newRoot];
			old=lson[old];
			R=M;
		}
		else									// 进入右边，和上面一样。
		{
			lson[newRoot]=lson[old];
			rson[newRoot]=Tcou++;
			newRoot=rson[newRoot];
			old=rson[old];
			L=M+1;
		}

		BIT[newRoot]=BIT[old]+d;				// 新节点的值是要维护的。
	}

	return ret;
}

void add(int x,int val,int d)					// 给树状数组上面的关于x的所有线段树进行insert操作。
{
	for(;x<=N;x+=lowbit(x))
		TreeRoot[x]=insert(TreeRoot[x],val,d);	// 在这颗线段树的基础上新建一个线段树（只是一些分支），这个线段树的根节点指向这个新线段树。
}

void update(int up,int ut)						// 更新up位置上数为ut。
{
	add(up,hash(num[up]),-1);					// 把这个位置上面原来的数的频率减去1。
	add(up,hash(ut),1);							// 把ut这个数的频率加上1。
	num[up]=ut;									// num数组就是记录这个位置的数是多少的。
}

int use[MaxN];									// 省事的一个数组，记录当前要询问的区间。

int sum(int x)									// 求1-x的线段树的某个区间的连续和。
{
	int ret=0;

	for(;x;x-=lowbit(x))
		ret+=BIT[lson[use[x]]];

	return ret;
}

int query(int ql,int qr,int K)					// ql到qr这个区间的第K小。
{
	int L=1,R=Hcou,M;
	int temp;

	int BaseL=BaseTree[ql-1],BaseR=BaseTree[qr];// 记录对初始序列的线段树当前所要查询的位置。
	
	for(int i=ql-1;i;i-=lowbit(i))				// 记录当前要找的区间。
		use[i]=TreeRoot[i];
	for(int i=qr;i;i-=lowbit(i))
		use[i]=TreeRoot[i];

	while(R>L)									// 二分查找。
	{
		M=(L+R)>>1;
		temp=sum(qr)-sum(ql-1);					// 获得在ql到qr这个区间里面的1-M这些数的出现了多少次。
		temp+=BIT[lson[BaseR]]-BIT[lson[BaseL]];// 再加上初始序列线段树的。

		if(K<=temp)								// 说明第K个在1-M里面找。
		{
			for(int i=ql-1;i;i-=lowbit(i))
				use[i]=lson[use[i]];
			for(int i=qr;i;i-=lowbit(i))
				use[i]=lson[use[i]];
			BaseL=lson[BaseL];
			BaseR=lson[BaseR];
			R=M;
		}
		else
		{
			for(int i=ql-1;i;i-=lowbit(i))
				use[i]=rson[use[i]];
			for(int i=qr;i;i-=lowbit(i))
				use[i]=rson[use[i]];
			BaseL=rson[BaseL];
			BaseR=rson[BaseR];
			K-=temp;
			L=M+1;
		}
	}

	return L;									// 这就是第K个。
}

int build_BIT(int L,int R)						// 建一颗空的线段树。
{
	int root=Tcou++;

	BIT[root]=0;

	if(L!=R)
	{
		int M=(L+R)>>1;

		lson[root]=build_BIT(L,M);				// 指向左儿子。
		rson[root]=build_BIT(M+1,R);			// 指向右儿子。
	}

	return root;
}

void ChairTree_init(int num[])					// 初始化主席树。
{
	TreeRoot[0]=build_BIT(1,Hcou);				// 建空树。

	for(int i=1;i<=N;++i)						// 把所有线段树指向空树。
	{
		TreeRoot[i]=TreeRoot[0];
		BaseTree[i]=insert(BaseTree[i-1],hash(num[i]),1);
	}
}

void Hash_init()
{
	sort(Hnum+1,Hnum+Hcou+1);
	Hcou=unique(Hnum+1,Hnum+Hcou+1)-Hnum-1;
}

void init()
{
	Tcou=Hcou=0;
}

struct Query
{
	bool type;
	int a,b,c;

}q[MaxM];


int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	char ts[10];
	int M;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);
		init();

		for(int i=1;i<=N;++i)
		{
			scanf("%d",&num[i]);
			Hnum[++Hcou]=num[i];
		}

		for(int i=1;i<=M;++i)
		{
			scanf("%s",ts);

			if(ts[0]=='Q')
			{
				q[i].type=0;
				scanf("%d %d %d",&q[i].a,&q[i].b,&q[i].c);
			}
			else
			{
				q[i].type=1;
				scanf("%d %d",&q[i].a,&q[i].b);
				Hnum[++Hcou]=q[i].b;
			}
		}

		Hash_init();
		ChairTree_init(num);

		for(int i=1;i<=M;++i)
		{
			if(q[i].type)
				update(q[i].a,q[i].b);
			else
				printf("%d\n",Hnum[query(q[i].a,q[i].b,q[i].c)]);
		}
	}
	
	return 0;
}
