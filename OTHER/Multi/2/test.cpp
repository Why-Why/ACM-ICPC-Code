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
// Created Time  : 2015年07月24日 星期五 00时51分00秒
// File Name     : test.cpp

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

long double A[300000];
char s[20000];
int N;
bool vis[300000];

bool judge()
{
	int a,b;
	int x;
	char c;

	for(int i=1;i<N;++i)
	{
		cin.getline(s,20000);
		a=b=0;

		for(x=0;s[x]<='9' && s[x]>='0';++x)
			a=a*10+s[x]-'0';

		c=s[x+1];
		x+=3;

		for(;s[x];++x)
			b=b*10+s[x]-'0';

		if(a>=N+i || b>=N+i)
			return 0;

		if(vis[a] || vis[b])
			return 0;

		vis[a]=vis[b]=1;

		if(c=='+')
			A[N+i]=A[a]+A[b];
		else if(c=='-')
			A[N+i]=A[a]-A[b];
		else if(c=='*')
			A[N+i]=A[a]*A[b];
		else
			A[N+i]=A[a]/A[b];

		if(fabs(A[N+i])>1e9)
			return 0;
	}

	if(cin>>s)
		return 0;

	return fabs(A[N+N-1]-24.0)<1e-8;
}

int main()
{
	cin>>N;

	for(int i=1;i<=N;++i)
		A[i]=N;

	freopen("out.txt","r",stdin);
	cout<<judge()<<endl;
	
	return 0;
}
