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
// Created Time  : 2016年07月14日 星期四 19时54分16秒
// File Name     : A.cpp

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

const int MaxN=105;

int N,D;

char s[MaxN];

inline bool judge(char s[]) {
	for(int i=1;i<=N;++i)
		if(s[i]=='0') return 1;
	return 0;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int ans=0;
	int cou=0;

	scanf("%d %d",&N,&D);
	for(int i=1;i<=D;++i) {
		scanf("%s",s+1);
		if(judge(s)) ++cou;
		else {
			ans=max(ans,cou);
			cou=0;
		}
	}
	ans=max(ans,cou);

	printf("%d\n",ans);
	
	return 0;
}
