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
// Created Time  : 2016年09月22日 星期四 23时41分32秒
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

const int MaxN=(1<<16)+5;

int N;
int R[3],L[3],U[3],D[3];

inline int judgeC(int L,int R) {
	if(L>R) return -1;

	printf("? %d %d %d %d\n",1,L,N,R);
	fflush(stdout);

	int ret=0;
	scanf("%d",&ret);
	return ret;
}

inline int judgeR(int L,int R) {
	if(L>R) return -1;

	printf("? %d %d %d %d\n",L,1,R,N);
	fflush(stdout);

	int ret=0;
	scanf("%d",&ret);
	return ret;
}

inline int judge(int x1,int y1,int x2,int y2) {
	if(x1>x2 || y1>y2) return -1;

	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);

	int ret;
	scanf("%d",&ret);
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);

	int l=1,r=N,m;

	while(r>l) {
		m=(l+r)>>1;
		if(judgeC(1,m)>=2) r=m;
		else l=m+1;
	}
	R[2]=l;

	l=1,r=N;
	while(r>l) {
		m=(l+r)>>1;
		if(judgeC(1,m)>=1) r=m;
		else l=m+1;
	}
	R[1]=l;

	l=1,r=N;
	while(r>l) {
		m=(l+r+1)>>1;
		if(judgeC(m,N)>=2) l=m;
		else r=m-1;
	}
	L[2]=l;

	l=1,r=N;
	while(r>l) {
		m=(l+r+1)>>1;
		if(judgeC(m,N)>=1) l=m;
		else r=m-1;
	}
	L[1]=l;

	l=1,r=N;
	while(r>l) {
		m=(l+r)>>1;
		if(judgeR(1,m)>=2) r=m;
		else l=m+1;
	}
	U[2]=l;

	l=1,r=N;
	while(r>l) {
		m=(l+r)>>1;
		if(judgeR(1,m)>=1) r=m;
		else l=m+1;
	}
	U[1]=l;

	l=1,r=N;
	while(r>l) {
		m=(l+r+1)>>1;
		if(judgeR(m,N)>=2) l=m;
		else r=m-1;
	}
	D[2]=l;

	l=1,r=N;
	while(r>l) {
		m=(l+r+1)>>1;
		if(judgeR(m,N)>=1) l=m;
		else r=m-1;
	}
	D[1]=l;

	//cout<<R[1]<<' '<<R[2]<<' '<<L[1]<<' '<<L[2]<<endl;
	//cout<<U[1]<<' '<<U[2]<<' '<<D[1]<<' '<<D[2]<<endl;

	for(int i=1;i<=2;++i)
		for(int j=1;j<=2;++j)
			for(int k=1;k<=2;++k)
				for(int l=1;l<=2;++l)
					if(judge(D[i],L[j],U[k],R[l])==1 && judge(D[3-i],L[3-j],U[3-k],R[3-l])==1) {
						printf("! %d %d %d %d %d %d %d %d\n",D[i],L[j],U[k],R[l],D[3-i],L[3-j],U[3-k],R[3-l]);
						fflush(stdout);
						return 0;
					}

	//while(1);

	return 0;
}
