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
// Created Time  : 2015年10月12日 星期一 18时56分45秒
// File Name     : E.cpp

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

long long x,y;

char tA,tB;
long long ans[100000];
int cou;

long long gcd(long long x,long long y)
{
	if(!y) return x;
	ans[cou++]=x/y;
	return gcd(y,x%y);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>x>>y;
	cou=0;

	tA='A';
	tB='B';

	if(x<y)
	{
		swap(x,y);
		swap(tA,tB);
	}

	if(gcd(x,y)!=1)
		puts("Impossible");
	else
	{
		for(int i=0;i<cou-1;++i,swap(tA,tB))
			cout<<ans[i]<<tA;
		cout<<ans[cou-1]-1<<tA<<endl;
	}
	
	return 0;
}
