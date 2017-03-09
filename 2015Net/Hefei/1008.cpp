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
// Created Time  : 2015年09月27日 星期日 13时39分52秒
// File Name     : 1008.cpp

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

int s1,s2;
long long D;

int count1(long long x,int &len,int &first)
{
	int ret=0;
	int cou=0;
	first=-1;
	len=-1;
	for(int i=0;i<33;++i)
	{
		if(x&1)
		{
			if(first==-1) first=cou;
			++ret;
		}
		else
		{
			if(first!=-1 && len==-1)
				len=cou-first;
		}
		x>>=1;
		++cou;
	}
	len=ret-len+1;
	return ret;
}

long long getans()
{
	int len;
	int first;
	int cou=count1(D,len,first);

	if(cou<s2)
	{
		if((D&1)==0) return D+1;
		return (D+1)+(1<<max(0,s1-len))-1;
	}

	return (D+(1<<first))+(1<<max(0,s1-len))-1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%I64d %d %d",&D,&s1,&s2);
		s1=max(s1,0);
		s2=min(s2,33);
		printf("Case #%d: %I64d\n",cas++,getans());
	}
	
	return 0;
}
