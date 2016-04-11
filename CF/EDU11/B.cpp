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
// Created Time  : 2016年04月08日 星期五 23时15分56秒
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

const int MaxN=105;

int seat[MaxN][4];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,M;
	scanf("%d %d",&N,&M);
	memset(seat,-1,sizeof(seat));

	int l=0,r=3,h=1;

	for(int i=1;i<=M;i+=2) {
		seat[h][l]=i;
		if(i+1<=M) seat[h][r]=i+1;
		++h;
		if(h>N) {
			h=1;
			l=1,r=2;
		}
	}

	const int step[4]={1,0,2,3};

	for(int i=1;i<=N;++i) {
		for(int j=0;j<4;++j)
			if(seat[i][step[j]]!=-1) printf("%d ",seat[i][step[j]]);
	}
	puts("");
	
	return 0;
}
