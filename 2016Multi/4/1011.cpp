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
// Created Time  : 2016年07月28日 星期四 12时31分01秒
// File Name     : 1010.cpp

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

char rem[][30]={"Cleveland Cavaliers","Golden State Warriors","San Antonio Spurs","Miami Heat","Miami Heat","Dallas Mavericks","L.A. Lakers","L.A. Lakers","Boston Celtics","San Antonio Spurs","Miami Heat","San Antonio Spurs","Detroit Pistons","San Antonio Spurs","L.A. Lakers","L.A. Lakers","L.A. Lakers","San Antonio Spurs","Chicago Bulls","Chicago Bulls","Chicago Bulls","Houston Rockets","Houston Rockets","Chicago Bulls","Chicago Bulls","Chicago Bulls","Detroit Pistons","Detroit Pistons","L.A. Lakers","L.A. Lakers","Boston Celtics","L.A. Lakers","Boston Celtics","Philadelphia 76ers","L.A. Lakers","Boston Celtics","L.A. Lakers","Seattle Sonics","Washington Bullets","Portland Trail Blazers","Boston Celtics","Golden State Warriors","Boston Celtics","New York Knicks","L.A. Lakers","Milwaukee Bucks","New York Knicks","Boston Celtics","Boston Celtics","Philadelphia 76ers","Boston Celtics","Boston Celtics","Boston Celtics","Boston Celtics","Boston Celtics","Boston Celtics","Boston Celtics","Boston Celtics","St. Louis Hawks","Boston Celtics","Philadelphia Warriors","Syracuse Nats","Minneapolis Lakers","Minneapolis Lakers","Minneapolis Lakers","Rochester Royals","Minneapolis Lakers","Minneapolis Lakers","Baltimore Bullets","Philadelphia Warriors"};

int getans(char s[]) {
	int ret=0;
	for(int i=0;i<70;++i)
		if(strcmp(s,rem[i])==0) ++ret;
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	char s[30];

	scanf("%d",&T);
	getchar();
	while(T--) {
		gets(s);
		printf("Case #%d: %d\n",cas++,getans(s));
	}

	return 0;
}
