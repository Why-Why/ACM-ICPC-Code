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
// Created Time  : 2015年12月29日 星期二 23时25分58秒
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
typedef long long LL;

struct Point {
	LL x,y;

	bool operator < (const Point &b) const {
		return x<b.x;
	}
}P[MaxN];

struct State {
	LL D,P,R,G;

	bool operator < (const State &b) const {
		return D<b.D;
	}
}sta[MaxN];

int pcou;
int stack[MaxN],top;
double krem[MaxN];
int kcou;

int N,C,DD;
LL dp[MaxN];

inline bool judge(int a,int b,int c) {
	(P[c].y-P[b].y)*(P[b].x-P[a].x)>=(P[b].y-P[a].y)*(P[c].x-P[b].x);
}

inline int find(double k) {
	return lower_bound(krem,krem+kcou,k)-krem;
}

void solve(int LLL,int MM,int RR) {
	LL tans=0;
	pcou=0;
	
	for(int i=LLL;i<=MM;++i) {
		tans=max(tans,dp[i]);
		if(dp[i]>=sta[i].P) {
			P[pcou].x=sta[i].G;
			P[pcou++].y=dp[i]-sta[i].P+sta[i].R-sta[i].D*sta[i].G-sta[i].G;
		}
	}
	sort(P,P+pcou);

	top=1;
	stack[0]=0;
	for(int i=1;i<pcou;++i) {
		while(top>1 && judge(stack[top-2],stack[top-1],i)) --top;
		stack[top++]=i;
	}

	kcou=0;
	for(int i=1;i<top;++i) krem[kcou++]=-(P[stack[i]].y-P[stack[i-1]].y+0.0)/(0.0+P[stack[i]].x-P[stack[i-1]].x);

	cout<<"####\n"<<LLL<<' '<<MM<<' '<<RR<<endl;

	for(int i=0;i<top;++i) cout<<"@ "<<P[stack[i]].x<<' '<<P[stack[i]].y<<' ';
	cout<<endl;

	int t;
	for(int i=MM+1;i<=RR;++i) {
		t=find(sta[i].D);
		cout<<i<<' '<<t<<endl;
		dp[i]=max(dp[i],max(tans,P[stack[t]].y+sta[i].D*P[stack[t]].x));
	}
}

void CDQ(int cL,int cR) {
	if(cL==cR) return;
	int cM=(cL+cR)>>1;

	CDQ(cL,cM);
	solve(cL,cM,cR);
	CDQ(cM+1,cR);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cas=1;

	while(~scanf("%d %d %d",&N,&C,&DD) && N+C+DD) {
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=N;++i) scanf("%I64d %I64d %I64d %I64d",&sta[i].D,&sta[i].P,&sta[i].R,&sta[i].G);
		sta[++N].D=DD+1;
		sta[N].P=sta[N].R=sta[N].G=0;
		sort(sta+1,sta+N+1);
		dp[1]=C;
		CDQ(1,N);
		printf("Case %d: %I64d\n",cas++,dp[N]);
	}
	
	return 0;
}
