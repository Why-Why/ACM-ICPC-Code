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
// Created Time  : 2016年04月07日 星期四 23时07分51秒
// File Name     : H.cpp

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

const int MaxN=30005;

int N,K,blen;
int A[MaxN];
int Q;

int rem1[MaxN],rem2[MaxN];
int ans[MaxN],tans;

struct QUE {
	int L,R,id,t;

	QUE() {}
	QUE(int a,int b,int c,int d):L(a),R(b),id(c),t(d) {}

	bool operator < (const QUE &b) const {
		int x=(L-1)/blen,y=(b.L-1)/blen;
		return x==y ? R<b.R : x<y;
	}
}que[MaxN<<2];

inline void updateL(int x,int t) {
	rem1[x]+=t;
	if(K-x>0 && K-x<=N) tans+=t*rem2[K-x];
}

inline void updateR(int x,int t) {
	rem2[x]+=t;
	if(K-x>0 && K-x<=N) tans+=t*rem1[K-x];
}

void getans() {
	int dL=1,dR=1;
	rem1[A[1]]=rem2[A[1]]=1;
	tans=0;

	for(int i=1;i<=Q;++i) {
		if(dR<que[i].R) for(int j=dR+1;j<=que[i].R;++j) updateR(A[j],1);
		else for(int j=dR;j>que[i].R;--j) updateR(A[j],-1);
		dR=que[i].R;

		if(dL<que[i].L) for(int j=dL+1;j<=que[i].L;++j) updateL(A[j],1);
		else for(int j=dL;j>que[i].L;--j) updateL(A[j],-1);
		dL=que[i].L;

		ans[que[i].id]+=que[i].t*tans;
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int tQ,a,b,c,d;

	while(~scanf("%d",&N)) {
		scanf("%d",&K);
		blen=sqrt(double(N));
		for(int i=1;i<=N;++i) scanf("%d",A+i),rem1[i]=rem2[i]=0;
		Q=0;
		scanf("%d",&tQ);
		for(int i=1;i<=tQ;++i) {
			scanf("%d %d %d %d",&a,&b,&c,&d);
			if(a>1 && c>1) que[++Q]=QUE(a-1,c-1,i,1);
			que[++Q]=QUE(b,d,i,1);
			if(a>1) que[++Q]=QUE(a-1,d,i,-1);
			if(c>1) que[++Q]=QUE(b,c-1,i,-1);
			ans[i]=0;
		}
		sort(que+1,que+Q+1);
		getans();
		for(int i=1;i<=tQ;++i) printf("%d\n",ans[i]);
	}
	
	return 0;
}
