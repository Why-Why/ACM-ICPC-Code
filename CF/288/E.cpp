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
// Created Time  : 2015年06月03日 星期三 19时15分35秒
// File Name     : E.cpp

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

int N;
int L[7000],R[7000];
bool ans[7000];

int getnum(int p,int wei)
{
	if(p>N)
		return -1;

	ans[wei]=1;

	if(L[p]==1)
	{
		ans[wei+1]=0;
		return 1;
	}

	int sum=0,temp;

	while(1)
	{
		temp=getnum(p+sum+1,wei+sum*2+1);					// !!!

		if(temp==-1)
			return -1;

		sum+=temp;

		if(2*sum+1>R[p])
			return -1;

		if(2*sum+1>=L[p])
			break;
	}

	ans[wei+2*sum+1]=0;
	
	return sum+1;
}

bool getans()
{
	int p=1;
	int t;
	int wei=1;

	while(p<=N)
	{
		t=getnum(p,wei);
		
		if(t==-1)
			return 0;

		p+=t;
		wei+=t*2;
	}

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);

	for(int i=1;i<=N;++i)
		scanf("%d %d",&L[i],&R[i]);

	if(!getans())
	{
		puts("IMPOSSIBLE");
		return 0;
	}

	for(int i=1;i<=N+N;++i)
		if(ans[i])
			printf("(");
		else
			printf(")");
	puts("");
	
	return 0;
}
