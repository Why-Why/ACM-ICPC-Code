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
// Created Time  : 2015年05月14日 星期四 18时06分35秒
// File Name     : 1850.cpp

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

long long A[20][30];
char s[20];
int len;

void init()
{
	long long t;

	for(int i=1;i<=26;++i)
		A[1][i]=i;

	for(int i=2;i<=10;++i)
	{
		A[i][0]=0;
		A[i][1]=A[i-1][28-i]+1;

		for(int j=2;j+i-1<=26;++j)
		{
			A[i][j]=A[i][j-1];
			A[i][j]+=A[i][1]-A[i-1][j];
		}
	}
}

long long getans()
{
	for(int i=2;i<=len;++i)
		if(s[i]<=s[i-1])
			return 0;

	long long ret=0;

	s[0]='a'-2;

	for(int i=1;i<=len;++i)
		ret+=A[len-i+1][s[i]-'a'+1]-A[len-i+1][s[i-1]-'a'+2];

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	while(~scanf("%s",s+1))
	{
		len=strlen(s+1);

		printf("%lld\n",getans());
	}
	
	return 0;
}
