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
// Created Time  : 2015年10月09日 星期五 18时45分52秒
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

const int MaxN=100005;

int N,M,P;
long long DP1[MaxN],DP2[MaxN];
long long *dp1,*dp2;
long long H[MaxN];
long long S[MaxN];

long long X[MaxN],Y[MaxN],cou;

long long d[MaxN];

bool better(int a,int b,long long H)
{
	return (Y[a]-X[a]*H)<=(Y[b]-X[b]*H);
}

bool judge(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3)
{
	return (y1-y2)*(x2-x3)<=(y2-y3)*(x1-x2);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ios::sync_with_stdio(false);
	cin>>N>>M>>P;

	d[1]=0;
	for(int i=2;i<=N;++i)
	{
		cin>>d[i];
		d[i]+=d[i-1];
	}
	long long a,b;
	for(int i=1;i<=M;++i)
	{
		cin>>a>>b;
		H[i]=b-d[a];
	}

	dp1=DP1;
	dp2=DP2;
	N=M;
	sort(H+1,H+N+1);

	S[0]=0;
	for(int i=1;i<=N;++i)
	{
		S[i]=S[i-1]+H[i];
		dp1[i]=H[i]*i-S[i];
	}

	int p;
	long long TX,TY;
	P=min(P,N);

	for(int j=2;j<=P;++j)
	{
		cou=1;
		Y[0]=dp1[j-1]+S[j-1];
		X[0]=j-1;
		p=0;

		for(int i=j;i<=N;++i)
		{
			while(p<cou-1 && better(p+1,p,H[i])) ++p;
			dp2[i]=Y[p]-X[p]*H[i]-S[i]+i*H[i];

			TX=i;
			TY=dp1[i]+S[i];

			while(cou-1>p && judge(TX,TY,X[cou-1],Y[cou-1],X[cou-2],Y[cou-2])) --cou;
			X[cou]=TX;
			Y[cou++]=TY;
		}
		swap(dp1,dp2);
	}

	cout<<dp1[N]<<endl;

	return 0;
}
