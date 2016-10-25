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
// Created Time  : 2016年10月07日 星期五 12时50分09秒
// File Name     : M.cpp

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

int r,c,R,C;
char map1[23][23],map2[23][23];

inline int count(int x) {
	int ret=0;
	for(;x;x-=x&(-x)) ++ret;
	return ret;
}

inline bool check(int sta,int L,int l) {
	int cou=0;

	for(int i=1;i<=C;++i)
		if(sta&(1<<(i-1))) {
			++cou;
			if(map2[L][i]!=map1[l][cou]) return 0;
		}

	return 1;
}

inline bool judge(int sta) {
	int p=1;

	for(int i=1;i<=R;++i)
		if(check(sta,i,p)) {
			++p;
			if(p>r) return 1;
		}

	return 0;
}

bool getans() {
	for(int i=1;i<(1<<C);++i)
		if(count(i)==c)
			if(judge(i)) return 1;
	return 0;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&r,&c);
	for(int i=1;i<=r;++i) scanf("%s",map1[i]+1);

	scanf("%d %d",&R,&C);
	for(int i=1;i<=R;++i) scanf("%s",map2[i]+1);

	if(getans()) puts("Yes");
	else puts("No");

	return 0;
}
