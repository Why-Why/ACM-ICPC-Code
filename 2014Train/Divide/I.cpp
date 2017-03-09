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
// Created Time  : 2016年01月01日 星期五 01时09分35秒
// File Name     : I.cpp

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

struct State {
	int x,y,z;
	int id;

	bool operator < (const State &b) const {
		if(x==b.x) {
			if(y==b.y) return z<b.z;
			return y<b.y;
		}
		return x<b.x;
	}
}sta[MaxN];

int N;
int dp[MaxN];
unsigned int dp2[MaxN];
int ans1;
unsigned int ans2;

struct REM {
	int a,b,id;

	bool operator < (const REM &y) const {
		if(a==y.a) return b<y.b;
		return a<y.a;
	}
}rem[MaxN];

int cou;

int hrem[MaxN],Hcou;
int C[MaxN];
unsigned int C2[MaxN];
int vis[MaxN],flag;

inline int hash1(int x) {
	return lower_bound(hrem+1,hrem+Hcou,x)-hrem;
}

inline int lowbit(int x) {
	return x&(-x);
}

void update(int x,int d,unsigned int d2) {
	for(;x<=Hcou;x+=lowbit(x))
		if(vis[x]!=flag) {
			vis[x]=flag;
			C[x]=d;
			C2[x]=d2;
		}
		else if(C[x]<d) {
			C[x]=d;
			C2[x]=d2;
		}
		else if(C[x]==d)
			C2[x]+=d2;
}

int query(int x,int ret,unsigned int &ret2) {
	for(;x;x-=lowbit(x))
		if(vis[x]==flag)
			if(C[x]>ret) {
				ret=C[x];
				ret2=C2[x];
			}
			else if(C[x]==ret) ret2+=C2[x];
	return ret;
}

void solve(int L,int M,int R) {
	++flag;
	cou=0;
	for(int i=L;i<=R;++i) {
		rem[cou].a=sta[i].y;
		rem[cou].b=sta[i].z;
		rem[cou++].id=i;
	}
	sort(rem,rem+cou);

	for(int i=0;i<cou;++i) {
		if(rem[i].id<=M) update(hash1(rem[i].b),dp[rem[i].id],dp2[rem[i].id]);
		else {
			dp[rem[i].id]=query(hash1(rem[i].b),dp[rem[i].id]-1,dp2[rem[i].id])+1;
		}
	}
}

void CDQ(int L,int R) {
	if(L==R) {
		if(ans1<dp[L]) {
			ans1=dp[L];
			ans2=dp2[L];
		}
		else if(ans1==dp[L]) ans2+=dp2[L];
		return;
	}

	int M=(L+R)>>1;
	CDQ(L,M);
	solve(L,M,R);
	CDQ(M+1,R);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		Hcou=0;
		for(int i=1;i<=N;++i) scanf("%d %d %d",&sta[i].x,&sta[i].y,&sta[i].z),hrem[++Hcou]=sta[i].z;
		sort(hrem+1,hrem+Hcou+1);
		Hcou=unique(hrem+1,hrem+Hcou+1)-hrem-1;
		sort(sta+1,sta+N+1);
		ans1=ans2=0;
		for(int i=1;i<=N;++i) dp[i]=dp2[i]=1;
		CDQ(1,N);
		printf("%d %u\n",ans1,ans2%(1<<30));
	}
	
	return 0;
}
