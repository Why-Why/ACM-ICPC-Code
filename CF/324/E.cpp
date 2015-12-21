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
// Created Time  : 2015年10月07日 星期三 02时16分42秒
// File Name     : E.cpp

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

const int MaxN=2010;

int N;
int num[MaxN];
int rem[MaxN];

long long ans=0;
int cou=0;
int rans1[2000006],rans2[2000006];

int wei[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a;

	scanf("%d",&N);

	for(int i=1;i<=N;++i)
		scanf("%d",num+i);
	for(int i=1;i<=N;++i)
	{
		scanf("%d",&a);
		rem[a]=i;
	}
	for(int i=1;i<=N;++i)
	{
		num[i]=rem[num[i]];
		wei[num[i]]=i;
	}

	int minn,rrr;
	int j;

	for(int i=N;i>=1;--i)
	{
		while(wei[i]!=i)
		{
			minn=MaxN;
			for(j=wei[i]+1;j<=i;++j)
				if(minn>num[j])
				{
					minn=num[j];
					rrr=j;
				}
			j=rrr;

			rans1[cou]=wei[i],rans2[cou]=j;
			++cou;
			ans+=j-wei[i];
			int temp=wei[i];
			wei[i]=j;
			wei[num[j]]=temp;
			num[temp]=num[j];
			num[j]=i;
		}
	}

	printf("%lld\n",ans);
	printf("%d\n",cou);
	for(int i=0;i<cou;++i)
		printf("%d %d\n",rans1[i],rans2[i]);
	
	return 0;
}
