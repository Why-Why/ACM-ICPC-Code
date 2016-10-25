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
// Created Time  : 2016年07月27日 星期三 20时58分34秒
// File Name     : 1010_1.cpp

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

Edge E1[MaxN<<1],E2[MaxN<<1];
int head1[MaxN],head2[MaxN],E1cou,E2cou;
int N;

int *head;
Edge *E;

void init() {
	E1cou=E2cou=0;
	memset(head1,-1,sizeof(head1));
	memset(head2,-1,sizeof(head2));
}

void addEdge1(int u,int v) {
	E1[E1cou].to=v;
	E1[E1cou].next=head1[u];
	head1[u]=E1cou++;
}

void addEdge2(int u,int v) {
	E2[E2cou].to=v;
	E2[E2cou].next=head2[u];
	head2[u]=E2cou++;
}

////////////////////////////////////////

typedef pair<long long,int> pii;

int rem1,rem2[MaxN],rcou;

int dp1[MaxN],dp2[MaxN],dpr[MaxN];
int dps[MaxN];
int minn;

void dfs1(int u,int pre) {
	dp1[u]=dp2[u]=-1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			dfs1(E[i].to,u);
			if(dp1[u]<dp1[E[i].to]) {
				dp2[u]=dp1[u];
				dp1[u]=dp1[E[i].to];
				dpr[u]=E[i].to;
			}
			else if(dp2[u]<dp1[E[i].to]) dp2[u]=dp1[E[i].to];
		}

	++dp1[u];
	if(dp2[u]!=-1) ++dp2[u];
}

void dfs2(int u,int pre) {
	if(pre!=-1) {
		dps[u]=dps[pre]+1;
		if(dpr[pre]!=u) dps[u]=max(dps[u],dp1[pre]+1);
		else dps[u]=max(dps[u],dp2[pre]+1);
	}

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
			dfs2(E[i].to,u);

	dps[u]=max(dps[u],dp1[u]);
	minn=min(minn,dps[u]);
}

void findRem() {
	rcou=0;

	E=E1;
	head=head1;
	dfs1(1,-1);
	minn=0x3f3f3f3f;
	dps[1]=0;
	dfs2(1,-1);

	for(int i=1;i<=N;++i)
		if(dps[i]==minn) {
			rem1=i;
			break;
		}

	E=E2;
	head=head2;
	dfs1(1,-1);
	minn=0x3f3f3f3f;
	dps[1]=0;
	dfs2(1,-1);

	for(int i=1;i<=N;++i)
		if(dps[i]==minn)
			rem2[rcou++]=i;
}

////////////////////////////////////////

const long long Q=1000000007;
const long long P=100000007;

char rems1[MaxN][13],rems2[MaxN][13];
char s1[15],s2[15];
int ans[MaxN];

long long hval1[MaxN],hval2[MaxN],*hval;

void dfsG(int u,int pre) {
	vector <long long> num;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			dfsG(E[i].to,u);
			num.push_back(hval[E[i].to]);
		}

	if(num.size()==0) hval[u]=P;
	else {
		sort(num.begin(),num.end());
		int len=num.size();
		hval[u]=1;
    
		for(int i=0;i<len;++i)
			hval[u]=(hval[u]*P+num[i]);
	}
}

bool dfsG1(int u1,int pre1,int u2,int pre2) {
	vector <pii> num1,num2;

	for(int i=head1[u1];i!=-1;i=E1[i].next)
		if(E1[i].to!=pre1)
			num1.push_back(pii(hval1[E1[i].to],E1[i].to));

	for(int i=head2[u2];i!=-1;i=E2[i].next)
		if(E2[i].to!=pre2)
			num2.push_back(pii(hval2[E2[i].to],E2[i].to));

	int len1=num1.size(),len2=num2.size();
	if(len1!=len2) return 0;

	sort(num1.begin(),num1.end());
	sort(num2.begin(),num2.end());

	bool ok;

	for(int i=0;i<len1;++i) {
		if(num1[i].first!=num2[i].first) return 0;

		ok=0;
		for(int j=i;j<len1 && num2[j].first==num2[i].first;++j)
			if(dfsG1(num1[i].second,u1,num2[j].second,u2)) {			// !!!
				ans[num1[i].second]=num2[j].second;
				swap(num2[i],num2[j]);
				ok=1;
				break;
			}

		if(!ok) return 0;
	}

	return 1;
}

void getans() {
	head=head1;
	E=E1;
	hval=hval1;
	dfsG(rem1,-1);

	for(int i=0;i<rcou;++i) {
		head=head2;
		E=E2;
		hval=hval2;
		dfsG(rem2[i],-1);

		if(hval1[rem1]==hval2[rem2[i]]) {
			if(dfsG1(rem1,-1,rem2[i],-1)) {
				ans[rem1]=rem2[i];
				return;
			}
		}
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	while(~scanf("%d",&N)) {
		init();

		tree.init();
		for(int i=1;i<N;++i) {
			scanf("%s %s",s1,s2);
			a=tree.insert(s1);
			b=tree.insert(s2);

			strcpy(rems1[a],s1);
			strcpy(rems1[b],s2);

			addEdge1(a,b);
			addEdge1(b,a);
		}

		tree.init();
		for(int i=1;i<N;++i) {
			scanf("%s %s",s1,s2);
			a=tree.insert(s1);
			b=tree.insert(s2);

			strcpy(rems2[a],s1);
			strcpy(rems2[b],s2);

			addEdge2(a,b);
			addEdge2(b,a);
		}

		findRem();
		getans();

		for(int i=1;i<=N;++i)
			printf("%s %s\n",rems1[i],rems2[ans[i]]);
	}

	return 0;
}
