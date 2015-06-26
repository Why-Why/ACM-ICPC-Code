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
// Created Time  : 2015年06月04日 星期四 15时44分53秒
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

typedef pair <long long,long long> pii;
set <pii> sta;

long long gcd(long long a,long long b)
{
	if(!a)
		return b;

	return gcd(b%a,a);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n;
	long long x,y,a,b,t;

	ios::sync_with_stdio(false);

	cin>>n>>x>>y;

	while(n--)
	{
		cin>>a>>b;
		a-=x;
		b-=y;

		if(b<0)
		{
			b=-b;
			a=-a;
		}
		else if(b==0 && a<0)
			a=-a;

		t=gcd(abs(a),abs(b));

		a/=t;
		b/=t;

		sta.insert(pii(a,b));
	}

	cout<<sta.size()<<endl;
	
	return 0;
}
