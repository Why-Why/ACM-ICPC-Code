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
// Created Time  : 2015年09月23日 星期三 19时20分26秒
// File Name     : K.cpp

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

const int MaxN=1010;

int N,M;
int A[MaxN],B[MaxN];

int getnum(int A,int B,int t)
{
	int r=t%(B-A);
	int d=t/(B-A);

	if(d&1) return B-r;
	else return A+r;
}

int query(int x,int y,int t)
{
	int ret=0;
	int temp;
	
	for(int i=1;i<=N;++i)
	{
		temp=getnum(A[i],B[i],t);
		if(temp>=x && temp<=y) ++ret;
	}

	return ret;
}

int main()
{
	freopen("knockout.in","r",stdin);
	freopen("knockout.out","w",stdout);

	int a,b,c;

	scanf("%d %d",&N,&M);

	for(int i=1;i<=N;++i)
		scanf("%d %d",A+i,B+i);

	while(M--)
	{
		scanf("%d %d %d",&a,&b,&c);
		printf("%d\n",query(a,b,c));
	}
	
	return 0;
}
