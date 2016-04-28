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
// Created Time  : 2016年04月23日 星期六 14时55分14秒
// File Name     : D.cpp

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

const int MaxN=1000000;

int rcou,rrr[MaxN];

const int M[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

inline bool run(int x) {
	if(x%400==0) return 1;
	if(x%100==0) return 0;
	if(x%4==0) return 1;
	return 0;
}

void init() {
	rcou=0;
	int y=1753,m=1,d=1,w=1;

	int last=0;

	while(1) {
		if(w==1 && (d==1 || d==11 || d==21)) rrr[rcou++]=y*10000+m*100+d;

		//if(w==1 && d==1 && m==1) {
		//	cout<<y<<endl;
		//}

		++w;
		if(w>7) w=1;

		++d;
		if(d>M[m]) {
			if(m!=2 || (m==2 && run(y)==0)) {
				d=1;
				++m;
				if(m>12) {
					m=1;
					++y;
				}
			}
			else if(d>M[m]+1) {
				d=1;
				++m;
				if(m>12) {
					m=1;
					++y;
				}
			}
		}

		if(y>9999) break;
	}

	//cout<<rcou<<endl;
}

inline void show(long long x,long long d) {
	long long a=x/10000+d*400;
	long long b=(x%10000)/100;
	long long c=x%100;

	printf("%lld %lld %lld\n",a,b,c);
}

inline void find(long long x) {
	long long d=x/2058;
	x%=2058;

	show(rrr[x],d);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();
	int T,a,b,c,d;

	scanf("%d",&T);
	while(T--) {
		scanf("%d %d %d %d",&a,&b,&c,&d);
		long long t=a*10000+b*100+c;
		t=lower_bound(rrr,rrr+rcou,t)-rrr;
		find(t+d-1LL);
	}
	
	return 0;
}
