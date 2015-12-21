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
// Created Time  : 2015年10月07日 星期三 11时50分16秒
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

const int MaxN=50004;

int N;
long long num[MaxN];

int cou1[35];
int lian1[35];
int lian0[35];

int qianj[35];
int qiano[35];

long long ans1,ans2,ans3;

void getans()
{
	long long temp;
	
	for(int i=0;i<32;++i)
		cou1[i]=lian1[i]=lian0[i]=qianj[i]=qiano[i]=0;

	for(int i=1;i<=N;++i)
	{
		for(int j=0;j<32;++j)
		{
			if(num[i] & (1LL<<j))
			{
				ans1+=(1LL<<j)*(lian1[j]+1LL);
				++lian1[j];
				ans2+=(1LL<<j)*(long long)i;

				if(cou1[j] & 1) ans3+=(1LL<<j)*(lian0[j]+1LL+qiano[j]);
				else ans3+=(1LL<<j)*(lian0[j]+1LL+qianj[j]);

				++cou1[j];

				if(cou1[j] & 1) qianj[j]+=lian0[j]+1;
				else qiano[j]+=lian0[j]+1;

				lian0[j]=0;
			}
			else
			{
				ans2+=(1LL<<j)*(i-1LL-lian0[j]);

				if(cou1[j] & 1) ans3+=(1LL<<j)*(long long)(qianj[j]);
				else ans3+=(1LL<<j)*(long long)(qiano[j]);

				++lian0[j];
				lian1[j]=0;
			}
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(int i=1;i<=N;++i) scanf("%lld",num+i);
		ans1=ans2=ans3=0;

		getans();

		double S=(N*(N+1.0))/2.0;
		printf("Case #%d: %.6f %.6f %.6f\n",cas++,(double)ans1/S,(double)ans2/S,(double)ans3/S);
	}
	
	return 0;
}
