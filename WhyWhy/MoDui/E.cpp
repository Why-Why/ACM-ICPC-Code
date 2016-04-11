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
// Created Time  : 2016年04月05日 星期二 23时09分42秒
// File Name     : E.cpp

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

const int MaxN=30004;
const int mod=1000000007;

int N,M,blen;
int num[MaxN];
int cou[MaxN];
int ans[MaxN];
long long tans;

long long jie[MaxN],njie[MaxN];

long long inv(long long a,long long m) {
	if(a==1) return 1;
	return inv(m%a,m)*(m-m/a)%m;
}

void init() {
	jie[0]=1;
	for(int i=1;i<MaxN;++i) jie[i]=(jie[i-1]*i)%mod;
	for(int i=0;i<MaxN;++i) njie[i]=inv(jie[i],mod);
}

struct State {
	int L,R;
	int id;

	bool operator < (const State &b) const {
		int x=(L-1)/blen,y=(b.L-1)/blen;
		return x==y ? R<b.R : x<y;
	}
}que[MaxN];

inline void update(int x,int t) {
	(tans*=jie[cou[x]])%=mod;
	cou[x]+=t;
	(tans*=njie[cou[x]])%=mod;
}

void getans() {
	int dL=1,dR=1;
	++cou[num[1]];
	tans=1;

	for(int i=1;i<=M;++i) {
		if(dR>que[i].R) for(int j=dR;j>que[i].R;--j) update(num[j],-1);
		else for(int j=dR+1;j<=que[i].R;++j) update(num[j],1);
		dR=que[i].R;

		if(dL>que[i].L) for(int j=dL-1;j>=que[i].L;--j) update(num[j],1);
		else for(int j=dL;j<que[i].L;++j) update(num[j],-1);
		dL=que[i].L;

		ans[que[i].id]=(tans*jie[que[i].R-que[i].L+1])%mod;
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&N,&M);
		blen=sqrt((double)N);
		for(int i=1;i<=N;++i) scanf("%d",num+i);

		memset(cou,0,sizeof(cou));
		tans=0;

		for(int i=1;i<=M;++i) scanf("%d %d",&que[i].L,&que[i].R),que[i].id=i;
		sort(que+1,que+M+1);
		getans();

		for(int i=1;i<=M;++i) printf("%d\n",ans[i]);
	}
	
	return 0;
}
