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
// Created Time  : 2016年03月21日 星期一 22时22分17秒
// File Name     : I_1.cpp

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

int ans[40000];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ans[1]=ans[2]=0;
	int cou=0,add=1;
	for(int i=3;i<=32767;++i) {
		ans[i]=ans[i-1]+add;
		++cou;
		if(cou>=2) {
			cou=0;
			++add;
		}
	}

	int T,N;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		printf("%d\n",ans[N]);
	}
	
	return 0;
}
