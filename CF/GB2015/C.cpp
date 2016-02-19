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
// Created Time  : 2015年12月30日 星期三 23时45分07秒
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

const int MaxN=505;

int ans1[MaxN][MaxN],ans2[MaxN][MaxN];
char map1[MaxN][MaxN];
int H,W;

void init() {
	for(int i=1;i<=H;++i)
		for(int j=1;j<=W;++j) {
			if(map1[i][j]=='.' && (j==1 || map1[i][j-1]=='.')) ++ans1[i][j];
			if(map1[i][j]=='.' && (i==1 || map1[i-1][j]=='.')) ++ans2[i][j];
		}

	for(int i=1;i<=H;++i)
		for(int j=1;j<=W;++j) {
			ans1[i][j]=ans1[i][j]+ans1[i-1][j]+ans1[i][j-1]-ans1[i-1][j-1];
			ans2[i][j]=ans2[i][j]+ans2[i-1][j]+ans2[i][j-1]-ans2[i-1][j-1];
		}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&H,&W);
	for(int i=1;i<=H;++i) scanf("%s",map1[i]+1);

	init();

	int Q,a,b,c,d;
	scanf("%d",&Q);

	while(Q--) {
		scanf("%d %d %d %d",&a,&b,&c,&d);
		printf("%d\n",(ans1[c][d]-ans1[c][b]-ans1[a-1][d]+ans1[a-1][b])+(ans2[c][d]-ans2[c][b-1]-ans2[a][d]+ans2[a][b-1]));
	}
	
	return 0;
}
