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
// Created Time  : 2015年11月29日 星期日 11时39分19秒
// File Name     : G.cpp

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

char s[1000];
int a,b,c;
char o1[100],o2[100];

int cal(int a,char b,int c) {
	if(b=='+') return a+c;
	if(b=='-') return a-c;
	if(b=='*') return a*c;
	if(b=='/') return a/c;
	if(b=='%') return a%c;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%s%d%s%d",&a,o1,&b,o2,&c);
		bool ok=1;
		int t1;
		if((o2[0]=='*' || o2[0]=='/' || o2[0]=='%') && (o1[0]=='+' || o1[0]=='-'))
			ok=0;

		if(ok) t1=cal(cal(a,o1[0],b),o2[0],c);
		else t1=cal(a,o1[0],cal(b,o2[0],c));

		printf("%d\n",t1);
	}
	
	return 0;
}
