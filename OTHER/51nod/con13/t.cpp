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
// Created Time  : 2016年04月30日 星期六 12时49分25秒
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

const int MaxN=1000000;

int B[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	B[0]=-1;
	for(int i=1;i<MaxN;++i)
		if(i&1) B[i]=2*B[i/2]+(i+1)/2;
		else B[i]=2*B[i/2]+1;

	int last=-1;

	for(int i=1;i<MaxN;i+=2) {
		if(B[i]<B[i+1]) cout<<"NO\n";
		if(B[i]==B[i+1]) {
			if(last==0) cout<<"NO\n";
			last=0;
		}
		else {
			if(last==1) cout<<"NO\n";
			last=1;
		}
	}

	return 0;
}
