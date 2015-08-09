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
// Created Time  : 2015年07月18日 星期六 16时18分30秒
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

int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int rui(int m,int y)
{
	if(m!=2)
		return 0;

	if(y%4==0 && y%100!=0)
		return 1;

	if(y%400==0)
		return 1;

	return 0;
}

bool add(int &y,int &m,int &d)
{
	if(y>=3000)
		return 0;

	++d;

	if(month[m]+rui(m,y)<d)
	{
		++m;
		d=1;
	}

	if(m>12)
	{
		++y;
		m=1;
	}

	return 1;
}

int bi[]={6,2,5,5,4,5,6,3,7,6};

int tongji(int y,int m,int d)
{
	int ret=0;
	
	for(int i=0;i<4;++i)
	{
		ret+=bi[y%10];
		y/=10;
	}

	for(int i=0;i<2;++i)
	{
		ret+=bi[m%10];
		ret+=bi[d%10];
		m/=10;
		d/=10;
	}
	
	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cou=0;
	int y=0,m=1,d=1;
	char s[100];
	int t;
	int ans;

	scanf("%d",&t);

	while(t--)
	{
		scanf("%s",s);
		scanf("%d",&cou);

		y=m=d=0;

		for(int i=0;i<4;++i)
			y=y*10+s[i]-'0';

		for(int i=4;i<6;++i)
			m=m*10+s[i]-'0';

		for(int i=6;i<8;++i)
			d=d*10+s[i]-'0';

		ans=0;

		while(1)
		{
			if(tongji(y,m,d)==cou)
				break;

			if(add(y,m,d)==0)
				break;

			++ans;
		}

		if(y>=3000)
			ans=-1;

		printf("%d\n",ans);
	}

	return 0;
}
