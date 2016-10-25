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
// Created Time  : 2016年07月03日 星期日 13时14分02秒
// File Name     : B.cpp

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

int a,b,c;

inline bool judge(int a,int b,int z,int M) {
	int R=2*a-3*M,L=3*M-2*b;
	int R1=a/2,L1=-a,R2=b,L2=-(b/2);

	if(R1<L2 || L1>R2) return 0;
	L1=max(L1,L2);
	R1=min(R1,R2);

	R1=min(R1,z+1);
	L1=max(L1,-1-z);

	if(R1<L1) return 0;
	if(R<L) return 0;
	//if(R<L) swap(L,R);

	if(L<=R1 && R>=L1) return 1;
	return 0;
}

inline int getans(int a,int b,int z) {
	int R=(a+b)/3,L=0,M;

	while(R>L) {
		M=(L+R+1)>>1;
		if(judge(a,b,z,M)) L=M;
		else R=M-1;
	}

	if(L>=z-1) return L+z;
	return 0;
}

inline int getans() {
	int ret=0;
	for(int i=0;i<=c;++i)
		ret=max(ret,getans(a-i,b-i,i));
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);
	while(T--) {
		scanf("%d %d %d",&a,&b,&c);
		printf("%d\n",getans());
	}
	
	return 0;
}
