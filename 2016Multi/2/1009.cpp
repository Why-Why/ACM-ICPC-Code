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
// Created Time  : 2016年07月21日 星期四 12时18分46秒
// File Name     : 1009.cpp

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

int num[111];
int N;

int gcd(int a,int b) {
	if(!a) return b;
	return gcd(b%a,a);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,M,a,b;

	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&N,&M);
		memset(num,-1,sizeof(num));

		while(M--) {
			scanf("%d %d",&a,&b);
			num[a]=b;
		}

		if(num[1]==-1) num[1]=100;
		if(num[2]==-1) num[2]=min(num[1],100);

		int rem=0;
		for(int i=N;i>2;--i)
			if(num[i]==-1) num[i]=rem;
			else rem=num[i];

		int s=0,x=0;
		s=num[1]+num[2];
		for(int i=1;i<=N;++i) x+=num[i];

		int t=gcd(s,x);
		s/=t;
		x/=t;

		printf("%d/%d\n",s,x);
	}

	return 0;
}
