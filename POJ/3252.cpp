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
// Created Time  : 2015年05月13日 星期三 23时29分44秒
// File Name     : 3252.cpp

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

int a,b;
int n1[50],n2[50],*num;
int w1,w2;
int C[40][40];
int A[40];

int dp[40][3];

void init()
{
	for(int i=0;i<=32;++i)
		C[i][0]=1;

	for(int i=1;i<=32;++i)
		for(int j=1;j<=i;++j)
			C[i][j]=C[i-1][j-1]+C[i-1][j];

	A[1]=1;

	for(int i=2;i<=32;++i)
	{
		A[i]=A[i-1];

		for(int j=(i+1)/2;j<=i-1;++j)
			A[i]+=C[i-1][j];
	}
}

int getans(int len)
{
	int ret=0;

	if(len==0)
		return 1;

	if(num[len-1])
	{
		ret+=getans(len-1);
		ret+=A[len-1];
	}
	else
		ret=getans(len-1);

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	int ans1,ans2;

	while(~scanf("%d %d",&a,&b))
	{
		--a;
		w1=w2=0;

		if(a!=-1)
			while(a)
			{
				if(a&1)
					n1[w1++]=1;
				else
					n1[w1++]=0;

				a>>=1;
			}

		while(b)
		{
			if(b&1)
				n2[w2++]=1;
			else
				n2[w2++]=0;

			b>>=1;
		}

		num=n1;
		ans1=getans(w1);

		num=n2;
		ans2=getans(w2);
cout<<ans1<<' '<<ans2<<endl;
		printf("%d\n",ans2-ans1);
	}
	
	return 0;
}
