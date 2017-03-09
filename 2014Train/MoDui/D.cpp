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
// Created Time  : 2016年03月31日 星期四 20时21分42秒
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
#include <climits>

using namespace std;

const int MaxN=50004;
const int INF=0x3f3f3f3f;

int hashrem[MaxN],hcou;
inline int HASH(int x) { return lower_bound(hashrem+1,hashrem+hcou+1,x)-hashrem; }

struct ST {
	int sum;
	int C[MaxN];

	void init() {
		sum=0;
		memset(C,0,sizeof(C));
	}

	int lowbit(int x) { return x&(-x); }

	void insert(int p) {
		p=HASH(p);
		for(;p<=hcou;p+=lowbit(p)) ++C[p];
		++sum;
	}

	void erase(int p) {
		p=HASH(p);
		for(;p<=hcou;p+=lowbit(p)) --C[p];
		--sum;
	}

	int findmin(int p) {
		int ret=0;
		p=HASH(p)-1;
		for(;p;p-=lowbit(p)) ret+=C[p];
		return ret;
	}

	int findmax(int p) {
		int ret=0;
		p=HASH(p);
		for(;p;p-=lowbit(p)) ret+=C[p];
		return sum-ret;
	}
	
}tree;


int N,Q;
int blen,bcou;
int num[MaxN];
long long ans[MaxN];
long long tans;

inline int belong(int x) { return (x-1)/blen+1; }

struct QUE {
	int l,r,id;

	bool operator < (const QUE & b) const {
		if(belong(l)==belong(b.l)) return r<b.r;
		return belong(l)<belong(b.l);
	}
}que[MaxN];

void update(int p,int f,long long d) {
	if(f==0) tans+=d*tree.findmin(num[p]);
	else tans+=d*tree.findmax(num[p]);

	if(d==1) tree.insert(num[p]);
	else tree.erase(num[p]);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	blen=sqrt((double)N);
	bcou=(N+blen-1)/blen;
	for(int i=1;i<=N;++i) scanf("%d",num+i),hashrem[++hcou]=num[i];
	scanf("%d",&Q);
	for(int i=1;i<=Q;++i) scanf("%d %d",&que[i].l,&que[i].r),que[i].id=i;
	sort(que+1,que+Q+1);

	sort(hashrem+1,hashrem+hcou+1);
	hcou=unique(hashrem+1,hashrem+hcou+1)-hashrem-1;

	int dl=1,dr=1;
	tans=0;

	tree.init();
	tree.insert(num[1]);
	for(int i=1;i<=Q;++i) {
		if(dr>que[i].r) for(int j=dr;j>que[i].r;--j) update(j,1,-1);
		else for(int j=dr+1;j<=que[i].r;++j) update(j,1,1);
		dr=que[i].r;

		if(dl>que[i].l) for(int j=dl-1;j>=que[i].l;--j) update(j,0,1);
		else for(int j=dl;j<que[i].l;++j) update(j,0,-1);
		dl=que[i].l;

		ans[que[i].id]=tans;
	}

	for(int i=1;i<=Q;++i) printf("%lld\n",ans[i]);
	
	return 0;
}
