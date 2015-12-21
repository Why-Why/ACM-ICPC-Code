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
// Created Time  : 2015年08月12日 星期三 12时12分17秒
// File Name     : 108.cpp

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

/*


bool judge(int x)
{
	for(int i=max(1,x-100);i<=x;++i)
		if(bian(i)==x)
			return 0;
	return 1;
}
*/
int cou;
int rem[10000000];

bool vis[10000007];

int bian(int x)
{
	int cou=x;
	while(x)
	{
		cou+=x%10;
		x/=10;
	}

	return cou;
}

void init()
{
	for(int i=1;i<=10000000;++i)
		if(!vis[i])
		{
			rem[cou++]=i;
			for(int j=bian(i);!vis[j] && j<=10000000;j=bian(j))
				vis[j]=1;
		}
}

int num[980005];
set <int> sta;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t;
	int ccc=0;

	init();
//	cout<<cou<<endl;
//	cout<<rem[cou-1]<<endl;
//	for(int i=1;i<cou;++i)
//		sta.insert(rem[i]-rem[i-1]);
//
//	for(set <int> ::iterator iter=sta.begin();iter!=sta.end();++iter)
//		cout<<*iter<<endl;

	for(int i=0,cou=0;i<=10000;++i,++cou)
	{
		if(cou==22)
		{
			printf("\n");
			cou=0;
		}
		
		if(rem[i]-rem[i-1]!=11)
			printf("%8d",rem[i]-rem[i-1]);
		else
			printf("       .");
	}

	return 0;
}
