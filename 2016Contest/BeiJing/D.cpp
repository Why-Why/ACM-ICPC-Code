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
// Created Time  : 2017年03月03日 星期五 12时58分34秒
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

int a[300];

int getans(int N) {
	int last=0,ret=0;

	for(int i=2;i<=N;++i)
		if(a[i]>a[i-1]) {
			++last;
			ret=max(ret,last);
		}
		else last=0;

	return min(N/2,ret);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;
	while(~scanf("%d",&N) && N) {
		for(int i=1;i<=N;++i) scanf("%d",a+i),a[N+i]=a[i];
		int ans=getans(N+N);
		for(int i=1,j=N;i<j;++i,--j) swap(a[i],a[j]);
		for(int i=1;i<=N;++i) a[N+i]=a[i];
		ans=max(ans,getans(N+N));

		printf("%d\n",ans);
	}

	return 0;
}
