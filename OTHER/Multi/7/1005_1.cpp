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
// Created Time  : 2015年08月11日 星期二 12时33分06秒
// File Name     : 1005_1.cpp

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

const int MaxN=100005;

long long sum=0;
int n,t;

int rem[MaxN];
int chang[MaxN];

long long getsum(long long num,int id)
{
	int cou=0;
	long long ret=0;

	while(num)
	{
		ret+=num%10;
		num/=10;
		++cou;
	}

	chang[id]=cou;

	return ret;
}

bool judge()
{
	long long sum=0;
	int ret=0;

	for(int i=t;i>=0;--i)
	{
//		cout<<sum<<endl;
		if(sum%2)
			ret-=rem[i];
		else
			ret+=rem[i];
		sum+=chang[i];
		ret%=11;
	}

	return ret%11==0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cas=1;
	long long temp;

	while(~scanf("%d %d",&n,&t) && n!=-1 && t!=-1)
	{
		sum=getsum(n,0);
		rem[0]=n%11;

		for(int i=1;i<=t;++i)
		{
			rem[i]=sum%11;
			temp=getsum(sum,i);
			sum+=temp;
		}

		printf("Case #%d: ",cas++);
		if(judge())
			puts("Yes");
		else
			puts("No");
	}
	
	return 0;
}
