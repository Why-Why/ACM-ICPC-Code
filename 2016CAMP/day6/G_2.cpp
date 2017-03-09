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
// Created Time  : 2017年02月18日 星期六 15时57分49秒
// File Name     : G_2.cpp

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

char rem[3000001][9];
int hnum[3000001];
int rcou;

int a,b;

set <int> sta;

inline void randString() {
	++rcou;
	for(int i=0;i<7;++i) rem[rcou][i]=rand()%26+'a';
	rem[rcou][7]=0;
}

inline int hash1(char s[]) {
	long long h=0;
	for(int i=0;s[i];++i)
		h=(h*a+s[i]-'a'+1)%b;
	return h;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	srand(time(0));

	scanf("%d %d",&a,&b);

	while(1) {
		randString();
		hnum[rcou]=hash1(rem[rcou]);

		if(sta.count(hnum[rcou])) {
			for(int i=1;i<rcou;++i)
				if(hnum[i]==hnum[rcou] && strcmp(rem[i],rem[rcou])) {
					for(int s=0;s<100;++s) {
						for(int j=0;j<7;++j)
							if(s & (1<<j)) printf("%s",rem[i]);
							else printf("%s",rem[rcou]);
						puts("");
					}
					return 0;
				}
		}

		sta.insert(hnum[rcou]);
	}

	return 0;
}
