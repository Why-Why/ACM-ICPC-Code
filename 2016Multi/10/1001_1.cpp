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
// Created Time  : 2016年08月18日 星期四 12时05分37秒
// File Name     : 1001.cpp

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
const int MaxNode=2000000;

int Tcou;
int TreeRoot[MaxN];
int lson[MaxNode],rson[MaxNode],BIT[MaxNode];

int N;
long long num[MaxN];

int M,a,b,c,d,s;

long long hnum[MaxN],hcou;

int insert(int old,int val,int d) {
	int newRoot=Tcou++,ret=newRoot;
	int L=1,R=hcou,M;

	BIT[newRoot]=BIT[old]+d;
	while(R>L) {
		M=(L+R)>>1;

		if(val<=M) {
			lson[newRoot]=Tcou++; rson[newRoot]=rson[old];
			newRoot=lson[newRoot]; old=lson[old];
			R=M;
		}
		else {
			lson[newRoot]=lson[old]; rson[newRoot]=Tcou++;
			newRoot=rson[newRoot]; old=rson[old];
			L=M+1;
		}
		BIT[newRoot]=BIT[old]+d;
	}

	return ret;
}

int build_BIT(int L,int R) {
	int root=Tcou++;
	BIT[root]=0;

	if(L!=R) {
		int M=(L+R)>>1;
		lson[root]=build_BIT(L,M);
		rson[root]=build_BIT(M+1,R);
	}

	return root;
}

void init() {
	Tcou=0;
	TreeRoot[0]=build_BIT(1,hcou);

	for(int i=1;i<=N;++i)
		TreeRoot[i]=insert(TreeRoot[i-1],num[i],1);
}

/*
inline int count(int p[],int x) {
	if(!x) return 0;

	int L=1,R=hcou,M;
	int ret=0;

	int root[4];
	for(int i=0;i<4;++i) root[i]=TreeRoot[p[i]];

	while(R>L) {
		M=(L+R)>>1;

		if(M<=x) {
			ret+=BIT[lson[root[0]]];
			ret+=BIT[lson[root[1]]];
			ret-=BIT[lson[root[2]]];
			ret-=BIT[lson[root[3]]];

			root[0]=rson[root[0]];
			root[1]=rson[root[1]];
			root[2]=rson[root[2]];
			root[3]=rson[root[3]];
			L=M+1;
		}
		else {
			root[0]=lson[root[0]];
			root[1]=lson[root[1]];
			root[2]=lson[root[2]];
			root[3]=lson[root[3]];
			R=M;
		}

		if(L>x || R<x) break;
	}

	return ret;
}

inline int judge(int x) {
	return 1;
	--x;
	int p[4]={b,d,a-1,c-1};
	return count(p,x);
	
	//int ret=count(b,x)+count(d,x)-count(a-1,x)-count(c-1,x);
	//return ret;
}

int getnum(int k) {
	int L=1,R=hcou,M;

	while(R>L) {
		M=(L+R+1)>>1;
		if(judge(M)<=k-1) L=M;
		else R=M-1;
	}

	return hnum[L];
}

inline int count(int root[],int M) {
}
*/

int getnum(int k) {
	int root[4]={TreeRoot[b],TreeRoot[d],TreeRoot[a-1],TreeRoot[c-1]};

	int L=1,R=hcou,M;
	int t;

	while(R>L) {
		M=(L+R)>>1;
		t=BIT[lson[root[0]]]+BIT[lson[root[1]]]-BIT[lson[root[2]]]-BIT[lson[root[3]]];

		if(t>k) {
			R=M;
			root[0]=lson[root[0]];
			root[1]=lson[root[1]];
			root[2]=lson[root[2]];
			root[3]=lson[root[3]];
		}
		else if(t<k) {
			L=M+1;
			k-=t;
			root[0]=rson[root[0]];
			root[1]=rson[root[1]];
			root[2]=rson[root[2]];
			root[3]=rson[root[3]];
		}
		else return M;
	}
	return L;
}

inline long long read() {
	char c; int sgn;
	if(c=getchar(),c==EOF) return 0; //EOF
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	sgn=(c=='-')?-1:1;
	long long ret=(c=='-')?0:(c-'0');
	while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
	ret*=sgn;
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	double ans;
	T=read();

	while(T--) {
		N=read();
		M=read();
		hcou=N;
		for(int i=1;i<=N;++i) {
			num[i]=read();
			hnum[i]=num[i];
		}

		sort(hnum+1,hnum+N+1);
		hcou=unique(hnum+1,hnum+N+1)-hnum-1;
		for(int i=1;i<=N;++i) num[i]=lower_bound(hnum+1,hnum+hcou+1,num[i])-hnum;

		init();

		while(M--) {
			a=read();
			b=read();
			c=read();
			d=read();
			s=b-a+1+d-c+1;

			if(s&1) ans=hnum[getnum((s+1)>>1)];
			else ans=(hnum[getnum(s>>1)]+0.0+hnum[getnum((s>>1)+1)])/2.0;
			printf("%.1f\n",ans);
		}
	}

	return 0;
}
