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
// Created Time  : 2016年02月27日 星期六 12时41分04秒
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

int dist2(int x1,int y1,int x2,int y2) {
	int dx=x1-x2;
	int dy=y1-y2;
	return dx*dx+dy*dy;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,x1,x2,y1,y2,r1,r2;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
		int d=dist2(x1,y1,x2,y2);
		int dd=r1*r1+r2*r2+2*r1*r2;
		if(x1==x2 && y1==y2) {
			if(r1==r2) puts("-1");
			else puts("0");
		}
		else {
			if(d>dd) puts("4");
			else if(d==dd) puts("3");
			else {
				int ld=r1*r1+r2*r2-2*r1*r2;
				if(ld==d) puts("1");
				else if(ld>d) puts("0");
				else puts("2");
			}
		}
	}
	
	return 0;
}
