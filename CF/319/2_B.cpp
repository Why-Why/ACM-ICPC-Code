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
// Created Time  : 2015年10月02日 星期五 19时33分24秒
// File Name     : 2_B.cpp

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

const int MaxN=1000006;

int N,M;

bool DP1[1003],DP2[1003];
bool *dp1,*dp2;
int num[1003];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a;

	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;++i)
	{
		scanf("%d",&a);
		++num[a%M];
	}

	if(num[0])
	{
		puts("YES");
		return 0;
	}

	dp1=DP1;
	dp2=DP2;

	for(int i=1;i<M;++i)
	{
		int k=1,w;
		while(num[i]>0)
		{
			memset(dp2,0,sizeof(dp2));
			w=(i*min(k,num[i]))%M;

			dp2[w]=1;
			for(int j=1;j<M;++j)
				if(dp1[j])
				{
					dp2[j]=1;
					dp2[(j+w)%M]=1;
				}

			if(dp2[0])
			{
				puts("YES");
				return 0;
			}

			num[i]-=k;
			k<<=1;
			swap(dp1,dp2);
		}
	}

	puts("NO");
	
	return 0;
}
