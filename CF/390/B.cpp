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
// Created Time  : 2017年01月08日 星期日 17时27分13秒
// File Name     : B.cpp

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

char map1[7][7];

inline bool judge(int x,int y) {
	if(map1[x][y]=='x' && map1[x-1][y]=='x' && map1[x+1][y]=='x') return 1;
	if(map1[x][y]=='x' && map1[x][y-1]=='x' && map1[x][y+1]=='x') return 1;
	if(map1[x][y]=='x' && map1[x-1][y-1]=='x' && map1[x+1][y+1]=='x') return 1;
	if(map1[x][y]=='x' && map1[x-1][y+1]=='x' && map1[x+1][y-1]=='x') return 1;
	return 0;
}

inline bool judge() {
	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j)
			if(judge(i,j)) return 1;
	return 0;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	for(int i=1;i<=4;++i) scanf("%s",map1[i]+1);
	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j)
			if(map1[i][j]=='.') {
				map1[i][j]='x';
				if(judge()) {
					puts("YES");
					return 0;
				}
				map1[i][j]='.';
			}
	puts("NO");

	return 0;
}
