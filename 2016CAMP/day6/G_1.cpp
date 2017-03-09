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
// Created Time  : 2017年02月18日 星期六 12时15分06秒
// File Name     : G_1.cpp

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

char rem[12000001][7];
int rcou;

typedef pair<int,int> pii;
pii num[12000001];

long long a1,a2,a3,a4,a5;
long long a,b;

//pii rrr[105];
//int rrcou=0;

inline bool judge(long long rr) {
	int acou=0,L,R;
	long long r;

	for(int i=0;i<rcou && acou<100;++i) {
		r=((-a4*num[i].first)%b+b)%b;

		L=lower_bound(num,num+rcou,pii(r,-1))-num;
		R=upper_bound(num,num+rcou,pii(r,rcou+1))-num;

		for(int j=L;j<R && acou<100;++j,++acou);
			//printf("%s%s\n",rem[num[i].second],rem[num[j].second]);
			//rrr[rrcou++]=pii(num[i].second,num[j].second);
	}

	return acou>=100;
}

inline void show(long long rr) {
	int acou=0,L,R;
	long long r;

	for(int i=0;i<rcou && acou<100;++i) {
		r=((-a4*num[i].first)%b+b)%b;

		L=lower_bound(num,num+rcou,pii(r,-1))-num;
		R=upper_bound(num,num+rcou,pii(r,rcou+1))-num;

		for(int j=L;j<R && acou<100;++j,++acou)
			printf("%s%s\n",rem[num[i].second],rem[num[j].second]);
			//rrr[rrcou++]=pii(num[i].second,num[j].second);
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long r;
	scanf("%lld %lld",&a,&b);

	a1=a;
	a2=a*a%b;
	a3=a2*a%b;
	a4=a3*a%b;
	a5=a4*a%b;

	long long last=-1;

	for(int i=1;i<=26;++i)
	for(int j=1;j<=26;++j)
	for(int k=1;k<=26;++k)
	for(int l=1;l<=26;++l) {
		r=(i+j*a1+k*a2+l*a3)%b;

		rem[rcou][0]='a'+l-1;
		rem[rcou][1]='a'+k-1;
		rem[rcou][2]='a'+j-1;
		rem[rcou][3]='a'+i-1;
		rem[rcou][4]=0;

		num[rcou]=pii(r,rcou);

		++rcou;
	}

	sort(num,num+rcou);

	int rr;

	for(long long base=a,x=0;x<48;(base*=a)%=b,++x) {
		if(base%b==0) {
			int acou=0;
			for(int i=0;i<26 && acou<100;++i)
				for(int j=0;j<26 && acou<100;++j) {
					printf("%c%c",i+'a',j+'a');
					for(int t=0;t<x+1;++t) putchar('a');
					puts("");
					++acou;
				}
			return 0;
		}
	}

	while(1) {
		rr=rand()%b;
		if(judge(rr)) {
			show(rr);
			break;
		}
	}

	return 0;

	/*
	int acou=0,L,R;

	for(int i=0;i<rcou && acou<100;++i) {
		r=((-a5*num[i].first)%b+b)%b;

		L=lower_bound(num,num+rcou,pii(r,-1))-num;
		R=upper_bound(num,num+rcou,pii(r,rcou+1))-num;

		for(int j=L;j<R && acou<100;++j,++acou) {
			printf("%s%s\n",rem[num[i].second],rem[num[j].second]);
			//rrr[rrcou++]=pii(num[i].second,num[j].second);
		}
	}
	*/

	return 0;
}
