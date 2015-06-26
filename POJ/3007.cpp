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
// Created Time  : 2015年06月15日 星期一 22时31分06秒
// File Name     : 3007.cpp

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

const int MaxNode=100000;

struct Trie
{
	int next[MaxNode][26];
	bool val[MaxNode];
	int Tcou,root;
	int ans;

	int newNode()
	{
		++Tcou;
		memset(next[Tcou],0,sizeof(next[Tcou]));
		val[Tcou]=0;
		return Tcou;
	}

	void init()
	{
		ans=0;
		Tcou=-1;
		root=newNode();
	}

	void insert(char s1[],char s2[])
	{
		int p=0;

		for(int i=0;s1[i];++i)
		{
			if(next[p][s1[i]-'a']==0)
				next[p][s1[i]-'a']=newNode();

			p=next[p][s1[i]-'a'];
		}

		for(int i=0;s2[i];++i)
		{
			if(next[p][s2[i]-'a']==0)
				next[p][s2[i]-'a']=newNode();

			p=next[p][s2[i]-'a'];
		}

		if(!val[p])
			++ans;

		val[p]=1;
	}
}tree;

char s[200],t1[200],t2[200],t3[200],t4[200];
int N;
int len;

void copy(int x)
{
	for(int i=0;i<x;++i)
		t1[i]=t3[i]=s[i];
	t1[x]=t3[x]=0;

	for(int i=x;i<len;++i)
		t2[i-x]=t4[i-x]=s[i];
	t2[len-x]=t4[len-x]=0;

	reverse(t3,t3+x);
	reverse(t4,t4+len-x);
}

int getans()
{
	tree.init();
	len=strlen(s);

	for(int i=1;i<len;++i)
	{
		copy(i);

		tree.insert(t1,t2);
		tree.insert(t2,t1);
		tree.insert(t1,t4);
		tree.insert(t4,t1);
		tree.insert(t2,t3);
		tree.insert(t3,t2);
		tree.insert(t3,t4);
		tree.insert(t4,t3);
	}

	return tree.ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);

	while(N--)
	{
		scanf("%s",s);
		printf("%d\n",getans());
	}
	
	return 0;
}
