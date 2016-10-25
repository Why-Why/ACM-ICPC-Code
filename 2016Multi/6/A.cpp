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
// Created Time  : 2016年09月16日 星期五 00时01分41秒
// File Name     : A.cpp

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

long long jie(int x) {
	long long ret=1;
	for(int i=1;i<=x;++i) ret*=i;
	return ret;
}

long long C(int a,int b) {
	if(a<b) return 0;
	return jie(a)/(jie(b)*jie(a-b));
}

int num[1000];
int N,M;

long long dfs(int a) {
	if(a>M) {
		long long ret=1;
		for(int i=2;i<=M;++i)
			ret*=C(num[i],num[i-1]);
		return ret;
	}

	long long ret=0;
	for(int i=0;i<=N;++i) {
		num[a]=i;
		ret+=dfs(a+1);
	}
	return ret;
}

long long getans(int a,int b) {
	long long ret=1;
	for(int i=1;i<=a;++i)
		ret+=pow(b,i);
	return ret;

	N=a;
	M=b;
	return dfs(1);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	for(int i=0;i<=7;++i,cout<<endl)
		for(int j=2;j<=7;++j)
			cout<<getans(i,j)<<' ';

	return 0;
}
