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
// Created Time  : 2016年05月22日 星期日 14时43分40秒
// File Name     : F.cpp

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

const int MaxN=8005;

int N,num[MaxN];
int fnum;

int cou[MaxN<<2];

inline long long getans(int ii) {
	memset(cou,0,sizeof(cou));
	int a=0;
	long long ret=0;
	++cou[N];
	for(int i=1;i<=N;++i) {
		if(num[i]>=fnum) ++a;
		if(i>=ii) ret+=cou[(a<<1)-i-1+N];
		else ++cou[(a<<1)-i+N];
	}
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N)) {
		for(int i=1;i<=N;++i) scanf("%d",num+i);
		for(int i=1;i<=N;++i) {
			fnum=num[i];
			if(i>1) putchar(' ');
			printf("%lld",getans(i));
		}
		puts("");
	}
	
	return 0;
}
