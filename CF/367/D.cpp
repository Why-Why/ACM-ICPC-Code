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
// Created Time  : 2016年09月07日 星期三 23时54分35秒
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

const int MaxN=200005;
const int MaxNode=MaxN*32+5;

struct Trie {
	int next[MaxNode][2],val[MaxNode];
	int Tcou,root;

	int newNode() {
		++Tcou;

		memset(next[Tcou],0,sizeof(next[Tcou]));
		val[Tcou]=0;

		return Tcou;
	}

	void init() {
		Tcou=-1;
		root=newNode();
	}

	void insert(int len,int x,int d) {
		int p=0;
		int t;

		for(int i=len-1;i>=0;--i) {
			t=(x&(1<<i)) ? 1 : 0;
			if(next[p][t]==0) next[p][t]=newNode();
			p=next[p][t];

			val[p]+=d;
		}
	}

	int match(int len,int x) {
		int p=0;
		int t,ans=0;

		for(int i=len-1;i>=0;--i) {
			t=(x&(1<<i)) ? 0 : 1;
			if(next[p][t]==0 || val[next[p][t]]==0) t^=1;
			p=next[p][t];

			if(t) ans|=(1<<i);
		}

		return ans^x;
	}
}tree;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,t;
	char s[10];

	tree.init();
	tree.insert(31,0,1);

	scanf("%d",&N);
	while(N--) {
		scanf("%s %d",s,&t);
		if(s[0]=='+') tree.insert(31,t,1);
		else if(s[0]=='-') tree.insert(31,t,-1);
		else printf("%d\n",tree.match(31,t));
	}

	return 0;
}
