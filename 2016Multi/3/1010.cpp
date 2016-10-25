// ━━━━━━神兽出没━━━━━━
//      ┏┓       ┏┓
//     ┏┛┻━━━━━━━┛┻┓
//     ┃           ┃
//     ┃     ━     ┃
//     %�%�%�%埄�%�%�%�%�   ┃
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
// Created Time  : 2016年07月26日 星期二 15时11分59秒
// File Name     : 1010.cpp

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

const double eps=1e-5;

inline int sgn(double x) {
    return x<-eps ? -1 : x>eps;
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int a,v1,v2;

    while(~scanf("%d %d %d",&a,&v1,&v2)) {
		if(a==0) {
			puts("0");
			continue;
		}
        if(v1<=v2) {
            puts("Infinity");
            continue;
        }

        printf("%.10f\n",(a+0.0)*(v1+0.0)/(v1*(double)v1-v2*(double)v2));
    }

    return 0;
}
