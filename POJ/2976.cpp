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
// Created Time  : 2015年08月08日 星期六 13时51分01秒
// File Name     : 2976.cpp

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

const int MaxN=1010;

struct NUM
{
	long long S,X;
	
	NUM() {}
	NUM(long long x,long long y):S(x),X(y) {}

	bool operator < (const NUM &b) const
	{
		double x,y;

		if(X==0)
			x=0;
		else
			y=(double)S/(double)X;

		if(b.X==0)
			y=0;
		else
			y=(double)b.S/(double)b.X;

		return x<y;
	}

	NUM operator + (const NUM &b) const
	{
		return NUM(S+b.S,X+b.X);
	}

	void dis() const
	{
		cout<<S<<'/'<<X<<endl;
	}
};

NUM dp[MaxN];
int N,K;
NUM num[MaxN];

inline NUM max1(NUM a,NUM b)
{
	if(a<b)
		return b;
	return a;
}

bool cmp(const NUM &a,const NUM &b)
{
	return b<a;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	NUM ans;

	while(~scanf("%d %d",&N,&K) && N+K)
	{
		K=N-K;

		for(int i=1;i<=N;++i)
			scanf("%lld",&num[i].S);
		for(int i=1;i<=N;++i)
			scanf("%lld",&num[i].X);

		sort(num+1,num+N+1,cmp);

		for(int i=0;i<=N;++i)
			d[i].S=dp[i].X=0;
		ans.S=ans.X=0;

		for(int i=1;i<=N;++i)
			for(int j=i;j>=1;--j)
				dp[j]=max1(dp[j],dp[j-1]+num[i]);

		for(int i=K;i<=N;++i)
			ans=max1(ans,dp[i]);

		ans.dis();

		printf("%.0f\n",100.0*(double)ans.S/(double)ans.X);
	}
	
	return 0;
}
