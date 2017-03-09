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
// Created Time  : 2015年09月22日 星期二 16时10分21秒
// File Name     : 1007.cpp

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

const int MaxN=510;
const int num[]={6,2,5,5,4,5,6,3,7,6};

long long dp[MaxN][MaxN];

inline int getsum(int a,int b,int c)
{
	return num[a]+num[b]+num[c];
}

long long getans(int N,long long M)
{
	cout<<N<<' '<<M<<endl;
	int d,s;

	memset(dp,0,sizeof(dp));
	dp[0][0]=1;

	for(int i=1;i<=N;++i)
		for(int j=0;j<10;++j)
			for(int k=0;k<10;++k)
			{
				if(j+k<10) d=0;
				else d=1;
				s=getsum(j,k,(j+k)%10);
				if(i-s<0) continue;

				cout<<j<<' '<<k<<' '<<s<<endl;

				for(int t=0;t<=i;++t)
					(dp[i][t]+=dp[i-s][t+d])%=M;
			}

	for(int i=0;i<=N;++i,cout<<endl)
		for(int j=0;j<13;++j)
		cout<<dp[i][j]<<' ';
	cout<<endl;

	return dp[N][0];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int N;
	long long M;

	scanf("%d",&T);

	while(T--)
	{
		//scanf("%d %I64d",&N,&M);
		cin>>N>>M;
		printf("Case #%d: %I64d\n",cas++,getans(N-3,M));
	}
	
	return 0;
}
