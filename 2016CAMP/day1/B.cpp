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
// Created Time  : 2017年02月14日 星期二 21时50分14秒
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

const int MaxN=1003;

char map1[MaxN][MaxN];
int N;

long long cal1() {
	int ret;
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			if(map1[i][j])
				++ret;
	return ret;
}

long long cal2() {

}
long long cal1() {
}
long long cal1() {
}
long long cal1() {
}
long long cal1() {
}
long long cal1() {
}
long long cal1() {
}
long long cal1() {
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N)) {
		for(int i=1;i<=N;++i) scanf("%d",map1[i]+1);
		long long ans=0;

		ans+=cal1()*2;
		ans+=cal2()*12;
		ans+=cal3()*60;
		ans+=cal4()*12;
		ans+=cal5()*6;
		ans+=cal6()*72;
		ans+=cal7()*144;
		ans+=cal8()*12;
		ans+=cal9()*24;

		printf("%lld\n",ans);
	}

	return 0;
}
