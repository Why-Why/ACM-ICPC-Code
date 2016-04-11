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
// Created Time  : 2016年02月27日 星期六 13时41分59秒
// File Name     : G.cpp

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

const int MaxN=2005;

int N,K;
int rem[(1<<16)+5];
char s[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int have;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&N,&K);
		scanf("%s",s);
		for(int i=0;i<(1<<K);++i) rem[i]=0;
		for(int i=0;i<N;++i) {
			have=0;
			for(int j=i;j<N;++j) {
				have|=(1<<(s[j]-'a'));
				rem[have]=max(rem[have],j-i+1);
			}
		}

		for(int i=0;i<(1<<K);++i)
			for(int j=0;j<K;++j)
				if(i & (1<<j))
					rem[i]=max(rem[i],rem[i^(1<<j)]);

		int ans=0;
		for(int i=0;i<(1<<K);++i)
			if(rem[i] && rem[(~i)&((1<<K)-1)])
				ans=max(ans,rem[i]*rem[(~i)&((1<<K)-1)]);

		printf("%d\n",ans);
	}
	
	return 0;
}
