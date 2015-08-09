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
// Created Time  : 2015年07月28日 星期二 15时45分56秒
// File Name     : 1008.cpp

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

int que[100000];
int first,last;

void dis(int N)
{
	first=last=0;
	que[last++]=N;
	
	int t;
	int a,b;

	while(last-first)
	{
		t=que[first++];

		a=t/100000;
		b=t%100000;

		cout<<a<<"-"<<b<<' ';

		if(a==b)
		{
			if(b==N)
				cout<<endl;
			continue;
		}

		int m=(a+b)/2;

		que[last++]=a*100000+m;
		que[last++]=(m+1)*100000+b;

		if(b==N)
			cout<<endl;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	for(int i=1;i<=10;++i)
	{
		dis(i);
		cout<<endl<<endl;
	}
	
	return 0;
}
