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
// Created Time  : 2016年09月04日 星期日 17时41分56秒
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

	long long n;
	cin>>n;

	if(n<=2) {
		puts("-1");
		return 0;
	}

	int cou=0;
	while(!(n&1)) n>>=1,++cou;

	if(n==1) {
		cou-=2;
		long long b=3,c=5;
		while(cou--) b<<=1,c<<=1;
		cout<<b<<' '<<c<<endl;
		return 0;
	}

	long long b=n*n/2LL,c=(n*n+1)/2LL;
	while(cou--) b<<=1,c<<=1;

	cout<<b<<' '<<c<<endl;

	return 0;
}
