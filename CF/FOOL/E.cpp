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
// Created Time  : 2016年04月02日 星期六 01时08分45秒
// File Name     : E.cpp

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

const int MaxN=13;

class TTT{};

int map1[MaxN][MaxN];
int N;

void DA(int a,int b) {
	a>b ? throw(TTT()) : 1;
}

void solve() {
	int i,j,k;
	i=j=k=0;

KKK:
	++k;
	try { DA(k,N); }
	catch(TTT) { goto DDD; }

AAA:
	++i;
	try {
		DA(i,N);
	}catch(TTT) {
		i=0;
		goto KKK;
	}
BBB:
	++j;
	try {
		DA(j,N);
	}catch(TTT) {
		j=0;
		goto AAA;
	}
	map1[i][j]=min(map1[i][j],map1[i][k]+map1[k][j]);
	goto BBB;
	goto AAA;
DDD:
	;
}

int getans() {
	int i,j,ret=-1;

	i=j=0;
AAA:
	++i;
	try {
		DA(i,N);
	}catch(TTT) {
		goto CCC;
	}
BBB:
	++j;
	try {
		DA(j,N);
	}catch(TTT) {
		j=0;
		goto AAA;
	}
	ret=max(ret,map1[i][j]);
	goto BBB;
	goto AAA;
CCC:
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>N;
	int i,j;

	i=j=0;
AAA:
	++i;
	try {
		DA(i,N);
	}catch(TTT) {
		goto CCC;
	}
BBB:
	++j;
	try {
		DA(j,N);
	}catch(TTT) {
		j=0;
		goto AAA;
	}
	cin>>map1[i][j];
	goto BBB;
	goto AAA;
CCC:

	solve();
	cout<<getans()<<endl;
	
	return 0;
}
