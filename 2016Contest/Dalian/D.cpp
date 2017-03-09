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
// Created Time  : 2016年11月11日 星期五 17时38分21秒
// File Name     : D.cpp

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

int gcd(int a,int b) {
	if(!a) return b;
	return gcd(b%a,a);
}

inline int lcm(int a,int b) {
	return a*b/gcd(a,b);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	int x,y,t;
	bool ok;

	a=100;

	while(~scanf("%d %d",&a,&b)) {
		if(a==b) {
			printf("0 %d\n",a);
			continue;
		}

		ok=0;
		for(x=1;x<a;++x) {
			y=a-x;
			if(lcm(x,y)==b) {
				ok=1;
				break;
			}
		}

		if(ok) printf("%d %d\n",x,y);
		else puts("No Solution");
	}

	return 0;
}
