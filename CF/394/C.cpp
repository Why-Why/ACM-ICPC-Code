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
// Created Time  : 2017年02月03日 星期五 19时29分09秒
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

int n,m;
char map1[55][55];
int jin[55][3];

inline int bian(char c) {
	if(c=='#' || c=='*' || c=='&') return 0;
	if(c>='0' && c<='9') return 1;
	return 2;
}

inline int dis(int b) {
	return min(b-1,m+1-b);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int ans=0x3f3f3f3f;
	memset(jin,0x3f,sizeof(jin));

	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) {
		scanf("%s",map1[i]+1);
		for(int j=1;j<=m;++j)
			jin[i][bian(map1[i][j])]=min(jin[i][bian(map1[i][j])],dis(j));
	}

	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				if(i!=j && i!=k && j!=k)
					ans=min((long long)ans,0LL+jin[i][0]+0LL+jin[j][1]+0LL+jin[k][2]);

	printf("%d\n",ans);

	return 0;
}
