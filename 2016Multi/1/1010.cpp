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
// Created Time  : 2016年07月25日 星期一 19时33分47秒
// File Name     : 1010.cpp

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
const int MaxNode=1000005;

struct Trie {
	int next[MaxNode][26],val[MaxNode];
	int Tcou,root;
	int cou;

	int newNode() {
		++Tcou;

		memset(next[Tcou],0,sizeof(next[Tcou]));
		val[Tcou]=0;

		return Tcou;
	}

	void init() {
		cou=0;
		Tcou=-1;
		root=newNode();
	}

	int insert(char s[]) {
		int p=0;

		for(int i=0;s[i];++i) {
			if(next[p][s[i]-'a']==0) next[p][s[i]-'a']=newNode();
			p=next[p][s[i]-'a'];
		}

		if(!val[p]) val[p]=++cou;

		return val[p];
	}
}tree;

//////////////////////////////////////

struct Edge {
	int to,next;
};

Edge E[2][MaxN<<1];
int Ecou[2],head[2][MaxN];

int N;

void init() {
	Ecou[0]=Ecou[1]=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int t,int u,int v) {
	E[t][Ecou[t]].to=v;
	E[t][Ecou[t]].next=head[t][u];
	head[t][u]=Ecou[t]++;
}

char s1[15],s2[15];
int du[MaxN],ducou[MaxN];
int rcou2,rem2[MaxN];

char rems1[MaxN][13],rems2[MaxN][13];

int ans[MaxN];
long long hval[2][MaxN];
int trem;

const int P=13131,Q=1000000007;

void dfs(int t,int u,int pre) {
	vector <int> num;
	int cou=0;
	for(int i=head[t][u];i!=-1;i=E[t][i].next)
		if(E[t][i].to!=pre) {
			++cou;
			dfs(t,E[t][i].to,u);
			num.push_back(hval[t][E[t][i].to]);
		}

	if(!cou) {
		hval[t][u]=1;
		return;
	}

	sort(num.begin(),num.end());
	int len=num.size();

	hval[t][u]=0;
	for(int i=0;i<len;++i)
		hval[t][u]=(hval[t][u]*P+num[i])%Q;
}

void dfs2(int u,int pre) {
	
}

bool judge(int u) {
	dfs(1,u,-1);
	if(hval[1][u]!=hval[0][trem]) return 0;

	dfs2(trem,u,-1);
	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	while(~scanf("%d",&N)) {
		init();
		for(int i=1;i<=N;++i) du[i]=ducou[i]=0;

		tree.init();
		for(int i=1;i<N;++i) {
			scanf("%s %s",s1,s2);
			a=tree.insert(s1);
			b=tree.insert(s2);
			addEdge(0,a,b);
			addEdge(0,b,a);
			++du[a];
			++du[b];

			strcpy(rems1[a],s1);
			strcpy(rems1[b],s2);
		}
		for(int i=1;i<=N;++i) ++ducou[du[i]];
		int minn=100000000,tdu;
		for(int i=1;i<=N;++i)
			if(ducou[i] && minn>ducou[i]) {
				minn=ducou[i];
				tdu=i;
			}
		for(int i=1;i<=N;++i)
			if(du[i]==tdu) {
				trem=i;
				break;
			}

		for(int i=1;i<=N;++i) du[i]=0;
		tree.init();
		for(int i=1;i<N;++i) {
			scanf("%s %s",s1,s2);
			a=tree.insert(s1);
			b=tree.insert(s2);
			addEdge(1,a,b);
			addEdge(1,b,a);

			++du[a];
			++du[b];

			strcpy(rems2[a],s1);
			strcpy(rems2[b],s2);
		}
		rcou2=0;
		for(int i=1;i<=N;++i) if(du[i]==tdu) rem2[++rcou2]=i;

		dfs(0,trem,-1);
		for(int i=1;i<=rcou2;++i) if(judge(i)) break;

		for(int i=1;i<=N;++i) printf("%s %s\n",rems1[i],rems2[ans[i]]);
	}

	return 0;
}
