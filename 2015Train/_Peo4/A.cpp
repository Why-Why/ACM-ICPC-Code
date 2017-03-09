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
// Created Time  : 2015年09月25日 星期五 19时53分27秒
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

long long gcd(long long a,long long b)
{
	if(!a) return b;
	return gcd(b%a,a);
}

struct Number
{
	long long S,X;

	Number() {}
	Number(long long a,long long b)
	{
		S=a;
		X=b;
		jian();
	}

	void jian()
	{
		if(X<0) X=-X,S=-S;
		long long t=gcd(abs(S),X);
		S/=t;
		X/=t;
	}

	Number operator + (const Number & b) const
	{
		Number ret;
		ret.X=X*b.X;
		ret.S=S*b.X+b.S*X;
		ret.jian();
		return ret;
	}

	Number operator - (const Number & b) const
	{
		Number ret;
		ret.X=X*b.X;
		ret.S=S*b.X-b.S*X;
		ret.jian();
		return ret;
	}

	Number operator * (const Number & b) const
	{
		Number ret;
		ret.S=S*b.S;
		ret.X=X*b.X;
		ret.jian();
		return ret;
	}

	Number operator / (const Number & b) const
	{
		Number ret;
		ret.S=S*b.X;
		ret.X=X*b.S;
		ret.jian();
		return ret;
	}

	void zdao()
	{
		swap(S,X);
	}

	Number dao() const
	{
		Number ret;
		ret.X=S;
		ret.S=X;
		return ret;
	}
};

Number getnum(int num[],int len)
{
	Number a;
	a.S=num[0];
	a.X=1;

	if(len==1) return a;

	Number b=getnum(num+1,len-1);
	b.zdao();

	return a+b;
}

void show(Number num)
{
	if(num.X==1 || num.S==0)
	{
		cout<<num.S;
		return;
	}

//	long long t=floor((double)num.S/num.X);
	long long t=num.S/num.X;
	if(t*num.X>num.S) --t;
	num.S-=t*num.X;
	cout<<t<<' ';
	show(num.dao());
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ios::sync_with_stdio(false);

	int cas=1;
	int N1,N2;
	int rem[20];
	Number t1,t2,t;

	while(cin>>N1>>N2 && N1+N2)
	{
		for(int i=1;i<=N1;++i)
			cin>>rem[i];
		t1=getnum(rem+1,N1);

		for(int i=1;i<=N2;++i)
			cin>>rem[i];
		t2=getnum(rem+1,N2);

		cout<<"Case "<<cas++<<":\n";
		t=t1+t2;
		show(t);
		cout<<endl;
		t=t1-t2;
		show(t);
		cout<<endl;
		t=t1*t2;
		show(t);
		cout<<endl;
		t=t1/t2;
		show(t);
		cout<<endl;
	}
	
	return 0;
}
