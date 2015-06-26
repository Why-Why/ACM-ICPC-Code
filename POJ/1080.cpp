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
// Created Time  : 2015年05月13日 星期三 09时48分59秒
// File Name     : 1080.cpp

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

char s1[300];
char s2[300];
int dp[300][300];
int l1,l2;

int getnum(char a,char b)
{
	if(a==b && a!='-')
		return 5;

	if(a<b)
		swap(a,b);

	switch(b)
	{
		case '-':
		{
			switch(a)
			{
				case 'A':
					return -3;
				case 'C':
					return -4;
				case 'G':
					return -2;
				case 'T':
					return -1;
			}
		}
		case 'A':
		{
			switch(a)
			{
				case 'C':
					return -1;
				case 'G':
					return -2;
				case 'T':
					return -1;
			}
		}
		case 'C':
		{
			switch(a)
			{
				case 'G':
					return -3;
				case 'T':
					return -2;
			}
		}
		case 'G':
		{
			switch(a)
			{
				case 'T':
					return -2;
			}
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %s %d %s",&l1,s1+1,&l2,s2+1);

		dp[0][0]=0;
		
		for(int i=1;i<=l2;++i)
			dp[0][i]=dp[0][i-1]+getnum('-',s2[i]);

		for(int i=1;i<=l1;++i)
			dp[i][0]=dp[i-1][0]+getnum(s1[i],'-');

		for(int i=1;i<=l1;++i)
			for(int j=1;j<=l2;++j)
				dp[i][j]=max(max(dp[i][j-1]+getnum('-',s2[j]),dp[i-1][j]+getnum(s1[i],'-')),dp[i-1][j-1]+getnum(s1[i],s2[j]));

		printf("%d\n",dp[l1][l2]);
	}
	
	return 0;
}
