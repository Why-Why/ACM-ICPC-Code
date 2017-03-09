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
// Created Time  : 2015年10月05日 星期一 20时33分09秒
// File Name     : D.cpp

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

int k,a,b;

char s[300];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d",&k,&a,&b);
	scanf("%s",s);

	int len=strlen(s);

	if(k*a>len || k*b<len)
	{
		puts("No solution");
		return 0;
	}

	int t=len/k,r=len%k;
	char temp;
	int cou=0,tl;

	for(int i=1;i<=k;++i)
	{
		if(i<=r) tl=t+1;
		else tl=t;

		temp=s[cou+tl];
		s[cou+tl]=0;
		printf("%s\n",s+cou);
		s[cou+tl]=temp;
		cou+=tl;
	}
	
	return 0;
}
