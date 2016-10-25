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
// Created Time  : 2016年07月20日 星期三 12时09分18秒
// File Name     : 1004.cpp

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
int A[MaxN];

int dp[MaxN][20];
int logN[MaxN];

int gcd(int x,int y) {
	if(!x) return y;
	return gcd(y%x,x);
}

void init(int N,int num[]) {
	logN[0]=-1;
	for(int i=1;i<=N;++i) {
		dp[i][0]=num[i];
		logN[i]=((i&(i-1))==0) ? logN[i-1]+1 : logN[i-1];
	}
	for(int j=1;j<=logN[N];++j)
		for(int i=1;i+(1<<j)-1<=N;++i)
			dp[i][j]=gcd(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int RMQ(int x,int y) {
	int k=logN[y-x+1];
	return gcd(dp[x][k],dp[y-(1<<k)+1][k]);
}

map <int,long long > map1[2],ans;
typedef pair<int,long long> pii;
map <int,long long> ::iterator iter,iter1;
int flag;

inline void add(int x,long long y) {
	iter1=map1[flag^1].find(x);
	if(iter1!=map1[flag^1].end())
		iter1->second+=y;
	else map1[flag^1].insert(pii(x,y));
}

inline void merge() {
	for(iter=map1[flag].begin();iter!=map1[flag].end();++iter) {
		iter1=ans.find(iter->first);
		if(iter1==ans.end())
			ans.insert(pii(iter->first,iter->second));
		else iter1->second+=iter->second;
	}
}

void getans() {
	long long t;

	flag=0;
	map1[flag].clear();
	map1[flag].insert(pii(A[1],1));

	ans.clear();

	for(int i=2;i<=N;++i) {
		merge();
		map1[flag^1].clear();
		add(A[i],1);
		for(iter=map1[flag].begin();iter!=map1[flag].end();++iter) {
			t=gcd(iter->first,A[i]);
			add(t,iter->second);
		}
		flag^=1;
	}
	merge();
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int a,b,t;
	scanf("%d",&T);
	
	while(T--) {
		scanf("%d",&N);
		for(int i=1;i<=N;++i) scanf("%d",A+i);
		init(N,A);
		getans();

		scanf("%d",&Q);
		printf("Case #%d:\n",cas++);
		while(Q--) {
			scanf("%d %d",&a,&b);
			t=RMQ(a,b);
			printf("%d",t);
			iter=ans.find(t);
			if(iter==ans.end()) puts(" 0");
			else printf(" %I64d\n",iter->second);
		}
	}

	return 0;
}
