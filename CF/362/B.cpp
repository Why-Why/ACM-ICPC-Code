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
// Created Time  : 2016年07月15日 星期五 16时27分51秒
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

const int MaxN=1000;

char s[MaxN];
char s1[MaxN],s2[MaxN],s3[MaxN];

bool judge(char s[]) {
	for(int i=0;s[i];++i)
		if(s[i]!='0') return 1;
	return 0;
}

void show1(char s[]) {
	bool ok=0;
	for(int i=0;s[i];++i) {
		if(s[i]!='0') ok=1;
		if(ok) putchar(s[i]);
	}
}

void show2(char s[]) {
	int t=strlen(s);
	for(int i=0;s[i];++i)
		if(s[i]!='0') t=i;
	for(int i=0;i<=t;++i) putchar(s[i]);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	for(int i=0;i<MaxN;++i) s2[i]='0';

	scanf("%s",s);
	int i;
	for(i=0;s[i]!='.';++i) s1[i]=s[i];
	++i;
	for(int j=0;s[i]!='e';++i,++j) s2[j]=s[i];
	++i;
	for(int j=0;s[i];++i,++j) s3[j]=s[i];

	int t;
	sscanf(s3,"%d",&t);

	for(int i=strlen(s1),j=0;j<t;++j,++i) s1[i]=s2[j];
	for(int i=0,j=t;j<MaxN;++i,++j) s2[i]=s2[j];

	if(judge(s1)) show1(s1);
	else putchar('0');
	if(judge(s2)) {
		putchar('.');
		show2(s2);
	}
	puts("");

	return 0;
}
