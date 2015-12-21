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
// Created Time  : 2015年09月07日 星期一 20时31分01秒
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

int a,b,c,l;
long long ans=0;

long long getnum0(int L,int R,int B)
{
	if(R<0) return 0;
	if(L<0) L=0;

	if(B<0)
	{
		if(R<(-B)) return 0;
		if(L<(-B)) L=-B;
	}

	if(R<L) return 0;

	return (L+B+R+B+2LL)*(R-L+1LL)/2;
}

long long getnum1(int L,int R,int B)
{
	if(L>B) return 0;
	if(R>B) R=B;

	if(R<0) return 0;
	if(L<0) L=0;

	if(R<L) return 0;

	return (-L+B-R+B+2LL)*(R-L+1LL)/2;
}

long long count(int D,int N,int M,int Q)
{
	if(M<Q || D<N)
		return 0;

	long long ret=0;
	int x1=ceil((N-M)/2.0),x2,x3=floor((D-Q)/2.0);

	x2=floor((D-M)/2.0);
	ret+=getnum0(x1,x2,M);
	ret+=getnum1(x2+1,x3,D);

	x2=floor((N-Q)/2.0);
	ret-=getnum1(x1,x2,N-1);
	ret-=getnum0(x2+1,x3,Q-1);

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>a>>b>>c>>l;

	for(int i=0;i<=l;++i)
		ans+=count(l-i,a+i-b-c+1,a+i+b-c-1,b-c+1-a-i);

	cout<<ans<<endl;
	
	return 0;
}
