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
// Created Time  : 2015年10月22日 星期四 10时33分26秒
// File Name     : ZPS.cpp

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

const int MaxN=10100;

struct LeftTree
{
	int tot;
	int ch[2][MaxN];
	int key[MaxN],dist[MaxN];

	void init()
	{
		tot=0;
	}

	int Merge(int A,int B)
	{
		if(!A) return B;
		if(!B) return A;
		if(key[B]<key[A]) swap(A,B);

		ch[1][A]=Merge(ch[1][A],B);
		if(dist[ch[1][A]]>dist[ch[0][A]]) swap(ch[0][A],ch[1][A]);
		if(!ch[1][A]) dist[A]=0;
		else dist[A]=dist[ch[1][A]]+1;

		return A;
	}

	int build_a_node(int x)
	{
		key[++tot]=x;
		dist[tot]=0;
		ch[0][tot]=ch[1][tot]=0;
		
		return tot;
	}

	int build(int num[],int n)
	{
		for(int i=0;i<n;++i) num[i]=build_a_node(num[i]);

		int first=2,last=1;
		int a,b;
		num[0]=Merge(num[0],num[1]);

		while((last+n-first)%n>1)
		{
			a=num[first++];
			if(first>=n) first-=n;
			b=num[first++];
			if(first>=n) first-=n;

			num[last++]=Merge(a,b);
			if(last>=n) last-=n;
		}

		return num[first++];
	}

	void insert(int & root,int x)				// Root may be changed.
	{
		root=Merge(root,build_a_node(x));
	}

	int deleteMin(int & root)					// Root may be changed.
	{
		int t=key[root];
		root=Merge(ch[0][root],ch[1][root]);

		return t;
	}
};

LeftTree tree;
int num[100];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	tree.init();
	int n,m,a,b;
	int t;
	cin>>n;
	for(int i=0;i<n;++i) cin>>num[i];
	t=tree.build(num,n);

	cin>>m;
	while(m--)
	{
		cin>>a;
		if(a==1) cout<<tree.deleteMin(t)<<' '<<t<<endl;
		else
		{
			cin>>b;
			tree.insert(t,b);
		}
	}
	
	return 0;
}
