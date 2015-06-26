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
// Created Time  : 2015年05月07日 星期四 20时24分14秒
// File Name     : 2513.cpp

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

const int MaxN=5000010;

struct Trie
{
	int next[MaxN][26];
	int end[MaxN];
	int id[MaxN];
	int Tcou,root;
	int cou,idcou;

	int newNode()
	{
		++Tcou;
		memset(next[Tcou],0,sizeof(next[Tcou]));
		end[Tcou]=0;

		return Tcou;
	}

	void init()
	{
		cou=idcou=0;
		Tcou=-1;
		root=newNode();
	}

	int insert(char s[])
	{
		int p=0;

		for(int i=0;s[i];++i)
		{
			if(next[p][s[i]-'a']==0)
				next[p][s[i]-'a']=newNode();

			p=next[p][s[i]-'a'];
		}

		++end[p];

		if(end[p]==1)
			id[p]=++idcou;

		if(end[p] & 1)
			++cou;
		else
			--cou;

		return id[p];
	}
}tree;

char s1[20],s2[20];

int fa[500100];

int find(int x)
{
	if(fa[x]==-1)
		return x;

	fa[x]=find(fa[x]);

	return fa[x];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	int cou=0;

	memset(fa,-1,sizeof(fa));

	tree.init();

	while(~scanf("%s %s",s1,s2))
	{
		a=tree.insert(s1);
		b=tree.insert(s2);

		if(find(a)!=find(b))
			fa[find(a)]=find(b);
	}

	for(int i=1;i<=tree.idcou;++i)
		if(fa[i]==-1)
			++cou;

	if(cou>=2 || tree.cou>2 || tree.cou==1)
		printf("Impossible\n");
	else
		printf("Possible\n");
	
	return 0;
}
