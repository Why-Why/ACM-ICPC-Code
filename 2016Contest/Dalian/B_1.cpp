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
// Created Time  : 2017年03月08日 星期三 11时51分24秒
// File Name     : B_1.cpp

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
#include <bitset>

using namespace std;

bitset <5000001> rwei[10],ans,tmp;
char s[5000006];

int N;
int rem[1003][11],rcou[1003];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N)) {
		for(int i=0;i<10;++i) rwei[i].reset();
		for(int i=1;i<=N;++i) {
			scanf("%d",rcou+i);
			for(int j=1;j<=rcou[i];++j) scanf("%d",&rem[i][j]);
		}

		scanf("%s",s);
		for(int i=0;s[i];++i) rwei[s[i]-'0'].set(i);

		ans.set();
		for(int i=1;i<=N;++i) {
			tmp.reset();
			for(int j=1;j<=rcou[i];++j) tmp|=rwei[rem[i][j]];
			ans&=(tmp>>(i-1));
		}

		char tc;

		for(int i=0;s[i];++i)
			if(ans[i]) {
				tc=s[i+N];
				s[i+N]=0;
				puts(s+i);
				s[i+N]=tc;
			}
	}

	return 0;
}
