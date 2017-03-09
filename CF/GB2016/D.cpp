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
// Created Time  : 2017年01月06日 星期五 17时43分51秒
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

bool vis[33][321][321];
int N,t[33];

const int base=155;

void getans(int p) {
	if(p==N) {
		for(int i=0;i<t[p];++i)
			vis[p][base][base+i]=1;
		return;
	}
	if(p>N) return;

	getans(p+2);

	for(int i=0;i<t[p];++i)
		vis[p][base][base+i]=1;
	for(int i=0;i<t[p+1];++i)
		vis[p][base-1-i][base+t[p]+i]=vis[p][base+1+i][base+t[p]+i]=1;

	for(int i=0;i<321;++i)
		for(int j=0;j<321;++j)
			if(vis[p+2][i][j]) {
				vis[p][i+t[p+1]][j+t[p]+t[p+1]]=1;
				vis[p][i-t[p+1]][j+t[p]+t[p+1]]=1;

				vis[p][base+base-j-t[p+1]-1][i+t[p]+t[p+1]-1]=1;
				vis[p][j+t[p+1]+1][i+t[p]+t[p+1]-1]=1;
			}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<=N;++i) scanf("%d",t+i);
	getans(1);

	int ans=0;
	for(int i=0;i<321;++i)
		for(int j=0;j<321;++j)
			if(vis[1][i][j]) ++ans;
	printf("%d\n",ans);

	return 0;
}
