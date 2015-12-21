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
// Created Time  : 2015年10月02日 星期五 19时01分26秒
// File Name     : 1_A.cpp

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

bool vis[2000];
int prime[2000],pcou;

void init()
{
	pcou=0;
	for(int i=2;i<2000;++i)
		if(vis[i]==0)
		{
			prime[pcou++]=i;
			for(int j=i*2;j<2000;j+=i)
				vis[j]=1;
		}
}

int rem[2000];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n;
	init();

	scanf("%d",&n);
	int cou=0;
	int t;

	if(n==1)
	{
		puts("0");
		return 0; 
	}

	for(int i=0;i<pcou;++i)
		if(prime[i]<=n)
		{
			t=prime[i];
			while(t<=n)
			{
				rem[cou++]=t;
				t*=prime[i];
			}
		}

	printf("%d\n",cou);
	printf("%d",rem[0]);
	for(int i=1;i<cou;++i)
		printf(" %d",rem[i]);
	puts("");
	
	return 0;
}
