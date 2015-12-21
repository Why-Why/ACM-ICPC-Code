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
// Created Time  : 2015年09月20日 星期日 22时00分49秒
// File Name     : 1012_1.cpp

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

const int INF=0x3f3f3f3f;
const long long LLINF=100000000000000000LL;
const int MaxN=5000006;

int num[MaxN];
int maxn,minn,pmax,pmin,amin;
int rem1,rem2,rem3,rem4,rem5;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int N;
	long long a,b;
	int t;
	long long ans;
	int rem[10],cou;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %I64d %I64d",&N,&a,&b);
		maxn=pmax=-INF;
		minn=pmin=amin=INF;

		for(int i=1;i<=N;++i)
		{
			scanf("%d",&t);
			num[i]=t;
			if(t>maxn)
			{
				pmax=maxn;
				maxn=t;
				rem3=rem1;
				rem1=i;
			}
			else if(t>pmax)
			{
				pmax=t;
				rem3=i;
			}

			if(t<minn)
			{
				pmin=minn;
				minn=t;
				rem4=rem2;
				rem2=i;
			}
			else if(t<pmin)
			{
				pmin=t;
				rem4=i;
			}

			if(abs(t)<amin)
			{
				amin=abs(t);
				rem5=i;
			}
		}

		cou=5;
		rem[0]=rem1; rem[1]=rem2; rem[2]=rem3; rem[3]=rem4; rem[4]=rem5;
		sort(rem,rem+5);
		cou=unique(rem,rem+5)-rem;

		ans=-LLINF;
		for(int i=0;i<cou;++i)
			for(int j=0;j<cou;++j)
				if(i!=j)
					ans=max(ans,a*num[rem[i]]*num[rem[i]]+b*num[rem[j]]);

		printf("Case #%d: %I64d\n",cas++,ans);
	}
	
	return 0;
}
