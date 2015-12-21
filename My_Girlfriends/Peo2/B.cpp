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
// Created Time  : 2015年09月18日 星期五 16时04分15秒
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

const int MaxN=200005;

long long rem[MaxN];
long long ans;
long long n,k,x;
long long zong;

long long num[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ios::sync_with_stdio(false);

	cin>>n>>k>>x;

	zong=1;
	while(k--)
		zong*=x;
	rem[0]=0;

	for(int i=1;i<=n;++i)
	{
		cin>>num[i];
		rem[i]=rem[i-1]|num[i];
	}
	ans=0;

	long long dang=0;
	long long t;
	for(int i=n;i>=1;--i)
	{
		t=num[i]*zong;
		ans=max(ans,dang|t|rem[i-1]);
		dang|=num[i];
	}

	cout<<ans<<endl;
	
	return 0;
}
