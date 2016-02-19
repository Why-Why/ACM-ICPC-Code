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
// Created Time  : 2015年12月27日 星期日 20时53分08秒
// File Name     : A_2.cpp

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

// 静态Trie，时间复杂度 O(n)，空间复杂度 O(kn)。
// 输入：字符串。
// 输出：匹配值(灵活改动)。
// 注意：使用init初始化。
// 原理：建树。

const int MaxNode=100005;

struct Trie
{
	int next[MaxNode][26],val[MaxNode];
	int Tcou,root;

	int newNode()
	{
		++Tcou;

		memset(next[Tcou],0,sizeof(next[Tcou]));
		val[Tcou]=0;

		return Tcou;
	}

	void init()
	{
		Tcou=-1;
		root=newNode();
		memset(val,0,sizeof(val));
	}

	Trie()
	{
		init();
	}

	void insert(int len,char s[],int id)
	{
		int p=0;

		for(int i=0;i<len;++i)
		{
			if(next[p][s[i]-'a']==0)
				next[p][s[i]-'a']=newNode();

			p=next[p][s[i]-'a'];
		}

		val[p]=id;
	}

	int match(int len,char s[])
	{
		int p=0;

		for(int i=0;i<len;++i)
		{
			if(next[p][s[i]-'a']==0)
				return 0;

			p=next[p][s[i]-'a'];
		}

		return val[p];
	}
}tree;

char s[100005];
int N,M;



int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&M);
	tree.init();

	for(int i=1;i<=N;++i) {
		scanf("%s",s);
		tree.insert(s);
	}
	while(M--) {
		scanf("%s",s);
		printf("%d\n",getans(s));
	}
	
	return 0;
}
