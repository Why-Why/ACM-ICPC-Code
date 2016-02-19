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
// Created Time  : 2016年01月22日 星期五 22时36分34秒
// File Name     : B.cpp

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

char rem[MaxN];
char s[MaxN];

int judge(char s[]) {
	int i;
	if(s[0]=='0') return -2;
	if(s[0]!='1') return -1;
	for(i=1;s[i];++i)
		if(s[i]!='0') return -1;
	return i-1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;
	int cou=0,t;
	bool ok=0,tok=0;
	scanf("%d",&N);
	for(int i=1;i<=N;++i) {
		scanf("%s",s);
		if((t=judge(s))==-1) strcpy(rem,s),tok=1;
		else if(t>=0) cou+=t;
		else if(t==-2) ok=1;
	}
	if(ok) puts("0");
	else {
		if(tok) printf("%s",rem);
		else putchar('1');
		for(int i=0;i<cou;++i) putchar('0');
		puts("");
	}
	
	return 0;
}
