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
// Created Time  : 2015年12月04日 星期五 00时02分24秒
// File Name     : B.cpp

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

int N,M;
int blen,cou;
int rem[MaxN];
int num[MaxN],len[MaxN],tot[MaxN],flag[MaxN];

inline int pos(int x) {
	return x/blen;
}

void solve(int id,int L,int R) {
	for(int i=L;i<R;++i) num[i]=rem[i];
	sort(num+L,num+R);

	int k=L,tcou=1;
	for(int i=L+1;i<R;++i)
		if(num[i]!=num[i-1]) {
			num[k]=num[i-1];
			tot[k]=tcou;
			++k;
			tcou=1;
		}
		else ++tcou;

	num[k]=num[R-1];
	tot[k]=tcou;
	++k;
	len[id]=k-L;
}

void init() {
	blen=(int)sqrt(N);
	cou=(N+blen-1)/blen;
	for(int i=0;i<=cou;++i) flag[i]=-1;

	for(int i=0,j=blen,t=0;i<N;i+=blen,j=min(j+blen,N),++t) solve(t,i,j);
}

void update(int L,int R,int C) {
	int p1=pos(L),p2=pos(R);

	for(int i=p1+1;i<p2;++i) {
		num[i*blen]=C;
		tot[i*blen]=blen;
		len[i]=1;
		flag[i]=C;
	}

	int lim;

	if(p1==p2) {
		lim=p1*blen+blen;
		if(flag[p1]!=-1) for(int i=p1*blen;i<lim;++i) rem[i]=flag[p1];
		flag[p1]=-1;
		for(int i=L;i<=R;++i) rem[i]=C;
		solve(p1,p1*blen,lim);
	}
	else {
		lim=p1*blen+blen;
		if(flag[p1]!=-1) for(int i=p1*blen;i<lim;++i) rem[i]=flag[p1];
		flag[p1]=-1;
		for(int i=L;i<lim;++i) rem[i]=C;
		solve(p1,p1*blen,lim);

		lim=p2*blen+blen;
		if(flag[p2]!=-1) for(int i=lim-blen;i<lim;++i) rem[i]=flag[p2];
		flag[p2]=-1;
		for(int i=lim-blen;i<=R;++i) rem[i]=C;
		solve(p2,lim-blen,lim);
	}
}

int find(int id,int C) {
	int L=id*blen;
	int k=lower_bound(num+L,num+L+len[id],C)-num-L;
	if(k>=len[id] || k<0) return 0;
	if(num[L+k]==C) return tot[L+k];
	return 0;
}

int query(int L,int R,int C) {
	int p1=pos(L),p2=pos(R);
	int ret=0;

	for(int i=p1+1;i<p2;++i) ret+=find(i,C);
	
	int lim;

	if(p1==p2) {
		lim=p1*blen+blen;
		if(flag[p1]!=-1) for(int i=lim-blen;i<lim;++i) rem[i]=flag[p1];
		flag[p1]=-1;
		for(int i=p1;i<=p2;++i) if(rem[i]==C) ++ret;
	}
	else {
		lim=p1*blen+blen;
		if(flag[p1]!=-1) for(int i=lim-blen;i<lim;++i) rem[i]=flag[p1];
		flag[p1]=-1;
		for(int i=L;i<lim;++i) if(rem[i]==C) ++ret;

		lim=p2*blen+blen;
		if(flag[p2]!=-1) for(int i=lim-blen;i<lim;++i) rem[i]=flag[p2];
		flag[p2]=-1;
		for(int i=lim-blen;i<=R;++i) if(rem[i]==C) ++ret;
	}

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c,d;

	while(~scanf("%d %d",&N,&M)) {
		for(int i=0;i<N;++i) scanf("%d",rem+i);
		init();

		while(M--) {
			scanf("%d %d %d %d",&a,&b,&c,&d);
			if(a==1) update(b,c,d);
			else printf("%d\n",query(b,c,d));
		}
	}
	
	return 0;
}
