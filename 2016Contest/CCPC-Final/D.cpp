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
// Created Time  : 2017年02月23日 星期四 14时52分15秒
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

const int MaxN=100005;

int N,M,R;
int top[MaxN],C[MaxN];
int have[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int a,b;

	scanf("%d",&T);
	while(T--) {
		scanf("%d %d %d",&N,&M,&R);
		for(int i=1;i<=N;++i) {
			scanf("%d",C+i);
			top[i]=min(i,R);
			have[i]=0;
		}

		while(M--) {
			scanf("%d %d",&a,&b);
			top[a]=min(top[a],b);
			top[b]=min(top[b],a);
		}
		top[R]=1;

		for(int i=1;i<=N;++i) ++have[top[i]];

		long long ans=0;

		for(int i=1;i<=N;++i)
			if(C[i]<=have[i]) {
				ans-=have[i]-C[i];
				if(ans<0) ans=0;
			}
			else ans+=C[i]-have[i];

		printf("Case #%d: %I64d\n",cas++,ans);
	}

	return 0;
}
