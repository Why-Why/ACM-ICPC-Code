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
// Created Time  : 2016年10月02日 星期日 12时37分57秒
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

long long x0,Y0,z0,x1,x2,Y1,y2,z1,z2;

long long dis(long long x,long long y,long long z) {
	return (x0-x)*(x0-x)+(Y0-y)*(Y0-y)+(z0-z)*(z0-z);
}

long long dis(long long x0,long long Y0,long long x1,long long Y1) {
	return (x0-x1)*(x0-x1)+(Y0-Y1)*(Y0-Y1);
}

long long getans() {
	int cou=0;

	if(x0>=x1 && x0<=x2) ++cou;
	if(Y0>=Y1 && Y0<=y2) ++cou;
	if(z0>=z1 && z0<=z2) ++cou;

	if(cou==3) return 0;
	else if(cou==2) {
		if(x0>=x1 && x0<=x2);
		else return min((x1-x0)*(x1-x0),(x2-x0)*(x2-x0));
		if(Y0>=Y1 && Y0<=y2);
		else return min((Y1-Y0)*(Y1-Y0),(y2-Y0)*(y2-Y0));
		if(z0>=z1 && z0<=z2);
		else return min((z1-z0)*(z1-z0),(z2-z0)*(z2-z0));
	}
	else if(cou==1) {
		if(x0>=x1 && x0<=x2) return min(min(dis(Y0,z0,Y1,z1),dis(Y0,z0,Y1,z2)),min(dis(Y0,z0,y2,z1),dis(Y0,z0,y2,z2)));
		if(Y0>=Y1 && Y0<=y2) return min(min(dis(x0,z0,x1,z1),dis(x0,z0,x1,z2)),min(dis(x0,z0,x2,z1),dis(x0,z0,x2,z2)));

		if(z0>=z1 && z0<=z2) return min(min(dis(Y0,x0,Y1,x1),dis(Y0,x0,Y1,x2)),min(dis(Y0,x0,y2,x1),dis(Y0,x0,y2,x2)));
	}
	else {
		return min(min(min(dis(x1,Y1,z1),dis(x1,Y1,z2)),min(dis(x1,y2,z1),dis(x1,y2,z2))),min(min(dis(x2,Y1,z1),dis(x2,Y1,z2)),min(dis(x2,y2,z1),dis(x2,y2,z2))));
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%lld %lld %lld",&x0,&Y0,&z0);
	scanf("%lld %lld %lld",&x1,&Y1,&z1);
	scanf("%lld %lld %lld",&x2,&y2,&z2);

	printf("%lld\n",getans());

	return 0;
}
