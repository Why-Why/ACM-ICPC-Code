// ━━━━━━神兽出没━━━━━━
// 　　 ┏┓       ┏┓
// 　　┏┛┻━━━━━━━┛┻┓
// 　　┃           ┃
// 　　┃     ━     ┃
//     ████━████   ┃
// 　　┃           ┃
// 　　┃    ┻      ┃
// 　　┃           ┃
// 　　┗━┓       ┏━┛
// 　　  ┃       ┃
// 　　  ┃       ┃
// 　　　┃       ┗━━━┓
// 　　　┃           ┣┓
// 　　　┃           ┏┛
// 　　　┗┓┓┏━━━━━┳┓┏┛
// 　　　 ┃┫┫     ┃┫┫
// 　　　 ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年05月14日 星期四 17时30分32秒
// File Name     : 3252_1.cpp

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

int C[40][40];
int A[40];
int num[40];
int len;

void change(int x)
{
	len=0;

	while(x)
	{
		num[len++]=((x&1)!=0);
		x>>=1;
	}
}

void init()
{
	for(int i=0;i<=32;++i)
		C[i][0]=1;

	for(int i=1;i<=32;++i)
		for(int j=1;j<=i;++j)
			C[i][j]=C[i-1][j]+C[i-1][j-1];

	A[1]=1;
	A[0]=1;

	for(int i=2;i<=32;++i)
	{
		A[i]=A[i-1];

		for(int k=(i+1)/2;k<=i-1;++k)
			A[i]+=C[i-1][k];
	}
}

int getans()
{
	if(len==0)
		return 1;

	int ret=A[len-1];
	int zn=(len+1)/2;

	for(int i=len-2;i>=0;--i)
		if(num[i]==0)
			--zn;
		else
		{
			for(int k=max(zn-1,0);k<=i;++k)
				ret+=C[i][k];
		}

	if(zn<=0)
		++ret;

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	int ans1,ans2;

	init();

	while(~scanf("%d %d",&a,&b))
	{
		--a;
		change(a);
		ans1=getans();

		change(b);
		ans2=getans();

		printf("%d\n",ans2-ans1);
	}
	
	return 0;
}
