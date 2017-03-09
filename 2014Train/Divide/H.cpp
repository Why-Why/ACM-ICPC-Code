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
// Created Time  : 2015年12月24日 星期四 22时13分54秒
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

const int MaxN=100005;

int N;
double S;
double A[MaxN],B[MaxN],R[MaxN];
double dp[MaxN];
double ans;

struct Point {
	double x,y;

	bool operator < (const Point &b) const {
		return x<b.x;
	}
};

Point P[MaxN];
int stack[MaxN],top;

int kcou;
double krem[MaxN];

inline bool judge(int a,int b,int c) {
	return (P[c].y-P[b].y)*(P[b].x-P[a].x)>=(P[b].y-P[a].y)*(P[c].x-P[b].x);
}

inline int find(double k) {
	return lower_bound(krem,krem+kcou,-k)-krem;
}

void solve(int L,int M,int RR) {
	int cou=0;
	double tans=0;
	for(int i=L;i<=M;++i) {
		P[cou].x=dp[i];
		P[cou].y=dp[i]/R[i];
		tans=max(tans,P[cou].x*A[i]+P[cou].y*B[i]);
		++cou;
	}
	sort(P,P+cou);
	top=1;
	stack[0]=0;

	for(int i=1;i<cou;++i) {
		while(top>1 && judge(stack[top-2],stack[top-1],i)) --top;
		stack[top++]=i;
	}
	kcou=0;
	for(int i=1;i<top;++i) krem[kcou++]=-(P[stack[i]].y-P[stack[i-1]].y)/(P[stack[i]].x-P[stack[i-1]].x);

	int t;
	double temp;

	for(int i=M+1;i<=RR;++i) {			// 单纯用ans不对，因为在在solve大的时候，用后面更新ans。
		t=find(-A[i]/B[i]);
		temp=P[stack[t]].x*A[i]+P[stack[t]].y*B[i];
		dp[i]=max(dp[i],max(tans,temp)*R[i]/(B[i]+R[i]*A[i]));
	}
}

void CDQ(int L,int RR) {
	if(L==RR) {
		ans=max(ans,dp[L]*A[L]+dp[L]/R[L]*B[L]);
		return;
	}

	int M=(L+RR)>>1;

	CDQ(L,M);
	solve(L,M,RR);
	CDQ(M+1,RR);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %lf",&N,&S);
	for(int i=1;i<=N;++i) scanf("%lf %lf %lf",A+i,B+i,R+i),dp[i]=0;

	ans=0;
	dp[1]=S*R[1]/(B[1]+R[1]*A[1]);
	CDQ(1,N);
	printf("%.3f\n",ans);

	return 0;
}
