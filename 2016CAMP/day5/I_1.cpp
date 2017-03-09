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
// Created Time  : 2017年02月17日 星期五 20时10分26秒
// File Name     : I_1.cpp

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

int vis[MaxN];
int rcou[MaxN],rem[MaxN][9];

int a[MaxN];
vector <int> rrr[MaxN];

inline void fen(int p,int x) {
	int t;

	for(int i=0;i<(1<<rcou[x]);++i) {
		t=1;
		for(int j=0;j<rcou[x];++j)
			if(i&(1<<j)) t*=rem[x][j];
		rrr[t].push_back(p);
	}
}

inline int cal1(int p,int x) {
	return upper_bound(rrr[x].begin(),rrr[x].end(),p)-rrr[x].begin();
}

inline int cal(int p,int x) {
	int t,ts;
	int ret=0;

	for(int i=0;i<(1<<rcou[x]);++i) {
		t=1;
		ts=0;
		for(int j=0;j<rcou[x];++j)
			if(i&(1<<j)) t*=rem[x][j],++ts;

		if(ts&1) ret-=cal1(p,t);
		else ret+=cal1(p,t);
	}

	return ret;
}

inline int solve(int L,int R,int x) {
	if(cal(R,x)-cal(L-1,x)==0) return -1;

	int M;
	while(R>L) {
		M=(L+R+1)>>1;
		if(cal(R,x)-cal(M-1,x)) L=M;
		else R=M-1;
	}

	return L;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	vis[1]=1;
	rcou[1]=0;
	for(int i=2;i<MaxN;++i)
		if(!vis[i]) {
			vis[i]=i;
			for(int j=i+i;j<MaxN;j+=i)
				if(!vis[j]) vis[j]=i;

			rem[i][rcou[i]++]=i;
		}
		else {
			int t=i/vis[i];
			if(vis[i]!=rem[t][0]) rem[i][rcou[i]++]=vis[i];
			for(int j=0;j<rcou[t];++j) rem[i][rcou[i]++]=rem[t][j];
		}

	int N,Q,l,r,x;

	scanf("%d %d",&N,&Q);
	for(int i=1;i<=N;++i) {
		scanf("%d",a+i);
		fen(i,a[i]);
	}

	while(Q--) {
		scanf("%d %d %d",&l,&r,&x);
		printf("%d\n",solve(l,r,x));
	}

	return 0;
}
