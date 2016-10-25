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
// Created Time  : 2016年05月06日 星期五 17时53分17秒
// File Name     : E.cpp

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

const int MaxN=500005;

int N,M,P;
int LL[MaxN],RR[MaxN];
char s[MaxN];
char ope[MaxN];
int rem[MaxN];

int s1[MaxN],top;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d",&N,&M,&P);
	scanf("%s",s+1);
	scanf("%s",ope+1);

	top=0;
	RR[0]=1;
	LL[N+1]=N;
	for(int i=1;i<=N;++i) {
		LL[i]=i-1;
		RR[i]=i+1;
		if(s[i]=='(') s1[top++]=i;
		else {
			--top;
			rem[s1[top]]=i;
			rem[i]=s1[top];
		}
	}

	int a,b;

	for(int i=1;i<=M;++i) {
		if(ope[i]=='R') {
			if(RR[P]<=N) P=RR[P];
		}
		else if(ope[i]=='L') {
			if(LL[P]>0) P=LL[P];
		}
		else {
			a=min(P,rem[P]);
			b=max(P,rem[P]);
			RR[LL[a]]=RR[b];
			LL[RR[b]]=LL[a];
			if(RR[b]<=N) P=RR[b];
			else P=LL[a];
		}
	}

	for(int i=RR[0];i<=N;i=RR[i]) putchar(s[i]);
	puts("");
	
	return 0;
}
