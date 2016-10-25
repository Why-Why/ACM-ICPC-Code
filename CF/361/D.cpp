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
// Created Time  : 2016年07月13日 星期三 23时20分08秒
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

using namespace std;

const int MaxN=200005;

int N;
int a[MaxN],b[MaxN];
int La[MaxN],Ra[MaxN],Lb[MaxN],Rb[MaxN];

int dp1[MaxN][20],dp2[MaxN][20];
int logN[MaxN];

inline int RMQ(int dp[MaxN][20],int x,int y) {
	int k=logN[y-x+1];
	return min(dp[x][k],dp[y-(1<<k)+1][k]);
}

inline int find1(int p,int x,int dp[MaxN][20]) {
	int L=0,R=p-1,M;

	while(R>L) {
		M=(L+R+1)>>1;
		if(RMQ(dp,M,p-1)<x) L=M;
		else R=M-1;
	}
	return L+1;
}

inline int find2(int p,int x,int dp[MaxN][20]) {
	int L=p+1,R=N+1,M;

	while(R>L) {
		M=(L+R)>>1;
		if(RMQ(dp,p+1,M)<=x) R=M;
		else L=M+1;
	}
	return L-1;
}

////////////////////////

struct State {
	int v,L,M,R;

	State() {}

	State(int a,int b,int c,int d) {
		v=a;
		L=b;
		M=c;
		R=d;
	}

	bool operator < (const State & b) const {
		if(v!=b.v) return v<b.v;
		return R<b.R;
	}
};

State rem1[MaxN],rem2[MaxN];

inline long long getnum(int x,int y) {
	int a,b,c,d;
	a=max(rem1[x].L,rem2[y].L);
	b=min(rem1[x].M,rem2[y].M);
	c=max(rem1[x].M,rem2[y].M);
	d=min(rem1[x].R,rem2[y].R);
	if(a>b || c>d) return 0;
	return (b-a+1LL)*(d-c+1LL);
}

long long getans() {
	long long ret=0;
	int p=1;

	for(int i=1;i<=N;++i) {
		while(rem1[p].v<rem2[i].v) ++p;
		if(rem1[p].v>rem2[i].v) continue;
		while(rem1[p].v==rem2[i].v && rem1[p].R<rem2[i].M) ++p;
		while(rem1[p].v==rem2[i].v && rem1[p].R<=rem2[i].R) {
			ret+=getnum(p,i);
			++p;
		}
		if(rem1[p].v==rem2[i].v) ret+=getnum(p,i);
	}
	return ret;
}

////////////////////////

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	logN[0]=-1;
	for(int i=1;i<=N;++i) {
		scanf("%d",a+i);
		a[i]=-a[i];
		dp1[i][0]=a[i];
		logN[i]=((i&(i-1))==0) ? logN[i-1]+1 : logN[i-1];
	}
	for(int i=1;i<=N;++i) {
		scanf("%d",b+i);
		dp2[i][0]=b[i];
	}
	for(int j=1;j<=logN[N];++j)
		for(int i=1;i+(1<<j)-1<=N;++i) {
			dp1[i][j]=min(dp1[i][j-1],dp1[i+(1<<(j-1))][j-1]);
			dp2[i][j]=min(dp2[i][j-1],dp2[i+(1<<(j-1))][j-1]);
		}

	for(int i=1;i<=N;++i) {
		La[i]=find1(i,a[i],dp1);
		Lb[i]=find1(i,b[i],dp2);

		Ra[i]=find2(i,a[i],dp1);
		Rb[i]=find2(i,b[i],dp2);

		rem1[i]=State(-a[i],La[i],i,Ra[i]);
		rem2[i]=State(b[i],Lb[i],i,Rb[i]);
	}
	sort(rem1+1,rem1+N+1);
	sort(rem2+1,rem2+N+1);
	rem1[N+1].v=0x3f3f3f3f;

	///////////////////////////

	cout<<getans()<<endl;

	return 0;
}
