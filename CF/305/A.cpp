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
// Created Time  : 2015年05月27日 星期三 00时29分21秒
// File Name     : A.cpp

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

int vis1[1000006],vis2[1000006];
long long m;
long long h1,a1,x1,ty1,h2,a2,x2,y2;

long long extend_gcd(long long a,long long b,long long &x,long long &y)
{
	if(a==0&&b==0) return -1;//无最大公约数
	if(b==0){x=1;y=0;return a;}
	long long d=extend_gcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

long long gcd(long long a,long long b)
{
	if(a==0)
		return b;

	return gcd(b%a,a);
}

long long getans(long long B1,long long tS1,long long T1,long long B2,long long tS2,long long T2)
{
	long long d1,d2;

	if(B1<tS1)
		d1=0;
	else
		d1=T1;

	if(B2<tS2)
		d2=0;
	else
		d2=T2;

	if(B1==B2)
		return B1-1;

	long long D=B2-B1;

	d2=-d2;

	if(D<0)
	{
		D=-D;
		d1=-d1;
		d2=-d2;
	}

	long long temp=gcd(abs(d1),abs(d2));

	cout<<B1<<' '<<d1<<' '<<B2<<' '<<d2<<endl;

	if(D%temp)
		return -1;

	long long x,y;
	long long dd1,dd2;

	extend_gcd(abs(d1),abs(d1),x,y);

	dd1=d2/temp;
	dd2=-d1/temp;


	/*if(d1<0)
	{
		dd1=-dd1;
		x=-x;
	}

	if(d2<0)
	{
		dd2=-dd2;
		y=-y;
	}*/

	x*=D/temp;
	y*=D/temp;

	cout<<x<<' '<<dd1<<' '<<y<<' '<<dd2<<endl;
	long long l=0,r=10000000000000000LL;

	if(dd1>0)
		l=max(l,(-x-1)/dd1+1);
	else
		r=min(r,(-x)/dd1);

	if(dd2>0)
		l=max(l,(-y-1)/dd2+1);
	else
		r=min(r,(-y)/dd2);

	if(r<l)
		return -1;

	return (x+dd1*l)*d1+B1-1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>m;
	cin>>h1>>a1>>x1>>ty1;
	cin>>h2>>a2>>x2>>y2;

	long long T1,T2,tS1,tS2;

	vis1[h1]=1;
	vis2[h2]=1;

	for(int i=2;;++i)
	{
		h1=(x1*h1+ty1)%m;

		if(vis1[h1])
		{
			T1=i-vis1[h1];
			tS1=vis1[h1];
			break;
		}

		vis1[h1]=i;
	}

	for(int i=2;;++i)
	{
		h2=(x2*h2+y2)%m;

		if(vis2[h2])
		{
			T2=i-vis2[h2];
			tS2=vis2[h2];
			break;
		}

		vis2[h2]=i;
	}

	if(vis1[a1]==0 || vis2[a2]==0)
	{
		puts("-1");
		return 0;
	}

	cout<<getans(vis1[a1],tS1,T1,vis2[a2],tS2,T2)<<endl;
	
	return 0;
}
