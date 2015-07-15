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
// Created Time  : 2015年07月03日 星期五 21时06分38秒
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

long long ans[100005];
int N,Q;
long long num[100005];
long long rem[100005];

void jiejue(int N,int flag)
{
	if(flag)
		reverse(rem+1,rem+N+1);

	for(long long i=1;i<=N;++i)
		ans[rem[i]]+=i;
}

void chuli()
{
	int cou=1;
	int flag=num[2]<num[1];

	rem[1]=num[1];

	for(int i=2;i<=N;++i)
	{
		if(num[i]>=num[i-1] && flag==0)
			rem[++cou]=num[i];
		else if(num[i]<num[i-1] && flag)
			rem[++cou]=num[i];
		else if(num[i]<num[i-1] && flag==0)
		{
			jiejue(cou,flag);
			cou=0;
			rem[++cou]=num[i];
			flag=1;
		}
		else if(num[i]>=num[i-1] && flag)
		{
			jiejue(cou,flag);
			cou=0;
			rem[++cou]=num[i];
			flag=0;
		}
	}

	jiejue(cou,flag);

	for(int i=1;i<=100000;++i)
		ans[i]+=ans[i-1];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int K;
	int flag=0;
	long long cou=1;

	scanf("%d",&N);

	for(int i=1;i<=N;++i)
		scanf("%lld",&num[i]);

	chuli();

	scanf("%d",&Q);

	while(Q--)
	{
		scanf("%d",&K);
		printf("%lld\n",(long long)N*(N+1LL)/2LL-ans[K-1]);
	}
	
	return 0;
}
