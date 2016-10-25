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
// Created Time  : 2016年07月03日 星期日 15时40分33秒
// File Name     : A.cpp

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

const int MaxN=305;

int map1[MaxN][MaxN];
long long ans=0;
int t[MaxN][MaxN];
int N;

inline long long getans(int d) {
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j) t[i][j]=map1[i][j];
	for(int k=1;k<=N;++k)
		if(k!=d)
			for(int i=1;i<=N;++i)
				if(i!=d)
					for(int j=1;j<=N;++j)
						if(j!=d) {
							if(t[i][k]==-1 || t[k][j]==-1) continue;
							if(t[i][j]==-1) t[i][j]=t[i][k]+t[k][j];
							else t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
						}
	long long ret=0;
	for(int i=1;i<=N;++i)
		if(i!=d)
			for(int j=1;j<=N;++j)
				if(j!=d)
					ret+=t[i][j];
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j) scanf("%d",&map1[i][j]);

	for(int d=1;d<=N;++d)
		ans+=getans(d);
	cout<<ans<<endl;
	
	return 0;
}
