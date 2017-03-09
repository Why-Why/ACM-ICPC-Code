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
// Created Time  : 2015年09月17日 星期四 12时00分33秒
// File Name     : E.cpp

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

struct Node
{
	int x,y,z;
	int id;
};

Node node[MaxN];
int N;

int ans[MaxN],cou[MaxN];

int remZ[MaxN];
int couZ;

int map_find(int p)
{
	int L=1,R=couZ,M;

	while(R>L)
	{
		M=(L+R)>>1;
		if(remZ[M]==p) return M;
		if(remZ[M]>p) R=M-1;
		else L=M+1;
	}
	return L;
}

bool cmpx(const Node &a,const Node &b)
{
	if(a.x==b.x)
		if(a.y==b.y) return a.z<b.z;
		else return a.y<b.y;
	else return a.x<b.x;
}
bool cmpy(const Node &a,const Node &b) { return a.y<b.y; }
bool cmpz(const Node &a,const Node &b) { return a.z<b.z; }

inline int lowbit(int x)
{
	return x&(-x);
}

int C[MaxN];
int A[MaxN];

void change(int p,int a,int c)
{
	p=map_find(p);
	for(;p<=couZ;p+=lowbit(p))
		if(A[p]<a) { A[p]=a; C[p]=c; }
		else if(A[p]==a) C[p]+=c;
}

int query(int p,int &c)
{
	int ret=-1;
	p=map_find(p);
	for(;p>0;p-=lowbit(p))
		if(ret<A[p]) { ret=A[p]; c=C[p]; }
		else if(ret==A[p]) c+=C[p];

	return ret;
}

void clear(int L,int R)
{
	for(int i=L;i<=R;++i)
		for(int p=map_find(node[i].z);p<=couZ;p+=lowbit(p))
			C[p]=A[p]=0;
}

void solve(int L,int R)
{
	int M=(L+R)>>1;

	sort(node+L,node+M+1,cmpy);
	sort(node+M+1,node+R+1,cmpy);

	int p=L;
	int temp,tc;
	for(int i=M+1;i<=R;++i)
	{
		while(p<=M && node[p].y<=node[i].y)
		{
			change(node[p].z,ans[node[p].id],cou[node[p].id]);
			++p;
		}

		temp=query(node[i].z,tc)+1;
		if(temp>ans[node[i].id]) { ans[node[i].id]=temp; cou[node[i].id]=tc; }
		else if(temp==ans[node[i].id]) cou[node[i].id]+=tc;
	}
	clear(L,M);

	sort(node+M+1,node+R+1,cmpx);
}

void CDQ(int L,int R)
{
	if(L==R) return;
	int M=(L+R)>>1;

	CDQ(L,M);
	solve(L,R);
	CDQ(M+1,R);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);
		couZ=0;
		for(int i=1;i<=N;++i)
		{
			scanf("%d %d %d",&node[i].x,&node[i].y,&node[i].z);
			node[i].id=i;
			ans[i]=1;
			cou[i]=1;
			remZ[++couZ]=node[i].z;
			A[i]=C[i]=0;
		}
		sort(node+1,node+N+1,cmpx);
		sort(remZ+1,remZ+couZ+1);
		couZ=unique(remZ+1,remZ+couZ+1)-remZ-1;

		CDQ(1,N);

		int maxn=0,coun;
		for(int i=1;i<=N;++i)
			if(maxn<ans[i]) { maxn=ans[i]; coun=cou[i]; }
			else if(maxn==ans[i]) coun+=cou[i];

		printf("%d %d\n",maxn,coun%(1<<30));
	}
	
	return 0;
}
