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
// Created Time  : 2016年11月16日 星期三 23时50分57秒
// File Name     : H.cpp

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

int rem[3000];
int N,num[3000];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		for(int i=1;i<=N;++i) scanf("%d",num+i);
		memset(rem,0,sizeof(rem));

		for(int i=1;i<=N;++i) {
			int t=0;
			for(int j=i;j<=N;++j) {
				t^=num[j];
				rem[t]=max(rem[t],j-i+1);
			}
		}

		int r,ans,M,a;

		scanf("%d",&M);
		while(M--) {
			r=100000000;
			scanf("%d",&a);
			if(a<0) a=0;
			for(int i=a;i<3000;++i)
				if(rem[i]) {
					if(i-a<r) r=i-a,ans=rem[i];
					else if(i-a==r) ans=max(ans,rem[i]);
					break;
				}

			for(int i=a;i>=0;--i)
				if(rem[i]) {
					if(a-i<r) r=a-i,ans=rem[i];
					else if(a-i==r) ans=max(ans,rem[i]);
					break;
				}

			printf("%d\n",ans);
		}
		puts("");
	}

	return 0;
}
