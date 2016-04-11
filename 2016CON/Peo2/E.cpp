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
// Created Time  : 2016年02月27日 星期六 13时17分37秒
// File Name     : E.cpp

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

int N,M;
int have[MaxN];
int rem[MaxN],cou;
int lleft[MaxN],rright[MaxN],wei[MaxN];
int cou0;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,a;
	scanf("%d",&T);
	while(T--) {
		cou=cou0=0;
		memset(have,0,sizeof(have));
		scanf("%d %d",&N,&M);
		while(N--) {
			scanf("%d",&a);
			if(a==0) ++cou0;
			else ++have[a];
		}

		wei[0]=0;
		for(int i=1;i<=M;++i)
			if(have[i]==0) {
				++cou;
				wei[cou]=i;
				lleft[cou]=wei[cou-1]+1;
			}

		int tcou=cou;
		wei[tcou+1]=M+1;
		++tcou;
		for(int i=M;i>=1;--i)
			if(have[i]==0) {
				--tcou;
				rright[tcou]=wei[tcou+1]-1;
			}

		if(cou<=cou0) printf("%d\n",M);
		else {
			int ans=0;
			if(cou0) {
				for(int i=1;i+cou0-1<=cou;++i)
					ans=max(ans,rright[i+cou0-1]-lleft[i]+1);
				printf("%d\n",ans);
			}
			else {
				for(int i=1;i<cou;++i)
					ans=max(ans,rright[i]-lleft[i+1]+1);
				ans=max(ans,wei[1]-1);
				ans=max(ans,N-wei[cou]);
				printf("%d\n",ans);
			}
		}
	}
	
	return 0;
}
