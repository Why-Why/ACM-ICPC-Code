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
// Created Time  : 2016年09月24日 星期六 12时13分29秒
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

using namespace std;

const int MaxN=555;

const int MaxNode=30000;

int rank1[MaxNode],rk;

struct Trie {
	int next[MaxNode][26],val[MaxNode];
	int Tcou,root;

	int rcou;

	int newNode()
	{
		++Tcou;

		memset(next[Tcou],0,sizeof(next[Tcou]));
		val[Tcou]=0;

		return Tcou;
	}

	void init()
	{
		rk=0;

		rcou=0;

		Tcou=-1;
		root=newNode();
	}

	Trie()
	{
		init();
	}

	int insert(char s[],int len)
	{
		int p=0;

		for(int i=0;i<len;++i)
		{
			if(next[p][s[i]-'a']==0)
				next[p][s[i]-'a']=newNode();

			p=next[p][s[i]-'a'];
		}

		if(val[p]) return val[p];
		val[p]=++rcou;
		return rcou;
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

	void dfs(int u) {
		if(val[u]) rank1[val[u]]=++rk;

		for(int i=0;i<26;++i)
			if(next[u][i])
				dfs(next[u][i]);
	}

}tree;

char s[MaxN];
long long rem[30000],rcou;

char rems[300000];
int scou,sp[30000];

inline void getans() {
	sort(rem,rem+rcou);

	int maxn=0,cou=1;
	rem[rcou]=-1;

	for(int i=1;i<=rcou;++i)
		if(rem[i]==rem[i-1]) ++cou;
		else {
			maxn=max(maxn,cou);
			cou=1;
		}

	tree.dfs(tree.root);

	long long maxnn=-1,rrr,ttt;

	cou=1;
	for(int i=1;i<=rcou;++i)
		if(rem[i]==rem[i-1]) ++cou;
		else {
			if(cou==maxn) {
				ttt=rank1[rem[i-1]/1000000]*1000000+rank1[rem[i-1]%1000000];
				if(maxnn==-1 || ttt<maxnn) {
					maxnn=ttt;
					rrr=rem[i-1];
				}
			}
			cou=1;
		}

	printf("%s %s:%d\n",rems+sp[rrr/1000000],rems+sp[rrr%1000000],maxn);
}

inline bool judge(char c) {
	if(c>='a' && c<='z') return 1;
	return 0;
}

inline void add() {
	int lastt;
	bool you=1;
	int L,t;
	char tc;

	for(int i=0;s[i];) {
		if(judge(s[i])) {
			L=i;
			while(judge(s[i])) ++i;
			t=tree.insert(s+L,i-L);

			sp[t]=scou;

			tc=s[i];
			s[i]=0;
			strcpy(rems+scou,s+L);
			rems[scou+i-L]=0;
			scou+=i-L+1;
			s[i]=tc;

			if(you==0) {
				rem[rcou++]=lastt*1000000LL+t;
			}

			lastt=t;

			if(s[i]==' ') you=0;
			else you=1;
		}
		else {
			if(s[i]!=' ') you=1;
			++i;
		}
	}
}

inline void init() {
	rcou=0;
	scou=0;
	tree.init();
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	while(fgets(s,MaxN,stdin)) {
		if(s[0]=='#') {
			getans();
			init();
		}
		else add();
	}

	return 0;
}
