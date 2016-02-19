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
// Created Time  : 2016年01月23日 星期六 19时02分05秒
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

long long a,b,ans;
char s[100];

bool judge1(int t) {
	for(int i=7;i<=10;++i)
		if(s[i]-s[i-1]!=t) return 0;
	return 1;
}

const int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int year(int y,int m) {
	if(m!=2) return 0;
	if(y%400==0) return 1;
	if(y%4==0 && y%100) return 1;
	return 0;
}

bool judge(char s[]) {
	if(judge1(0) || judge1(1) || judge1(-1)) return 1;
	int y=(s[3]-'0')*1000+(s[4]-'0')*100+(s[5]-'0')*10+s[6]-'0';
	int m=(s[7]-'0')*10+s[8]-'0';
	int d=(s[9]-'0')*10+s[10]-'0';

	if(y<1980 || y>2016) return 0;
	if(m<1 || m>12) return 0;
	if(d<1 || month[m]+year(y,m)<d) return 0;
	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int N;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		scanf("%I64d %I64d",&a,&b);
		ans=0;
		while(N--) {
			scanf("%s",s);
			if(judge(s)) ans+=a;
			else ans+=b;
		}
		printf("%I64d\n",ans);
	}
	
	return 0;
}
