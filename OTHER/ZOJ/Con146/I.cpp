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
// Created Time  : 2016年04月23日 星期六 15时56分03秒
// File Name     : I.cpp

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

char peo[3][4]={".O.","/|\\","(.)"};

char map1[111][111];
int H,W;

inline bool judge(int x,int y) {
	int nx,ny;

	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j) {
			nx=x+i;
			ny=y+j;
			if(nx>=1 && ny>=1 && nx<=H && ny<=W) {
				if(peo[i][j]!='.' && map1[nx][ny]==peo[i][j]) return 1;
			}
		}
	return 0;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&H,&W);
		for(int i=1;i<=H;++i) scanf("%s",map1[i]+1);

		int ans=0;
		for(int i=-1;i<=H+2;++i)
			for(int j=-1;j<=W+2;++j)
				if(judge(i,j)) ++ans;
		printf("%d\n",ans);
	}
	
	return 0;
}
