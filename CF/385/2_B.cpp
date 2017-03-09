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
// Created Time  : 2017年01月17日 星期二 00时04分09秒
// File Name     : 2_B.cpp

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

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,M;
	char s[555];
	int U,D,L,R;
	int cou=0,t;

	U=L=555;
	D=R=-1;

	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;++i) {
		scanf("%s",s+1);
		t=0;
		for(int j=1;j<=M;++j)
			if(s[j]=='X') {
				L=min(L,j);
				R=max(R,j);
				++t;
			}

		if(t) U=min(U,i),D=max(D,i);
		cou+=t;
	}

	if((R-L+1)*(D-U+1)==cou) puts("YES");
	else puts("NO");

	return 0;
}
