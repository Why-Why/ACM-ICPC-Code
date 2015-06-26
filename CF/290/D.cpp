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
// Created Time  : 2015年05月19日 星期二 09时59分05秒
// File Name     : D.cpp

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

typedef pair<int,int> pii;
priority_queue <pii> que;
map <int,int> sta;
int N;
int L[400],C[400];

int gcd(int a,int b)
{
	if(!b)
		return a;

	return gcd(b,a%b);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	pii temp;
	int t;
	int ans=-1;
	map <int,int>::iterator p;

	scanf("%d",&N);

	for(int i=1;i<=N;++i)
		scanf("%d",&L[i]);

	for(int i=1;i<=N;++i)
		scanf("%d",&C[i]);

	for(int i=1;i<=N;++i)
	{
		que.push(pii(L[i],C[i]));

		p=sta.find(L[i]);

		if(p==sta.end())
			sta.insert(pii(L[i],C[i]));
		else if((*p).second>C[i])
			(*p).second=C[i];
	}

	while(!que.empty())
	{
		temp=que.top();
		que.pop();
		sta.erase(temp.first);

		if(temp.first==1)
			if(ans==-1 || ans>temp.second)
				ans=temp.second;

		for(int i=1;i<=N;++i)
		{
			t=gcd(temp.first,L[i]);
			p=sta.find(t);

			if(t==temp.first)
				continue;

			if(p==sta.end())
			{
				que.push(pii(t,C[i]+temp.second));
				sta.insert(pii(t,C[i]+temp.second));
			}
			else if(temp.second+C[i]<(*p).second)
			{
				(*p).second=temp.second+C[i];
				que.push(pii(t,temp.second+C[i]));
			}
		}

		sta.erase(temp.first);
	}

	printf("%d\n",ans);
	
	return 0;
}
