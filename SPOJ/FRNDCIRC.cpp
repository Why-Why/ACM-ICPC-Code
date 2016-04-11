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
// Created Time  : 2016年04月01日 星期五 16时15分44秒
// File Name     : FRNDCIRC.cpp

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
const int HASH=100003;

typedef unsigned long long ULL;

struct HASHMAP {
	int head[HASH],next[MaxN],Hcou;
	ULL key[MaxN];
	int rem[MaxN];

	void init() {
		Hcou=0;
		memset(head,-1,sizeof(head));
	}

	int insert(ULL v) {
		int h=v%HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(v==key[i])
				return rem[i];
		++Hcou;
		rem[Hcou]=Hcou;
		key[Hcou]=v;
		next[Hcou]=head[h];
		head[h]=Hcou;

		return Hcou;
	}

	ULL hash(char s[]) {
		ULL ret=0,seed=13131313;
		for(int i=0;s[i];++i) ret=ret*seed+s[i];
		return ret;
	}
}tree;

int N;
char s1[30],s2[30];

int fa[MaxN];
int cou[MaxN];

int find(int x) {
	if(fa[x]==-1) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

int merge(int a,int b) {
	int x=find(a),y=find(b);
	if(x==y) return cou[x];

	fa[x]=y;
	cou[y]+=cou[x];
	return cou[y];
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,a,b;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		tree.init();
		for(int i=0;i<=(N<<1);++i) fa[i]=-1,cou[i]=1;

		for(int i=1;i<=N;++i) {
			scanf("%s %s",s1,s2);
			a=tree.insert(tree.hash(s1));
			b=tree.insert(tree.hash(s2));
			printf("%d\n",merge(a,b));
		}
	}
	
	return 0;
}
