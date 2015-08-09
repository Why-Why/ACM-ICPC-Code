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
// Created Time  : 2015年08月05日 星期三 10时16分25秒
// File Name     : 1009.cpp

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

string s[30];

bool judge(string &s,int len,int M)
{
	for(int i=0;i<len;++i)
		if(s[i]!=s[M-len+i])
			return 0;

	return 1;
}

int getans(string &s,int M)
{
	for(int i=M-1;i>=0;--i)
		if(judge(s,i,M))
			return i;
}

int rem[10000];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	s[1]="b";
	s[2]="a";

	for(int i=3;i<=20;++i)
		s[i]=s[i-1]+s[i-2];

	int N,M;

	for(int i=1;i<=20;++i)
		cout<<s[i].size()<<endl;

	for(int i=1;i<=10;++i)
		cout<<s[i]<<endl;

	int T=100;

	for(int i=1;i<=T;++i)
		rem[i]=getans(s[20],i);

	rem[0]=-2;
	int remcou[10000];
	int kai[10000];
	int rcou=0;
	int cou=0;

	for(int i=1;i<=T;++i)
		if(rem[i]!=rem[i-1]+1)
		{
			cout<<endl<<rem[i];
			kai[rcou]=rem[i];
			remcou[rcou++]=cou;
			cou=1;
		}
		else
		{
			cout<<' '<<rem[i];
			++cou;
		}

	cout<<endl;
	for(int i=1;i<rcou;++i)
		cout<<kai[i]<<' ';
	cout<<endl;
	
	return 0;
}
