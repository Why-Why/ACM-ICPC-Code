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
// Created Time  : 2017年02月12日 星期日 10时05分08秒
// File Name     : t.cpp

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

int N;

bool judge(int sta) {
	for(int i=0;i<N;++i)
		if((sta&(1<<i)) && (sta&(1<<(i*2+3)))) return 0;
	return 1;
}

int cou(int x) {
	int ret=0;
	for(;x;x>>=1)
		if(x&1) ++ret;
	return ret;
}

int getans() {
	int ret=0;
	for(int i=0;i<(1<<N);++i)
		if(judge(i)) ret=max(ret,cou(i));
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	for(int i=1;i<=20;++i) {
		N=i;
		cout<<i<<" "<<getans()<<endl;
	}

	while(cin>>N) cout<<getans()<<endl;

	return 0;
}
