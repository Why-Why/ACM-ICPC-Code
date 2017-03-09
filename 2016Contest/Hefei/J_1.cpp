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
// Created Time  : 2016年11月18日 星期五 23时44分46秒
// File Name     : J_1.cpp

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

inline long long f(long long x,long long y) {
	int c=0;
	long long t;

	while(y>0) {
		++c;
		t=x%y;
		x=y;
		y=t;
	}

	return c*x*x;
}

long long F(long long x,long long y) {
	return x*y/f(x,y);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,M;
	long long ans=0;

	while(cin>>N>>M) {
		ans=0;
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
				ans+=F(i,j);
		cout<<ans<<endl;
	}

	return 0;
}
