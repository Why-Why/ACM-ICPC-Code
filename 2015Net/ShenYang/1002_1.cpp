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
// Created Time  : 2015年09月20日 星期日 22时37分34秒
// File Name     : 1002_1.cpp

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

int M;
long long x;
long long rem[1000000];
int remp[100000];
int cou;

int getnum(long long x,int mod)
{
	long long ret=1;
	long long base=2;

	while(x)
	{
		if(x&1) (ret*=base)%=mod;
		(base*=base)%=mod;
		x>>=1;
	}

	return (ret+1)%mod;
}

int find(int M)
{
	int rem1,rem0;
	long long s1,s2,s3;
	int p;

	rem1=10%M; rem0=2%M;
	cou=0;
	rem[cou++]=rem0;
	rem[cou++]=rem1;
	s1=2;
	s2=10;
	for(int i=2;;++i)
	{
		s3=(10*s2-s1+M)%M;
		rem[cou++]=s3;
		if(s3==rem1 && s2==rem0)
		{
			p=i-1;
			break;
		}

		s1=s2;
		s2=s3;
	}

	remp[M]=p;
	return p;
}

int find1(int cou,int mod)
{
	rem[0]=2%mod;
	rem[1]=10%mod;

	for(int i=2;i<=cou;++i)
		rem[i]=(rem[i-1]*10-rem[i-2]+mod)%mod;
	return rem[cou];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	memset(remp,-1,sizeof(remp));

	int T,cas=1;
	int p;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%I64d %d",&x,&M);
		if(remp[M]==-1)
		{
			p=find(M);
			printf("Case #%d: %d\n",cas++,(rem[getnum(x,p)]-1+M)%M);
		}
		else
			printf("Case #%d: %d\n",cas++,(find1(getnum(x,remp[M]),M)-1+M)%M);
	}
	
	return 0;
}
