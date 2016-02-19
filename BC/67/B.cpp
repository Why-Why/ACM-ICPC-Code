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
// Created Time  : 2015年12月26日 星期六 19时43分14秒
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

double ans[33][33];
bool vis[33][33];

double tans[33][33];
bool tvis[33][33];

const int pai[]={0,1,2,3,4,5,6,7,8,9,10,10,10,10};

double getnum(int a,int b) {
	if(tvis[a][b]) return tans[a][b];
	tvis[a][b]=1;
	if(b>21) {
		tans[a][b]=0;
		return 0;
	}
	if(a<=b) {
		tans[a][b]=1;
		return 1;
	}

	double s=0;
	for(int i=1;i<=13;++i)
		s+=getnum(a,b+pai[i])/13.0;
	tans[a][b]=s;
	return s;
}

double getans(int a,int b) {
	if(vis[a][b]) return ans[a][b];
	vis[a][b]=1;
	if(a>21) {
		ans[a][b]=0;
		return 0;
	}
	double s1,s2=0;
	s1=1-getnum(a,b);
	for(int i=1;i<=13;++i) s2+=getans(a+pai[i],b)/13.0;
	ans[a][b]=max(s1,s2);
	return ans[a][b];
}

inline int zhuan(char c) {
	if(c>='1' && c<='9') return c-'0';
	if(c=='A') return 1;
	return 10;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b;
	double aaa;
	char s[10];

	scanf("%d",&T);
	while(T--) {
		scanf("%s",s);
		a=zhuan(s[0])+zhuan(s[1]);
		b=zhuan(s[2])+zhuan(s[3]);
		aaa=getans(a,b);
		if(aaa>0.5) puts("YES");
		else puts("NO");
	}
	
	return 0;
}
