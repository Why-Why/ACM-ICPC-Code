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
// Created Time  : 2015年11月27日 星期五 20时56分42秒
// File Name     : A.cpp

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

const int INF=0x3f3f3f3f;
const int MaxN=100005;
const int MaxM=50005+100005;

struct OPE {
	int type,id;
	int a,b,c;
}ope[MaxM];

OPE to1[MaxM],to2[MaxM];

int N,M;
int C[MaxN];
int ans[MaxM];
int rem[MaxM];

inline int lowbit(int x) {
	return x&(-x);
}

int add(int x,int c) {
	for(;x<=N;x+=lowbit(x)) C[x]+=c;
}

int query(int x) {
	int ret=0;
	for(;x;x-=lowbit(x)) ret+=C[x];
	return ret;
}

void solve(int ql,int qr,int L,int R) {
	if(ql>qr) return;
	if(L==R) {
		for(int i=ql;i<=qr;++i) if(ope[i].type) ans[ope[i].id]=L;
		return;
	}

	int M=(L+R+1)>>1;
	for(int i=ql;i<=qr;++i)
		if(ope[i].type==1) rem[i]=query(ope[i].b)-query(ope[i].a-1);
		else if(ope[i].type==0) { if(ope[i].b<M) add(ope[i].a,1); }

	int cou1=0,cou2=0;
	for(int i=ql;i<=qr;++i)
		if(ope[i].type==0)
			if(ope[i].b<M) add(ope[i].a,-1),to1[cou1++]=ope[i];
			else to2[cou2++]=ope[i];
		else if(ope[i].type==1)
			if(ope[i].c<=rem[i]) to1[cou1++]=ope[i];
			else ope[i].c-=rem[i],to2[cou2++]=ope[i];

	int i=ql;
	for(int j=0;j<cou1;++j) ope[i++]=to1[j];
	for(int j=0;j<cou2;++j) ope[i++]=to2[j];

	solve(ql,ql+cou1-1,L,M-1);
	solve(ql+cou1,qr,M,R);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&N,&M)) {
		memset(C,0,sizeof(C));
		int len=0;
		for(int i=1;i<=N;++i) {
			scanf("%d",&ope[++len].b);
			ope[len].a=i;
			ope[len].type=0;
		}
		for(int i=1;i<=M;++i) {
			ope[++len].id=i;
			ope[len].type=1;
			scanf("%d %d %d",&ope[len].a,&ope[len].b,&ope[len].c);
		}

		solve(1,len,-INF,INF);
		for(int i=1;i<=M;++i) printf("%d\n",ans[i]);
	}
	
	return 0;
}
