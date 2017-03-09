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
// Created Time  : 2017年02月21日 星期二 17时26分27秒
// File Name     : L.cpp

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

const int game[][2]={{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
const int score[][2]={{3,0},{1,1},{0,3}};

multiset <long long> sta;

inline long long change(int s[]) {
	long long ret=0;
	for(int i=0;i<4;++i) ret=ret*1000+s[i];
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	for(int i=0;i<(1<<12);++i) {
		int t=i;
		int sum[4]={};

		for(int j=0;j<6;++j,t>>=2)
			if((t&3)==3) goto next1;
			else {
				sum[game[j][0]]+=score[t&3][0];
				sum[game[j][1]]+=score[t&3][1];
			}

		sta.insert(change(sum));
next1:
		;
	}

	int T,cas=1;

	scanf("%d",&T);
	while(T--) {
		int sum[4],t;
		for(int i=0;i<4;++i) scanf("%d",sum+i);

		t=sta.count(change(sum));

		printf("Case #%d: ",cas++);
		if(t==1) puts("Yes");
		else if(t==0) puts("Wrong Scoreboard");
		else puts("No");
	}

	return 0;
}
