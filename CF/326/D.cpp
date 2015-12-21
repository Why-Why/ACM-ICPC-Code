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
// Created Time  : 2015年10月16日 星期五 01时12分45秒
// File Name     : D.cpp

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

const int mod=1000000007;

long long n,d,k,l,r;
long long rem[1000006];
long long num[1000006];
long long tnum[1000006];
long long sum=0;

long long getans(int x)
{
	long long ret=0;
	long long pre=sum;
	long long psum=0;
	long long temp;
	sum=0;

	long long tsum=0;
	long long t1=0;

	for(int i=1,p=1;p<=r;++i)
	{
		while(p<=r && (i>n || num[i]>tnum[p]))
		{
			(tsum+=t1)%=mod;
			++p;
		}
		if(i<=n) (t1+=rem[i])%=mod;
	}

	for(int i=n;i>=1;--i)
	{
		temp=rem[i];

		if(num[i]==num[i+1])
		{
			rem[i]=rem[i+1];
			(sum+=rem[i])%=mod;
		}
		else
		{
			rem[i]=((pre-psum)%mod+mod)%mod;
			(sum+=rem[i])%=mod;
		}
		(psum+=temp)%=mod;
	}

	long long ttt=(d+1-x)%mod;
	ttt=(sum*ttt)%mod;

	(ret+=ttt)%=mod;

	return (ret+tsum)%mod;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ios::sync_with_stdio(false);

	cin>>n>>l>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>num[i];rem[i]=1;
		tnum[i]=num[i];
	}
	sum=n;
	num[n+1]=-1;

	d=l/n;
	r=l%n;
	sort(num+1,num+n+1);
	if(r) sort(tnum+1,tnum+r+1);

	long long ans=l%mod;

	for(int i=2;i<=k && i<=(d+1);++i)
		(ans+=getans(i))%=mod;

	cout<<ans<<endl;
	
	return 0;
}
