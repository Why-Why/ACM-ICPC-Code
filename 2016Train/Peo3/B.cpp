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
// Created Time  : 2016年03月05日 星期六 12时44分55秒
// File Name     : B.cpp

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

int N;
int num[MaxN];
int cou[40];

long long getans(int u) {
	int cc=0;
	long long ret=0;

	while(u) {
		if((u&1)==0) ret+=cou[cc];
		++cc;
		u>>=1;
	}

	++cou[cc-1];
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		for(int i=1;i<=N;++i) scanf("%d",num+i);
		sort(num+1,num+N+1);
		memset(cou,0,sizeof(cou));

		long long ans=0;
		for(int i=1;i<=N;++i)
			ans+=getans(num[i]);
		cout<<ans<<endl;
	}
	
	return 0;
}
