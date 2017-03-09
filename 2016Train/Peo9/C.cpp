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
// Created Time  : 2016年05月29日 星期日 13时25分41秒
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

const int MaxN=100005;

int N,P,mid;
char s[MaxN];

long long getans() {
	long long ret=0;
	long long cou1=0,cou2=0;

	for(int i=mid;i>P;--i,++cou1)
		if(s[i]!=s[N+1-i]) break;
	cou1=mid-P-cou1;

	for(int i=1;i<P;++i,++cou2)
		if(s[i]!=s[N+1-i]) break;
	cou2=P-1-cou2;

	for(int i=1;i<=mid;++i)
		ret+=min(26-abs(s[i]-s[N+1-i]),abs(s[i]-s[N+1-i]));

	return cou1+cou2+min(cou1,cou2)+ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&N,&P);
		scanf("%s",s+1);
		mid=(N+1)>>1;
		if(P>mid) {
			P=N+1-P;
			reverse(s+1,s+N+1);
		}

		printf("%I64d\n",getans());
	}
	
	return 0;
}
