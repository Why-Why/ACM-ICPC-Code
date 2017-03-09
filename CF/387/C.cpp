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
// Created Time  : 2017年01月16日 星期一 14时41分01秒
// File Name     : C.cpp

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

int eend[111];
int N;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int Q,t,k,d;

	scanf("%d %d",&N,&Q);
	while(Q--) {
		scanf("%d %d %d",&t,&k,&d);
		int ans=0,acou=0;
		for(int i=1;i<=N && acou<k;++i)
			if(eend[i]<=t) {
				ans+=i;
				++acou;
			}
		if(acou<k) ans=-1;
		else {
			acou=0;
			for(int i=1;i<=N && acou<k;++i)
				if(eend[i]<=t) {
					eend[i]=t+d;
					++acou;
				}
		}

		printf("%d\n",ans);
	}

	return 0;
}
