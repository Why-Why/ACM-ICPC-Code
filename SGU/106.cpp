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
// Created Time  : 2015年08月10日 星期一 17时57分06秒
// File Name     : 106.cpp

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <time.h>

using namespace std;

long long a,b,c;
long long x1,x2,y11,y2;
long long d,x,y,k;
long long l1,l2,r1,r2;

void gcd(long long a,long long b,long long &d,long long &x,long long &y)
{
	if(!b) { d=a; x=1; y=0; }
	else { gcd(b,a%b,d,y,x); y-=x*(a/b); }
}

long long getans()
{
	if(x1>x2 || y11>y2)
		return 0;

	if(a==0 && b==0)
		return c ? 0 : ((long long)(x2-x1)+1LL)*((long long)(y2-y11)+1LL);

	c=-c;

	if(a==0)
	{
		if(c%b) return 0;
		if(c/b>=y11 && c/b<=y2)
			return x2-x1+1;
		else return 0;
	}
	if(b==0)
	{
		if(c%a) return 0;
		if(c/a>=x1 && c/a<=x2)
			return y2-y11+1;
		else return 0;
	}

	gcd(abs(a),abs(b),d,x,y);
	if(c%d) return 0;

	x*=c/d; y*=c/d;
	a/=d; b/=d;

//	cout<<x<<' '<<y<<' '<<a<<' '<<b<<endl;

//	x+=((long long)(-x/b))*b;
//	y-=((long long)(-x/b))*a;

	if(b>0)
	{
		l1=ceil(double(x1-x)/(double)b);
		r1=floor(double(x2-x)/(double)b);
	}
	else
	{
		l1=ceil(double(x2-x)/(double)b);
		r1=floor(double(x1-x)/(double)b);
	}

	for(int i=-1;i<=1;++i)
		if(x+(l1+i)*b>=x1 && x+(l1+i)*b<=x2)
		{
			l1+=i;
			break;
		}

	for(int i=1;i>=-1;--i)
		if(x+(r1+i)*b<=x2 && x+(r1+i)*b>=x1)
		{
			r1+=i;
			break;
		}

	if(a>0)
	{
		l2=ceil(double(y-y2)/(double)a);
		r2=floor(double(y-y11)/(double)a);
	}
	else
	{
		l2=ceil(double(y-y11)/(double)a);
		r2=floor(double(y-y2)/(double)a);
	}

	for(int i=-1;i<=1;++i)
		if(y-(l2+i)*a>=y11 && y-(l2+i)*a<=y2)
		{
			l2+=i;
			break;
		}

	for(int i=1;i>=-1;--i)
		if(y-(r2+i)*a>=y11 && y-(r2+i)*a<=y2)
		{
			r2+=i;
			break;
		}
	
	return max(0LL,min(r1,r2)-max(l1,l2)+1);
}

long long judge()
{
	long long ret=0;
	long long y;

	for(int i=x1;i<=x2;++i)
		if((-c-a*i)%b==0)
		{
			y=(-c-a*i)/b;
			if(y<=y2 && y>=y11)
				++ret;
		}

	return ret;
}

long long gcd111(long long a,long long b)
{
	if(!a) return b;
	return gcd111(b%a,a);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&x1,&x2,&y11,&y2))
		printf("%lld\n",getans());

/*	long long t1,t2;
	long long ta,tb,tc,tx1,tx2,ty1,ty2;

	srand(time(0));

	for(int i=1;i<=100000;++i)
	{
		a=rand()%100000000;
		b=rand()%100000000;
		c=gcd111(a,b)*(rand()%1000);
		x1=rand()%2000-1000;
		x2=x1+rand()%1000;
		y1=rand()%2000-1000;
		y2=y1+rand()%1000;

		ta=a,tb=b,tc=c,tx1=x1,tx2=x2,ty1=y1,ty2=y2;

		t1=getans();
		a=ta,b=tb,c=tc,x1=tx1,x2=tx2,y1=ty1,y2=ty2;
		t2=judge();

		if(t1==t2)
		;//	puts("YES");
		else
			cout<<"NO "<<ta<<' '<<tb<<' '<<tc<<' '<<tx1<<' '<<tx2<<' '<<ty1<<' '<<ty2<<endl<<t1<<' '<<t2<<endl;
	}*/
	
	return 0;
}
