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
// Created Time  : 2016年07月13日 星期三 21时29分51秒
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

const int MaxN=100;

char num[MaxN];
int remx[MaxN],remy[MaxN];
const int x[]={4,1,1,1,2,2,2,3,3,3};
const int y[]={2,1,2,3,1,2,3,1,2,3};
int n;

inline bool j(int x,int y) {
	if(x==4 && y==2) return 1;
	if(x<=3 && x>=1 && y<=3 && y>=1) return 1;
	return 0;
}

inline bool judge(int bx,int by) {
	for(int i=1;i<n;++i) {
		bx+=remx[i];
		by+=remy[i];
		if(j(bx,by)==0) return 0;
	}

	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&n);
	scanf("%s",num+1);
	for(int i=1;i<n;++i) {
		remx[i]=x[num[i+1]-'0']-x[num[i]-'0'];
		remy[i]=y[num[i+1]-'0']-y[num[i]-'0'];
	}

	int cou=0;
	for(int i=1;i<=3;++i)
		for(int j=1;j<=3;++j)
			if(judge(i,j)) ++cou;
	if(judge(4,2)) ++cou;

	if(cou==1) puts("YES");
	else puts("NO");
	
	return 0;
}
