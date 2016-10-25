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
// Created Time  : 2016年09月03日 星期六 15时27分37秒
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

int N;
char s[1005][20];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	bool ok=0;

	scanf("%d",&N);
	for(int i=1;i<=N;++i) {
		scanf("%s",s[i]);
		if(ok) continue;
		if(s[i][0]=='O' && s[i][1]=='O') {
			ok=1;
			s[i][0]=s[i][1]='+';
		}
		else if(s[i][3]=='O' && s[i][4]=='O') {
			ok=1;
			s[i][3]=s[i][4]='+';
		}
	}

	if(ok) {
		puts("YES");
		for(int i=1;i<=N;++i) puts(s[i]);
	}
	else puts("NO");

	return 0;
}
