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
// Created Time  : 2016年08月11日 星期四 12时09分04秒
// File Name     : 1011.cpp

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

const int MaxN=100005;

int N;
char s[MaxN];

inline bool getans() {
	int coul=0,v=0;
	bool bian=0;

	if(N&1) return 0;

	for(int i=1;i<=N;++i)
		if(s[i]=='(') {
			++coul;
			++v;
		}
		else {
			--v;

			if(v<0) {
				if(bian) return 0;
				v+=2;
				bian=1;
			}
		}

	if(coul+coul!=N) return 0;

	if(!bian) {
		if(N==2) return 0;
		return 1;
	}

	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		scanf("%s",s+1);
		if(getans()) puts("Yes");
		else puts("No");
	}

	return 0;
}
