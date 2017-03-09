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
// Created Time  : 2015年07月03日 星期五 20时17分09秒
// File Name     : test1.cpp

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

int rem1[100],rem2[100];
int num[200];
int N;

bool judge(int x)
{
	int cou1=0,cou2=0;

	for(int i=0;i<N;++i)
		if((1<<i) & x)
		{
			rem1[++cou1]=num[i+1];
		}
		else
			rem2[++cou2]=num[i+1];

	if(cou1!=cou2)
		return 0;

	for(int i=1;i<=cou1;++i)
		if(rem1[i]!=rem2[i])
			return 0;

	for(int i=1;i<=cou1;++i)
		cout<<rem1[i]<<' ';

	return 1;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out1.txt","w",stdout);

	int T;

	cin>>T;

	while(T--)
	{
		cin>>N;

		for(int i=1;i<=N;++i)
			cin>>num[i];

		bool ok=0;

		for(int i=0;i<(1<<N);++i)
			if(judge(i))
			{
				puts("Good job!!");
				ok=1;
				break;
			}

		if(!ok)
			puts("What a pity!");
	}
	
	return 0;
}
