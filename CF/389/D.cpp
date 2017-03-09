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
// Created Time  : 2017年01月09日 星期一 17时08分31秒
// File Name     : D.cpp

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

const int MaxNode=300000;

int sta[MaxNode];
int num[100005];
int ans;

inline bool cmp(int a,int b) {
	if(num[a]!=num[b]) return num[a]>num[b];
	return a<b;
}

struct Trie
{
	int next[MaxNode][26];
	int Tcou,root;

	vector <int> as[MaxNode],bs[MaxNode];

	int newNode()
	{
		++Tcou;

		memset(next[Tcou],0,sizeof(next[Tcou]));
		as[Tcou].clear();
		bs[Tcou].clear();

		return Tcou;
	}

	void init()
	{
		Tcou=-1;
		root=newNode();
	}

	Trie()
	{
		init();
	}

	void insert(int len,char s[],int a) {
		int p=0;

		for(int i=0;i<len;++i) {
			if(next[p][s[i]-'a']==0)
				next[p][s[i]-'a']=newNode();

			p=next[p][s[i]-'a'];
		}

		as[p].push_back(a);
	}

	void insertV(int len,char s[],int b) {
		int p=0;

		for(int i=len-1;i>=0;--i) {
			if(next[p][s[i]-'a']==0)
				next[p][s[i]-'a']=newNode();

			p=next[p][s[i]-'a'];
		}

		bs[p].push_back(b);
	}

	void dfs(int u) {
		if(as[u].size() && bs[u].size()) {
			int len1=as[u].size(),len2=bs[u].size();
			sort(as[u].begin(),as[u].end(),cmp);
			sort(bs[u].begin(),bs[u].end(),cmp);

			if(as[u][0]==bs[u][0]) {
				for(int i=0;i<len1;++i) sta[as[u][i]]=1;
				for(int i=0;i+1<len1;i+=2)
					if(num[as[u][i]]+num[as[u][i+1]]>0) {
						ans+=num[as[u][i]]+num[as[u][i+1]];
						sta[as[u][i]]=sta[as[u][i+1]]=2;
					}
					else break;
			}
			else {
				if(sta[as[u][0]]);
				else {
					sta[as[u][0]]=sta[bs[u][0]]=-1;
                
					for(int i=0;i<len1 && i<len2;++i)
						if(num[as[u][i]]+num[bs[u][i]]>0)
							ans+=num[as[u][i]]+num[bs[u][i]];
						else break;
				}
			}
		}

		for(int i=0;i<26;++i)
			if(next[u][i])
				dfs(next[u][i]);
	}

	/*
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
	*/
}tree;

char s[100005];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	tree.init();
	int K,N;

	scanf("%d %d",&K,&N);
	for(int i=1;i<=K;++i) {
		scanf("%s %d",s,num+i);
		tree.insert(N,s,i);
		tree.insertV(N,s,i);
	}

	tree.dfs(tree.root);

	int maxn=0;

	for(int i=1;i<=K;++i)
		if(sta[i]==1) maxn=max(maxn,num[i]);
		else if(sta[i]==2) maxn=max(maxn,-num[i]);
	ans+=maxn;

	printf("%d\n",ans);

	return 0;
}
