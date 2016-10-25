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
// Created Time  : 2016年10月24日 星期一 22时47分52秒
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

#include <stdarg.h>

using namespace std;

struct State {
	int r,p;

	bool operator < (const State & b) const {
		return r>b.r;
	}
};

State num[111];
int N;

char aaa[10003][103];
int cou;

inline void add(int n,...) {
	va_list arg;

	va_start(arg,n);		// ??? +3 ?

	for(int i=0;i<N;++i) aaa[cou][i]='0';
	aaa[cou][N]=0;

	for(int i=0;i<n;++i) {
		int t=va_arg(arg,int);
		aaa[cou][t-1]='1';
	}

	++cou;
}

//////////////////////////

inline void jian(int L,int R,int d) {
	for(int i=L;i<=R;i+=2) {
		for(int j=0;j<d;++j)
			if(i+2==R) add(3,num[i].p,num[i+1].p,num[i+2].p);
			else add(2,num[i].p,num[i+1].p);

		if(i+2==R) break;
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<=N;++i) scanf("%d",&num[i].r),num[i].p=i;
	sort(num+1,num+N+1);

	int ans;
	for(ans=num[N].r;ans>=1;--ans) {
		int sum=0;
		for(int i=3;i<=N;++i) sum+=num[i].r-ans;

		if(sum>=num[1].r-num[2].r) break;
	}

	printf("%d\n",ans);

	if(ans==0) {
		for(int i=1;i<=N;i+=2) {
			for(int j=0;j<num[i].r;++j)
				if(i+2==N) add(3,num[i].p,num[i+1].p,num[i+2].p);
				else add(2,num[i].p,num[i+1].p);

			if(i+2==N) break;
		}
	}
	else {
		int p=3;

		while(num[1].r>num[2].r) {
			while(num[p].r<=ans) ++p;
			--num[p].r;
			--num[1].r;

			add(2,num[p].p,num[1].p);
		}

		sort(num+1,num+N+1);

		p=2;
		while(p<=N) {
			while(p<=N && num[p].r==num[p-1].r) ++p;
			if(p>N) break;

			jian(1,p-1,num[1].r-num[p].r);
			for(int i=1;i<=p-1;++i) num[i].r=num[p].r;
		}
	}

	printf("%d\n",cou);
	for(int i=0;i<cou;++i) puts(aaa[i]);

	return 0;
}
