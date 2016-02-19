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
// Created Time  : 2015年12月30日 星期三 23时17分17秒
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

long long A,B;

int len;
int num[1000];

void chuli(long long x) {
	len=0;
	while(x) {
		if(x&1) num[len]=1;
		else num[len]=0;
		++len;
		x>>=1;
	}
}

long long aaa[1000];

void init() {
	aaa[1]=1;
	for(int i=2;i<=100;++i) aaa[i]=i-1;
	for(int i=2;i<=100;++i) aaa[i]+=aaa[i-1];
}

bool judge(int x) {
	for(int i=x;i>=0;--i) if(num[i]==0) return 0;
	return 1;
}

long long getans(long long x) {
	if(x==0) return 1;
	if(x==1) return 1;
	chuli(x);

	long long ret=aaa[len-1];

	for(int i=len-2;i>=0;--i) {
		if(num[i]==1) {
			++ret;
		}
		else {
			if(judge(i-1)) ++ret;
			break;
		}
	}
	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	cin>>A>>B;
	cout<<getans(B)-getans(A-1)<<endl;
	
	return 0;
}
