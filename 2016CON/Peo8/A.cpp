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
// Created Time  : 2016年05月21日 星期六 12时41分43秒
// File Name     : A.cpp

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

int N,M,K;
int d,m,y;
int dd,mm,yy;

inline int leap(int m,int y) {
	if(m!=2) return 0;
	if(y%400==0) return 1;
	if(y%4==0 && y%100) return 1;
	return 0;
}

const int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

inline void add(int &d,int &m,int &y,int a,int b) {
	y+=a;
	m+=b;

	while(m>12) {
		m-=12;
		++y;
	}

	if(d>month[m]+leap(m,y)) {
		++m;
		d=1;
	}

	while(m>12) {
		m-=12;
		++y;
	}
}

inline bool judge(int s1,int s2) {
	int y1=y,yy1=yy,m1=m,mm1=mm,d1=d,dd1=dd;
	add(d1,m1,y1,60,s1);
	add(dd1,mm1,yy1,0,s2);

	if(y1<yy1) return 1;
	if(y1>yy1) return 0;
	if(m1<mm1) return 1;
	if(m1>mm1) return 0;
	if(d1<dd1) return 1;
	return 0;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d",&M,&N,&K);
	scanf("%d.%d.%d",&d,&m,&y);
	dd=1;
	mm=1;
	yy=2012;

	int sum1=0,sum2=0;

	for(int i=1;i<=K;++i) {
		if(judge(sum1,sum2)) break;
		sum1+=M;
		sum2+=N;
	}

	add(d,m,y,60,sum1);
	printf("%02d.%02d.%04d\n",d,m,y);
	
	return 0;
}
