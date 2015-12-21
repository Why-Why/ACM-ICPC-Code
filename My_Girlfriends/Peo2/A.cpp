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
// Created Time  : 2015年09月18日 星期五 15时46分22秒
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

int a,b;

double getans1()
{
	int k=(a+b)/(2*b);

	if(k<1) return -10.0;

	return (a+b)/(2.0*k);
}

double getans2()
{
	int k=(a-b)/(2*b);

	if(k<0) return -10.0;
	
	if(a==b) return a;
	return (a-b)/(2.0*k);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>a>>b;

	double t,ans=-10;

	t=getans1();
	if(t>=-1.0) ans=t;

	t=getans2();
	if(t>=-1.0) ans=min(ans,t);

	if(ans>=-1.0)
		printf("%.12f\n",ans);
	else puts("-1");
	
	return 0;
}
