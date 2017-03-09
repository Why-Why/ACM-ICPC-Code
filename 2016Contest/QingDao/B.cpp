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
// Created Time  : 2017年02月26日 星期日 13时55分02秒
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

void z1(int num[]) {
	int t1=num[21],t2=num[23];
	num[21]=num[15];
	num[23]=num[16];

	num[15]=num[20];
	num[16]=num[18];

	num[20]=num[6];
	num[18]=num[5];

	num[6]=t1;
	num[5]=t2;
}

void z2(int num[]) {
	int t1=num[3],t2=num[4];

	num[3]=num[19];
	num[4]=num[20];

	num[19]=num[10];
	num[20]=num[9];

	num[10]=num[23];
	num[9]=num[24];

	num[23]=t1;
	num[24]=t2;
}

void z3(int num[]) {
	int t1=num[7],t2=num[8];

	num[7]=num[17];
	num[8]=num[19];

	num[17]=num[14];
	num[19]=num[13];

	num[14]=num[24];
	num[13]=num[22];

	num[24]=t1;
	num[22]=t2;
}

void z4(int num[]) {
	int t1=num[11],t2=num[12];

	num[11]=num[18];
	num[12]=num[17];

	num[18]=num[2];
	num[17]=num[1];

	num[2]=num[22];
	num[1]=num[21];

	num[22]=t1;
	num[21]=t2;
}

void z5(int num[]) {
	int t1=num[13],t2=num[15];

	num[13]=num[9];
	num[15]=num[11];

	num[9]=num[5];
	num[11]=num[7];

	num[5]=num[1];
	num[7]=num[3];

	num[1]=t1;
	num[3]=t2;
}

void z6(int num[]) {
	int t1=num[14],t2=num[16];

	num[14]=num[2];
	num[16]=num[4];

	num[2]=num[6];
	num[4]=num[8];

	num[6]=num[10];
	num[8]=num[12];

	num[10]=t1;
	num[12]=t2;
}

bool judge(int num[]) {
	for(int i=1;i<=24;i+=4)
		for(int j=1;j<4;++j)
			if(num[i+j]!=num[i+j-1]) return 0;
	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,num[30],tnum[30];

	scanf("%d",&T);
	while(T--) {
		for(int i=1;i<=24;++i) scanf("%d",num+i);
		bool ok=0;

		if(judge(num)) ok=1;

		memcpy(tnum,num,sizeof(num));
		z1(tnum);
		if(judge(tnum)) ok=1;
		z1(tnum);
		z1(tnum);
		if(judge(tnum)) ok=1;

		memcpy(tnum,num,sizeof(num));
		z2(tnum);
		if(judge(tnum)) ok=1;
		z2(tnum);
		z2(tnum);
		if(judge(tnum)) ok=1;

		memcpy(tnum,num,sizeof(num));
		z3(tnum);
		if(judge(tnum)) ok=1;
		z3(tnum);
		z3(tnum);
		if(judge(tnum)) ok=1;

		memcpy(tnum,num,sizeof(num));
		z4(tnum);
		if(judge(tnum)) ok=1;
		z4(tnum);
		z4(tnum);
		if(judge(tnum)) ok=1;

		memcpy(tnum,num,sizeof(num));
		z5(tnum);
		if(judge(tnum)) ok=1;
		z5(tnum);
		z5(tnum);
		if(judge(tnum)) ok=1;

		memcpy(tnum,num,sizeof(num));
		z6(tnum);
		if(judge(tnum)) ok=1;
		z6(tnum);
		z6(tnum);
		if(judge(tnum)) ok=1;

		if(ok) puts("YES");
		else puts("NO");
	}

	return 0;
}
