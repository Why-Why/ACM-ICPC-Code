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
// Created Time  : 2017年03月06日 星期一 11时14分02秒
// File Name     : tt.cpp

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

int maxn=0;

void show(int tnum[],int cou) {
	/*
	for(int i=0;i<cou;++i) cout<<tnum[i]<<' ';
	cout<<endl;
	return;
	*/

	int num[1000000];
	memcpy(num,tnum,sizeof(num));

	int minn=1000000000;
	for(int i=0;i<cou;++i)
		if(num[i]==0) return;
		else minn=min(minn,abs(num[i]));

	maxn=max(maxn,minn);
	//cout<<minn<<" ";
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int num1[1000000],num2[1000],num3[1000];
	int cou1=0,cou2=0,cou3=0;
	map <int,int> sta;
	
	num2[cou2++]=0;

	for(int i=1;i<=2500;++i) {
		show(num2,cou2);

		sta.clear();
		for(int j=0;j<cou1;++j) ++sta[num1[j]];
		for(int j=0;j<cou2;++j) {
			++sta[num2[j]];
			++sta[num2[j]-1];
			++sta[num2[j]+1];
		}

		cou3=0;
		for(auto x:sta)
			if(x.second&1) num3[cou3++]=x.first;

		cou1=cou2;
		for(int j=0;j<cou2;++j) num1[j]=num2[j];
		cou2=cou3;
		for(int j=0;j<cou2;++j) num2[j]=num3[j];
	}

	cout<<maxn<<endl;

	return 0;
}
