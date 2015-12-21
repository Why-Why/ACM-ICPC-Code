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
// Created Time  : 2015年09月19日 星期六 13时53分54秒
// File Name     : 1010.cpp

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

string s1="c",s2="ff",s3;
int rem[1000000],cou;
string ts="cff";

long long getans(string &s)
{
	cou=0;
	char tts[]="cff";
	int t=0;

	cout<<s<<endl;

	while((t=s.find_first_of(ts,t))!=string::npos)
		rem[cou++]=t++;

	cout<<cou<<endl;
	for(int i=0;i<cou;++i)
		cout<<rem[i]<<' ';
	cout<<endl;

	long long ret=0;
	for(int i=0;i<cou;++i)
		for(int j=i+1;j<cou;++j)
			ret+=rem[j]-rem[i];

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	string a="asdasdfgh";
	string b="as";

	cout<<a.find_first_of(b,2)<<endl;

	for(int i=3;i<=4;++i)
	{
		s3=s1+s2;
		cerr<<s3<<endl;
		cout<<i<<' '<<getans(s3)<<endl;
		s1=s2;
		s2=s3;
	}
	
	return 0;
}
