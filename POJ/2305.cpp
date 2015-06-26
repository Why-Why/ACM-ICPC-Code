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
// Created Time  : 2015年05月14日 星期四 23时12分32秒
// File Name     : 2305.cpp

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

int b;
char num1[1010];
char num2[20];
int len1,len2;

long long n1,n2;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long base;

	while(~scanf("%d",&b) && b)
	{
		scanf("%s %s",num1,num2);
		len1=strlen(num1);
		len2=strlen(num2);

		n2=0;
		for(int i=0;i<len2;++i)
			n2=n2*b+num2[i]-'0';

		base=1;
		n1=0;
		for(int i=len1-1;i>=0;--i)
		{
			n1=(n1+base*(num1[i]-'0'))%n2;
			base=(base*b)%n2;
		}

		len1=0;

		while(n1)
		{
			num1[len1++]=n1%b;
			n1/=b;
		}

		if(len1==0)
			printf("0");

		for(int i=len1-1;i>=0;--i)
			printf("%d",num1[i]);
		puts("");
	}
	
	return 0;
}
