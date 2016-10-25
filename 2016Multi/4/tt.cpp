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
// Created Time  : 2016年07月28日 星期四 16时19分46秒
// File Name     : tt.cpp

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

int u[1000],v[1000];
int N,M;
int ans[1000];
bool rem[10000000];

bool judge(int s) {
	for(int i=0;i<M;++i)
		if(s&(1<<i)) {
			if(rem[s^(1<<i)]) return 0;
		}
}

void getans() {
	for(int i=0;i<(1<<M);++i)
		if(judge(i)) {
			for(int j=0;j<M;++j)
				if(i&(1<<j)) ++ans[j+1];
			rem[i]=1;
		}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	scanf("%d",&T);

	while(T--) {
		memset(rem,0,sizeof(rem));
		scanf("%d %d",&N,&M);
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=M;++i) scanf("%d",u+i,v+i);
		getans();
		printf("Case #%d:",cas++);
		for(int i=1;i<=M;++i) printf(" %d",ans[i]);
	}

	return 0;
}
