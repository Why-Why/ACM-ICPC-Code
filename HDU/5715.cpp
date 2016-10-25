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
// Created Time  : 2016年05月30日 星期一 20时23分37秒
// File Name     : 5715.cpp

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

const int MaxN=10005;

int N,M,L;
int num[MaxN];
long long sum[MaxN];
typedef pair<long long,long long> pii;
bool DP1[MaxN],DP2[MaxN],*dp1,*dp2;

struct Tree {
	const static int MaxL=320005;

	int next[MaxL][2],val[MaxL];
	int Tcou,root;
	int cou;

	int newNode() {
		++Tcou;
		next[Tcou][0]=next[Tcou][1]=0;
		val[Tcou]=0;
		return Tcou;
	}

	void init() {
		Tcou=-1;
		root=newNode();
		cou=0;
	}

	void insert(int x) {
		++cou;
		int t,p=0;

		for(int i=30;i>=0;--i) {
			t=(x&(1<<i)) ? 1 : 0;
			if(next[p][t]==0) next[p][t]=newNode();
			++val[p];
			p=next[p][t];
		}
		++val[p];
	}

	void erase(int x) {
		--cou;
		int t,p=0,rem[40],r1[40];

		for(int i=30;i>=0;--i) {
			t=(x&(1<<i)) ? 1 : 0;
			if(next[p][t]==0) return;
			--val[p];
			rem[i]=p;
			r1[i]=t;
			p=next[p][t];
		}
		--val[p];

		for(int i=0;i<=30;++i)
			if(val[p]==0) {
				next[rem[i]][r1[i]]=0;
				p=rem[i];
			}
	}

	int find(int x) {
		int t,p=0,ret=0;

		for(int i=30;i>=0;--i) {
			t=(x&(1<<i)) ? 0 : 1;
			if(next[p][t]==0) t=!t;
			else ret|=(1<<i);
			p=next[p][t];
		}
		return ret;
	}

	int size() {
		return cou;
	}

}tree;

inline bool judge(long long mid) {
	dp1=DP1;
	dp2=DP2;
	memset(DP1,0,sizeof(DP1));
	memset(DP2,0,sizeof(DP2));		// !!!

	int p2;

	for(int i=1;i<=M;++i) {
		tree.init();
		dp1[0]=0;
		if(i==1) tree.insert(0),dp1[0]=1;
		p2=0;

		for(int j=1;j<=N;++j) {
			if(dp1[j]) tree.insert(sum[j]);
			//while(!que.empty() && que.top().second<j-L) que.pop();
			while(p2<j-L) {
				if(dp1[p2]) tree.erase(sum[p2]);
				++p2;
			}

			if(tree.size() && tree.find(sum[j])>=mid) {
				dp2[j]=1;
				if(i==M && j==N) return 1;
			}
			else dp2[j]=0;
		}

		swap(dp1,dp2);
	}

	return 0;
}

long long getans() {
	long long L=0,R=2147483647,mid;

	while(R>L) {
		mid=(L+R+1)>>1;
		if(judge(mid)) L=mid;
		else R=mid-1;
	}

	return L;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d %d",&N,&M,&L);
		sum[0]=0;
		for(int i=1;i<=N;++i) scanf("%d",num+i),sum[i]=sum[i-1]^num[i];
		printf("Case #%d:\n%I64d\n",cas++,getans());
	}
	
	return 0;
}
