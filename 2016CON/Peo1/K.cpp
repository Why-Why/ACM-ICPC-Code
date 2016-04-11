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
// Created Time  : 2016年02月20日 星期六 15时08分31秒
// File Name     : K.cpp

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

int N,Q;
int a[MaxN];
int num[MaxN];

int sk1[MaxN],sk2[MaxN],top;
long long ans[MaxN];

long long getans(int a,int b) {
	long long ret=0;
	top=0;
	ret=ans[a]=num[a];
	sk1[top]=num[a];
	sk2[top]=a;
	++top;

	for(int i=a+1;i<=b;++i) {
		while(top>0 && sk1[top-1]<num[i]) --top;
		if(!top) ans[i]=((long long)num[i])*(i-a+1LL);
		else ans[i]=ans[sk2[top-1]]+((long long)num[i])*(i-sk2[top-1]+0LL);
		ret+=ans[i];
		sk1[top]=num[i];
		sk2[top]=i;
		++top;
	}

	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&Q);
	for(int i=1;i<=N;++i) scanf("%d",a+i);
	for(int i=1;i<N;++i) num[i]=abs(a[i+1]-a[i]);

	int x,y;
	while(Q--) {
		scanf("%d %d",&x,&y);
		printf("%I64d\n",getans(x,y-1));
	}
	
	return 0;
}
