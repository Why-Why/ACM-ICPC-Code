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
// Created Time  : 2016年01月17日 星期日 10时43分23秒
// File Name     : C.cpp

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

long long A,B;
long long C[MaxN];
long long sum[MaxN];
int N;

inline int getK(long long sum,long long t) {
	return t/sum;
}

inline int getT(long long t) {
	return upper_bound(sum+1,sum+N+1,t)-sum-1;
}

inline double getans1(long long A,long long B) {
	double ret=0;
	bool ok=0;
	int a=getT(A),b=getT(B);

	if(a==b) ret=(B-A+0.0)*(B+A+0.0)/2.0;
	else {
		ret=(sum[a+1]-A+0.0)*(sum[a+1]-sum[a]+A-sum[a]+0.0)/2.0;
		ret+=(B-sum[b]+0.0)*(B-sum[b]+0.0)/2.0;
		for(int i=a+1;i<b;++i) ret+=(sum[i+1]-sum[i]+0.0)*(sum[i+1]-sum[i]+0.0)/2.0;
	}
	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	scanf("%d",&T);

	while(T--) {
		memset(sum,0,sizeof(sum));
		memset(C,0,sizeof(C));
		sum[0]=0;
		scanf("%d %lld %lld",&N,&A,&B);
		for(int i=1;i<=N;++i) scanf("%lld",C+i),sum[i]=sum[i-1]+C[i];

		int a=getK(sum[N],A),b=getK(sum[N],B);
		double ans=0;
		double len=B-A;
		A-=sum[N]*a;
		B-=sum[N]*b;
		if(a==b) ans=getans1(A,B);
		else {
			ans=getans1(A,sum[N])+getans1(0,B);
			ans+=getans1(0,sum[N])*(b-a-1.0);
		}
		printf("Case #%d: %.9f\n",cas++,ans/len);
	}
	
	return 0;
}
