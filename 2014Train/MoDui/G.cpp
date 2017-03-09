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
// Created Time  : 2016年04月07日 星期四 20时44分54秒
// File Name     : G.cpp

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

int N,Q;
int num[MaxN],hrem[MaxN],hcou,blen;

long long ans[MaxN],tans;
long long rem[MaxN];

struct QUE {
	int L,R,id;

	bool operator < (const QUE &b) const {
		int x=(L-1)/blen,y=(b.L-1)/blen;
		return x==y ? R<b.R : x<y;
	}
}que[MaxN];

inline long long cube(long long x) {
	return x*x*x;
}

inline void update(int x,int t) {
	tans-=cube(rem[x]);
	rem[x]+=t;
	tans+=cube(rem[x]);
}

void getans() {
	int dL=1,dR=1;
	tans=1;
	rem[num[1]]=1;

	for(int i=1;i<=Q;++i) {
		if(dR<que[i].R) for(int j=dR+1;j<=que[i].R;++j) update(num[j],1);
		else for(int j=dR;j>que[i].R;--j) update(num[j],-1);
		dR=que[i].R;

		if(dL<que[i].L) for(int j=dL;j<que[i].L;++j) update(num[j],-1);
		else for(int j=dL-1;j>=que[i].L;--j) update(num[j],1);
		dL=que[i].L;

		ans[que[i].id]=tans;
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N)) {
		hcou=0;
		for(int i=1;i<=N;++i) scanf("%d",num+i),hrem[++hcou]=num[i];
		sort(hrem+1,hrem+hcou+1);
		hcou=unique(hrem+1,hrem+hcou+1)-hrem-1;
		for(int i=1;i<=N;++i) num[i]=lower_bound(hrem+1,hrem+hcou+1,num[i])-hrem;

		scanf("%d",&Q);
		for(int i=1;i<=Q;++i) scanf("%d %d",&que[i].L,&que[i].R),que[i].id=i;
		blen=sqrt(double(N));
		sort(que+1,que+Q+1);

		tans=0;
		memset(rem,0,sizeof(rem));
		getans();
		for(int i=1;i<=Q;++i) printf("%I64d\n",ans[i]);
	}
	
	return 0;
}
