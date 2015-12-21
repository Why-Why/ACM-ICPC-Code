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
// Created Time  : 2015年10月05日 星期一 10时52分24秒
// File Name     : t.cpp

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
#include <stack>

using namespace std;

char rem[10][5];
int N;

int wei[100];
stack <int> you[3];
int last;

bool judge(int id)
{
	if(you[rem[id][0]-'A'].empty()) return 0;
	if(you[rem[id][0]-'A'].top()!=last && (you[rem[id][1]-'A'].empty() || you[rem[id][1]-'A'].top()>you[rem[id][0]-'A'].top()))
		return 1;
	return 0;
}

void change(int id)
{
	int t=you[rem[id][0]-'A'].top();
	you[rem[id][0]-'A'].pop();
	wei[t]=rem[id][1]-'A';
	you[rem[id][1]-'A'].push(t);
	last=t;
}

long long getans()
{
	int ret=0;
	last=-1;
	bool ok=0;

	while(ok==0 || you[0].empty()+you[1].empty()+you[2].empty()!=2)
	{
		ok=1;

		for(int i=0;i<6;++i)
			if(judge(i))
			{
				cout<<i<<endl;
				change(i);
				++ret;

				break;
			}
	}

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cou,last;

	while(cin>>N)
	{
		for(int i=0;i<6;++i)
			cin>>rem[i];

		for(int i=1;i<=N;++i) wei[i]=1;
		for(int i=0;i<3;++i)
			while(!you[i].empty()) you[i].pop();

		for(int i=N;i>=1;--i)
			you[0].push(i);

		printf("%lld\n",getans());
	}

	return 0;
}
