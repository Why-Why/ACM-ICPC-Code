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
// Created Time  : 2015年08月13日 星期四 13时19分09秒
// File Name     : 1010.cpp

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

const int mod=258280327;

int N,A,B;
long long ans[15];

int gen(int x)
{
	int sum=0;
	int t;

	while(x>=10)
	{
		t=x;
		sum=0;
		while(t)
		{
			sum+=t%10;
			t/=10;
		}
		x=sum;
	}

	return x;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T,a;
	int sum;
	long long aaa;

	scanf("%d",&T);

	long long tans[15];
	int temp;

	while(T--)
	{
		scanf("%d %d %d",&N,&A,&B);
		sum=0;
		memset(ans,0,sizeof(ans));
		ans[0]=1;

		for(int i=1;i<=N;++i)
		{
			scanf("%d",&a);
			sum+=a;
			for(int j=0;j<=9;++j)
				tans[j]=ans[j];
			for(int j=0;j<=9;++j)
				(ans[gen(j+a)]+=tans[j])%=mod;
		}

		if(gen(A+B)!=gen(sum))
		{
			temp=gen(sum);
			a=0;
			if(gen(A)==temp) ++a;
			if(gen(B)==temp) ++a;
			printf("%d\n",a);
		}
		else
		{
			aaa=ans[A];
			temp=gen(sum);
			if(temp==gen(B)) ++aaa;
			aaa+=mod;
			aaa%=mod;
			printf("%I64d\n",aaa);
		}
	}

	return 0;
}
