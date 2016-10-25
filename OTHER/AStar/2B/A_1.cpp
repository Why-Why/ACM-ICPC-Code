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
// Created Time  : 2016年05月22日 星期日 15时47分57秒
// File Name     : A_1.cpp

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

int N,num[MaxN];

int minn[MaxN][20],maxn[MaxN][20];
int minp[MaxN][20];
int logN[MaxN];

void init(int N,int num[]) {
	logN[0]=-1;
	for(int i=1;i<=N;++i) {
		minn[i][0]=maxn[i][0]=num[i];
		minp[i][0]=i;
		logN[i]=((i&(i-1))==0) ? logN[i-1]+1 : logN[i-1];
	}

	for(int j=1;j<=logN[N];++j)
		for(int i=1;i+(1<<j)-1<=N;++i) {
			minn[i][j]=min(minn[i][j-1],minn[i+(1<<(j-1))][j-1]);
			maxn[i][j]=max(maxn[i][j-1],maxn[i+(1<<(j-1))][j-1]);
			if(minn[i][j-1]<=minn[i+(1<<(j-1))][j-1]) minp[i][j]=minp[i][j-1];
			else minp[i][j]=minp[i+(1<<(j-1))][j-1];
		}
}

inline int find(int L,int R) {
	int k=logN[R-L+1];
	if(minn[L][k]<=minn[R-(1<<k)+1][k]) return minp[L][k];
	else return minp[R-(1<<k)+1][k];
}

inline long long gmax(int L,int R) {
	int k=logN[R-L+1];
	return max(maxn[L][k],maxn[R-(1<<k)+1][k]);
}

inline long long gmin(int L,int R) {
	int k=logN[R-L+1];
	return min(minn[L][k],minn[R-(1<<k)+1][k]);
}

inline long long getans(int len) {
	int s=1,a,b,p;
	long long ret=0;

	//cerr<<len<<endl;

	while(s<=N) {
		p=find(s,min(s-1+len,N));
		a=max(s,p+1-len);
		b=min(p-1+len,s-1+len);
		b=min(b,N);

		//cerr<<p<<' '<<a<<' '<<b<<endl;

		if(b-a+1>=len) ret=max(gmax(a,b)*gmin(a,b),ret);

		if(p==s) s=p+1;
		else s=p;
	}
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N)) {
		for(int i=1;i<=N;++i) scanf("%d",num+i);
		init(N,num);
		for(int i=1;i<=N;++i) printf("%I64d\n",getans(i));
	}
	
	return 0;
}
