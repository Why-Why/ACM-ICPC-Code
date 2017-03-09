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
// Created Time  : 2015年11月29日 星期日 11时55分28秒
// File Name     : J.cpp

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

int num[10000];

int cal(int x) {
	int ret=1;
	for(int i=1;i<=x;++i) (ret*=x)%=7;
	return ret;
}

const char ans[10][20]={"Saturday","Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	num[0]=0;
	for(int i=1;i<=7*42;++i)
		num[i]=(num[i-1]+cal(i))%7;

	int ttt=7*42;
	int T,N;

	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		printf("%s\n",ans[num[(N-1)%ttt+1]]);
	}
	
	return 0;
}
