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
// Created Time  : 2015年07月03日 星期五 23时28分26秒
// File Name     : B_1.cpp

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

int R[100005];
int L[100005];
int num[100005];
long long ans[100005];
int N,Q,K;
int Stack[100005],top;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);

	for(int i=1;i<=N;++i)
		scanf("%d",&num[i]);

	top=0;
	Stack[top++]=0;
	Stack[top++]=1;
	L[1]=0;

	for(int i=2;i<=N;++i)
	{
		while(top>1 && num[Stack[top-1]]<num[i])
			--top;

		L[i]=i-1-Stack[top-1];
		Stack[top++]=i;
	}

	top=0;
	Stack[top++]=N+1;
	Stack[top++]=N;
	R[N]=0;

	for(int i=N-1;i>=1;--i)
	{
		while(top>1 && num[Stack[top-1]]<=num[i])
			--top;

		R[i]=Stack[top-1]-1-i;
		Stack[top++]=i;
	}

	ans[0]=0;

	for(int i=1;i<=N;++i)
		ans[num[i]]+=(L[i]+1LL)*(R[i]+1LL);

	for(int i=1;i<=100000;++i)
		ans[i]+=ans[i-1];

	scanf("%d\n",&Q);

	while(Q--)
	{
		scanf("%d",&K);
		printf("%lld\n",(long long)N*(N+1LL)/2LL-ans[K-1]);
	}
	
	return 0;
}
