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
// Created Time  : 2016年07月14日 星期四 20时18分44秒
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

const int MaxN=1000005;

bool vis[MaxN];
int minn[MaxN];

int pc[MaxN];

int cou[MaxN];
int rem[MaxN][12];
int ci[MaxN][12];

void init() {
	int ccc,t;

	for(int i=2;i<MaxN;++i)
		if(!vis[i]) {
			for(int j=i+i;j<MaxN;j+=i) {
				vis[j]=1;
				if(minn[j]==0) minn[j]=i;
				else minn[j]=min(minn[j],i);
			}
			rem[i][cou[i]++]=i;
			ci[i][0]=1;
		}
		else {
			ccc=0;
			t=i;
			while(t%minn[i]==0) {
				++ccc;
				t/=minn[i];
			}
			rem[i][cou[i]]=minn[i];
			ci[i][cou[i]++]=ccc;

			for(int j=0;j<cou[t];++j) {
				rem[i][cou[i]]=rem[t][j];
				ci[i][cou[i]++]=ci[t][j];
			}
		}
}

int N,K,a;

bool judge() {
	for(int i=0;i<cou[K];++i)
		if(pc[rem[K][i]]<ci[K][i]) return 0;
	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	scanf("%d %d",&N,&K);
	for(int i=1;i<=N;++i) {
		scanf("%d",&a);
		if(a==1) continue;
		for(int j=0;j<cou[a];++j)
			pc[rem[a][j]]=max(pc[rem[a][j]],ci[a][j]);
	}

	if(judge()) puts("Yes");
	else puts("No");

	return 0;
}
