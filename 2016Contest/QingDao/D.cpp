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
// Created Time  : 2017年02月27日 星期一 13时01分21秒
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

int N;
int num[13];
double p[13];

const int MaxT=10000;

double die[13][MaxT+1];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		for(int i=1;i<=N;++i) {
			scanf("%d %lf",num+i,p+i);

			double tp=p[i];
			for(int j=1;j<=MaxT;++j,tp*=p[i]) die[i][j]=pow(1-tp,(double)num[i]);
		}

		if(N==1) {
			puts("1.000000");
			continue;
		}

		for(int i=1;i<=N;++i) {
			double ans=0;
			double last=0;

			for(int j=1;j<=MaxT;++j) {
				double tans=1.0;

				for(int k=1;k<=N;++k)
					if(k!=i)
						tans*=die[k][j];

				ans+=(1.0-die[i][j])*(tans-last);
				last=tans;
			}

			if(i>1) putchar(' ');
			printf("%.6f",ans);
		}
		puts("");
	}

	return 0;
}
