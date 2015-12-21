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
// Created Time  : 2015年11月28日 星期六 10时54分07秒
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

const int MaxN=100005;

int N,Q,M;

struct DATA {
	long long A;
	int B;
	int p;

	bool operator < (const DATA & b) const {
		return B<b.B;
	}
}num[MaxN];

struct Query {
	int l,r;
	int id;

	bool operator < (const Query & b) const {
		return l>b.l;
	}
}que[MaxN];

long long ans[MaxN]={0};

struct GETANS {
	struct State {
		long long v;
		int a,b;

		bool operator < (const State & y) const {
			return a>y.a;
		}
	}data[MaxN];
	int k,n;

	long long C[MaxN];

	inline int lowbit(int x) {
		return x&(-x);
	}

	void add(int x,long long v) {
		for(;x<=N;x+=lowbit(x)) C[x]=max(C[x],v);
	}

	long long query(int x) {
		long long ret=0;
		for(;x;x-=lowbit(x)) ret=max(ret,C[x]);
		return ret;
	}

	void init(int _k) {
		n=0;
		k=_k;
		memset(C,0,sizeof(C));
	}

	void process() {
		for(int i=1;i+k<=N;++i) {
			data[++n].v=num[i].A+num[i+k].A;
			data[n].a=min(num[i].p,num[i+k].p);
			data[n].b=max(num[i].p,num[i+k].p);
		}
		sort(data+1,data+n+1);
	}

	void getans() {
		for(int i=1,j=1;i<=Q;++i) {
			for(;j<=n && data[j].a>=que[i].l;++j)
				add(data[j].b,data[j].v);
			ans[que[i].id]=max(ans[que[i].id],query(que[i].r));
		}
	}
}func[12];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t;

	scanf("%d %d %d",&N,&Q,&M);
	for(int i=1;i<=N;++i) scanf("%lld",&num[i].A);
	for(int i=1;i<=N;++i) scanf("%d",&num[i].B),num[i].p=i;
	for(int i=1;i<=M;++i) {
		scanf("%d",&t);
		func[i].init(t);
	}
	for(int i=1;i<=Q;++i) {
		scanf("%d %d",&que[i].l,&que[i].r);
		que[i].id=i;
	}

	sort(num+1,num+N+1);
	sort(que+1,que+Q+1);

	for(int i=1;i<=M;++i) {
		func[i].process();
		func[i].getans();
	}

	for(int i=1;i<=Q;++i)
		printf("%lld\n",ans[i]);
	
	return 0;
}
