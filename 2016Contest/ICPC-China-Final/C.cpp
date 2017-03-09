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
// Created Time  : 2017年02月07日 星期二 23时39分58秒
// File Name     : C.cpp

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

int C[1003],vis[100005];
int N,flag;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;

	scanf("%d",&T);
	while(T--) {
		int ans=0;
		scanf("%d",&N);
		for(int i=1;i<=N;++i) scanf("%d",C+i);

		for(int i=1;i<=N;++i)
			for(int j=i+1;j<=N;++j) {
				int k;
				++flag;
				for(k=i;k<j && vis[C[k]]!=flag;++k)
					vis[C[k]]=flag;

				for(int p=j;k>i;--k,vis[C[k]]=0) {
					while(p<=N && vis[C[p]]!=flag) {
						vis[C[p]]=flag;
						++p;
					}

					ans=max(ans,k-i+p-j);
				}
			}

		printf("Case #%d: %d\n",cas++,ans);
	}

	return 0;
}
