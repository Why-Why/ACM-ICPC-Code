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
// Created Time  : 2016年09月17日 星期六 12时57分59秒
// File Name     : 1007.cpp

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

int N,TT;
int A[MaxN];
long long t1[MaxN*5],t2[MaxN*5];
int f1=0,l1=0,f2=0,l2=0;

inline long long getK(int K) {
	long long ret=0,cou=0,t;

	while(cou<K) {
		if(l1-f1+l2-f2==0) break;

		if(l2-f2==0) t=t1[f1++];
		else if(l1-f1==0) t=t2[f2++];
		else {
			if(t1[f1]>t2[f2]) t=t2[f2++];
			else t=t1[f1++];
		}
		++cou;
		ret+=t;
	}

	return ret;
}

inline bool judge(int M) {
	f1=l1=0;
	f2=l2=0;

	int x0,tt;

	tt=N%(M-1);
	if(tt==0) x0=1;
	else if(tt==1) x0=0;
	else x0=M-tt;

	while(x0--) t1[l1++]=0;
	for(int i=1;i<=N;++i) t1[l1++]=A[i];

	long long ans=0,t;

	while(l1-f1+l2-f2>1) {
		t=getK(M);
		ans+=t;
		t2[l2++]=t;
	}

	return ans<=TT;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&TT);
		for(int i=1;i<=N;++i) scanf("%d",A+i);
		sort(A+1,A+N+1);

		int L=2,R=N,M;
		while(R>L) {
			M=(L+R)>>1;
			if(judge(M)) R=M;
			else L=M+1;
		}
		printf("%d\n",L);
	}

	return 0;
}
