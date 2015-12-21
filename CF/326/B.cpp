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
// Created Time  : 2015年10月16日 星期五 00时40分23秒
// File Name     : B.cpp

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

long long n;

bool vis[2000000];
int cou;
int prime[1000000];

void init()
{
	cou=0;
	for(long long i=2;i<1500000;++i)
		if(!vis[i])
		{
			prime[cou++]=i;
			for(long long j=i*i;j<1500000;j+=i)
				vis[j]=1;
		}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	cin>>n;
	long long ans=1;

	for(int i=0;i<cou;++i)
		if(n%prime[i]==0)
		{
			ans*=prime[i];
			while(n%prime[i]==0) n/=prime[i];
		}
	ans*=n;
	
	cout<<ans<<endl;
	
	return 0;
}
