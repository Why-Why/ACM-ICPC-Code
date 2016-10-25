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
// Created Time  : 2016年09月17日 星期六 14时25分37秒
// File Name     : 1004.cpp

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

	long long L,R,t,r;

	while(~scanf("%I64d %I64d",&L,&R)) {
		long long ans=0;

		if(L==R) {
			if(L<=1) puts("0");
			else if(L==2) puts("1");
			else puts("2");
			continue;
		}

		if(R<=1) {
			puts("0");
			continue;
		}

		if(L<1) L=1;

		t=(L+1)/2;
		r=(L+1)%2;

		L-=t;
		R-=t;
		++ans;

		if(2*R-r<=2 && 2*t+r<=2) {
			puts("1");
			continue;
		}

		if(R<=t+1+r) {
			++ans;
			printf("%I64d\n",ans);
			continue;
		}

		++ans;
		L=0;
		R=R-t-1-r;

		//cout<<R<<' '<<t<<endl;

		//ans+=ceil((R-1.0)/2.0);
		if(R&1) ans+=(R-1)/2LL;
		else ans+=R/2LL;

		printf("%I64d\n",ans);
	}

	return 0;
}
