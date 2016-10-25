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
// Created Time  : 2016年09月18日 星期日 14时15分43秒
// File Name     : 1007_1.cpp

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

bool judge(int x) {
	int num[20],dep=0;
	int tx=x;

	while(x) {
		num[dep++]=(x%10)%2;
		x/=10;
	}

	int cou=1;
	num[dep]=100;
	for(int i=1;i<=dep;++i) {
		if(num[i]!=num[i-1]) {
			if(num[i-1]==cou%2) return 0;
			cou=1;
		}
		else ++cou;
	}

	return 1;
}

int getans(int x) {
	int ret=0;
	for(int i=1;i<=x;++i)
		if(judge(i)) ++ret;
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,a,b;

	scanf("%d",&T);
	while(T--) {
		cin>>a>>b;
		cout<<getans(b)<<endl;
	}
	return 0;
}
