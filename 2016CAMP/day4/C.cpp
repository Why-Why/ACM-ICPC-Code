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
// Created Time  : 2017年02月16日 星期四 12时08分36秒
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

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,N;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		if(N==1) printf("1 1 1 2\n");
		else if(N==2) printf("1 1 1 2\n1 3 1 4\n1 5 1 6\n");
		else if(N==3) printf("1 1 2 1\n2 2 3 2\n2 3 3 3\n4 2 5 2\n5 3 4 3\n3 4 4 4\n");
		else if(N==4) printf("4 3 5 3\n3 3 3 4\n4 2 3 2\n5 2 6 2\n4 4 5 4\n2 4 2 3\n6 4 6 3\n1 2 2 2\n3 1 4 1\n5 1 6 1\n");
		else puts("impossible");
	}

	return 0;
}
