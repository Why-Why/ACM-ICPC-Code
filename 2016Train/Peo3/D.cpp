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
// Created Time  : 2016年03月05日 星期六 14时40分09秒
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

struct state {
	int a,b;

	bool operator < (const state & y) const {
		if(a==y.a) return b<y.b;
		return a<y.a;
	}
};

state num[100005];
int N;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a;
	long long len;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		for(int i=1;i<=N;++i) {
			scanf("%d",&num[i].a);
			num[i].b=i;
		}
		num[N+1].a=num[0].a=0;
		num[N+1].b=num[0].b=0;
		sort(num+1,num+N+1);

		long long zans=0;
		long long tans=0;
		for(int i=1;i<=N+1;++i)
			if(num[i].a!=num[i-1].a) {
				len=N-num[i-1].b;
				tans+=(len+1)*len/2;
				zans+=((N+1LL)*N/2LL-tans)*num[i-1].a;

				len=num[i].b-1;
				tans=(len+1)*len/2;
			}
			else {
				len=num[i].b-1-num[i-1].b;
				tans+=(len+1)*len/2;
			}
		cout<<zans<<endl;
	}
	
	return 0;
}
