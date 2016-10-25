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
// Created Time  : 2016年07月14日 星期四 17时42分11秒
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

const int MaxN=400005;
const int mod=1000000007;

int N,K;
int L[MaxN],R[MaxN];
int rem[MaxN],rcou;

long long jie[MaxN],njie[MaxN];

long long inv(long long a,long long m) {
	if(a==1) return 1;
	return inv(m%a,m)*(m-m/a)%m;
}

void init() {
	jie[0]=1;
	njie[0]=inv(jie[0],mod);
	for(int i=1;i<MaxN;++i) {
		jie[i]=jie[i-1]*i%mod;
		njie[i]=inv(jie[i],mod);
	}
}

inline int find(int x) {
	return lower_bound(rem+1,rem+rcou+1,x)-rem;
}

inline long long getC(long long n,long long m) {
	if(n<m) return 0;
	return jie[n]*njie[m]%mod*njie[n-m]%mod;
}

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

int BIT[MaxN<<2];
int COL[MaxN<<2];

inline void pushUP(int po) {
	BIT[po]=BIT[lc]+BIT[rc];
}

inline void pushDown(int L,int M,int R,int po) {
	if(COL[po]) {
		COL[lc]+=COL[po];
		COL[rc]+=COL[po];
		BIT[lc]+=(M-L+1)*COL[po];
		BIT[rc]+=(R-M)*COL[po];
		COL[po]=0;
	}
}

void update(int ul,int ur,int ut,int L,int R,int po) {
	if(ul<=L && ur>=R) {
		BIT[po]+=ut*(R-L+1);
		COL[po]+=ut;
		return;
	}

	int M=(L+R)>>1;

	pushDown(L,M,R,po);
	if(ul<=M) update(ul,ur,ut,lson);
	if(ur>M) update(ul,ur,ut,rson);
	pushUP(po);
}

int query(int p,int L,int R,int po) {
	if(L==R) return BIT[po];

	int M=(L+R)>>1;
	pushDown(L,M,R,po);
	if(p<=M) return query(p,lson);
	else return query(p,rson);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();
	scanf("%d %d",&N,&K);
	for(int i=1;i<=N;++i) {
		scanf("%d %d",L+i,R+i);
		++R[i];
		rem[++rcou]=L[i];
		rem[++rcou]=R[i];
	}
	sort(rem+1,rem+rcou+1);
	rcou=unique(rem+1,rem+rcou+1)-rem-1;

	for(int i=1;i<=N;++i)
		update(find(L[i]),find(R[i])-1,1,1,rcou,1);

	long long ans=0;

	for(int i=1;i<rcou;++i)
		(ans+=getC(query(i,1,rcou,1),K)*(rem[i+1]-rem[i]))%=mod;

	cout<<ans<<endl;

	return 0;
}
