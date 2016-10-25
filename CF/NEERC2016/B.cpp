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
// Created Time  : 2016年10月24日 星期一 23时34分01秒
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

int num1[55],num2[55];
int cou1,cou2;
int minn,maxn;

inline int query(int a,int b) {
	printf("? %d %d\n",a,b);
	fflush(stdout);

	char s[5];
	scanf("%s",s);

	if(s[0]=='>') return 1;
	if(s[0]=='=') return 0;
	return -1;
}

void getmax(int num[],int len) {
	if(len==1) {
		maxn=num[1];
		return;
	}

	int temp[55],tcou=0;

	for(int i=1;i+1<=len;i+=2)
		if(query(num[i],num[i+1])>=0) temp[++tcou]=num[i];
		else temp[++tcou]=num[i+1];

	if(len&1) temp[++tcou]=num[len];

	getmax(temp,tcou);
}

void getmin(int num[],int len) {
	if(len==1) {
		minn=num[1];
		return;
	}

	int temp[55],tcou=0;

	for(int i=1;i+1<=len;i+=2)
		if(query(num[i],num[i+1])<=0) temp[++tcou]=num[i];
		else temp[++tcou]=num[i+1];

	if(len&1) temp[++tcou]=num[len];

	getmin(temp,tcou);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int N;

	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);

		cou1=cou2=0;
		for(int i=1;i+1<=N;i+=2) {
			if(query(i,i+1)>=0) num1[++cou1]=i,num2[++cou2]=i+1;
			else num1[++cou1]=i+1,num2[++cou2]=i;
		}

		if(N&1) num1[++cou1]=N,num2[++cou2]=N;

		getmax(num1,cou1);
		getmin(num2,cou2);

		printf("! %d %d\n",minn,maxn);
		fflush(stdout);
	}

	return 0;
}
