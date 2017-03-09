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
// Created Time  : 2017年03月08日 星期三 12时21分00秒
// File Name     : B_2.cpp

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

char s[5000006];
bitset <1003> rwei[10],ans;

int N;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t,a;

	while(~scanf("%d",&N)) {
		for(int i=0;i<10;++i) rwei[i].reset();
		for(int i=0;i<N;++i) {
			scanf("%d",&t);
			while(t--) {
				scanf("%d",&a);
				rwei[a].set(N-1-i);
			}
		}

		scanf("%s",s);

		ans.reset();
		for(int i=0;s[i];++i) {
			ans>>=1;
			ans.set(N-1);
			ans&=rwei[s[i]-'0'];

			if(i-N+1>=0 && ans[0]) {
				char tc=s[i+1];
				s[i+1]=0;
				puts(s+(i-N+1));
				s[i+1]=tc;
			}
		}
	}

	return 0;
}
