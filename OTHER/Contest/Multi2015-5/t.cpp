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
// Created Time  : 2016年05月06日 星期五 20时00分59秒
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

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T=10;
	cout<<T<<endl;

	srand(time(0));

	while(T--) {
		int N=rand()%10+1,M=rand()%10+1;
		cout<<N<<' '<<M<<endl;
		for(int i=1;i<=M;++i) {
			cout<<rand()%N+1<<' '<<rand()%N+1<<endl;
		}
	}
	return 0;

	cout<<1<<endl;
	int t=50000;
	cout<<t<<' '<<(t-1)*2<<endl;
	for(int i=1;i<=t-1;++i) {
		cout<<1<<' '<<i+1<<endl;
		cout<<i+1<<' '<<1<<endl;
	}
	
	return 0;
}
