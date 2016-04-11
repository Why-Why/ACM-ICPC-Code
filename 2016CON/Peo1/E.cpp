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
// Created Time  : 2016年02月20日 星期六 16时30分36秒
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

const int MaxN=100005;

int K;

int judge(int a) {
	if(a==0) return 0;
	if(a==1) return 1;
	if(a>=5 && a&1) return 0;

	int t=judge(a-1);

	if(a==3) {
		if(t) return 0;
		return 1;
	}

	int tt;
	if(!K) tt=0;
	else tt=judge(a>>1);
	
	if(tt && t) return 0;
	if(!tt && !t) return 1;
	if((tt+t)==1) return 2;
	return 1;
}

void show(int x) {
	for(int i=7;i>=0;--i) if(x&(1<<i)) putchar('1');
	else putchar('0');
	putchar(' ');
}

/*
int main() {
	for(int i=1;i<=100000;i+=2) {
		if(judge(i)) cout<<i<<' '<<judge(i)<<endl;
	}
}
*/

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,a;
	int sum=0;

	scanf("%d %d",&N,&K);
	K%=2;
	for(int i=1;i<=N;++i) {
		scanf("%d",&a);
		sum^=judge(a);
	}

	if(sum) puts("Kevin");
	else puts("Nicky");
	
	return 0;
}
