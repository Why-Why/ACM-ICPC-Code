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
// Created Time  : 2017年02月13日 星期一 13时20分16秒
// File Name     : J_1.cpp

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

bool map1[103][103];
int ans;
int du[103];

inline void add(int a,int b) {
	if(map1[a][b]) return;
	++ans;
	map1[a][b]=map1[b][a]=1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,K;

	while(~scanf("%d %d",&N,&K)) {
		if(K==1) {
			puts("-1");
			continue;
		}
		for(int i=1;i<=N;++i) {
			for(int j=1;j<=N;++j)
				map1[i][j]=0;
			du[i]=0;
		}
		ans=N;

		for(int i=1;i<N;++i) map1[i][i+1]=map1[i+1][i]=1;
		map1[1][N]=map1[N][1]=1;

		K-=2;
		int t=2,tmp;

		while(K) {
			if(K==1) {
				for(int i=1;i<=((N+1)/2);++i)
					add(i,N/2+i);
				break;
			}

			for(int i=1;i<=N;++i) {
				tmp=i+t;
				while(tmp>N) tmp-=N;
				add(i,tmp);
			}
			++t;
			K-=2;
		}

		/*
		for(int i=1;i<=N;++i) {
			for(int j=1;j<=N && du[i]<K;++j)
				if(j!=i) {
					if(du[j]<K) {
						if(map1[i][j]==0) {
							++ans;
							++du[i];
							++du[j];
							map1[i][j]=map1[j][i]=1;
						}
					}
				}

			for(int j=1;j<=N && du[i]<K;++j)
				if(j!=i) {
					if(map1[i][j]==0) {
						++ans;
						++du[i];
						++du[j];
						map1[i][j]=map1[j][i]=1;
					}
				}
		}
		*/

		printf("%d\n",ans);
		for(int i=1;i<=N;++i)
			for(int j=i+1;j<=N;++j)
				if(map1[i][j])
					printf("%d %d\n",i,j);
		printf("1");
		for(int i=2;i<=N;++i)
			printf(" %d",i);
		puts("");
	}

	return 0;
}
