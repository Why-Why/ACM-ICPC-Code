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
// Created Time  : 2015年09月25日 星期五 19时00分43秒
// File Name     : H.cpp

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

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T,cas=1;
	int ang,h;
	char s[20];
	bool type;
	int qian,hou;
	
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %s %d",&ang,s,&h);
		qian=360-30*h;
		if(s[0]=='a') type=1;
		else type=0;

		hou=ang;
		if(type && qian>=ang) hou+=360;
		if(!type && qian<=ang) hou-=360;

		double x=(hou-qian)*120.0/11.0;
		int dang=h*3600;
		x=dang+x;
		if(x<0) x+=12*3600;
		else if(x>=12*3600) x-=12*3600;

		int th=x/3600;
		int tm=(x-th*3600)/60;
		double ts=x-th*3600-tm*60;
		if(th==0) th=12;

		printf("Case %d: %d:%02d:%02d\n",cas++,th,tm,(int)round(ts));
	}

	return 0;
}
