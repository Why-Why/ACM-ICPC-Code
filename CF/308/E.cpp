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
// Created Time  : 2015年06月19日 星期五 01时48分51秒
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

char s[6000];
int len,cou;
long long pc[6000],pj[6000];
long long ans;

void init()
{
	int p=len-1;

	pj[len+1]=0;
	pc[len+1]=0;

	while(p>=0)
	{
		if(s[p+1]=='*')
		{
			pc[p]=pc[p+2]*(s[p]-'0');
			pj[p]=pj[p+2];
		}
		else
		{
			pj[p]=pc[p+2]+pj[p+2];
			pc[p]=s[p]-'0';
		}

		p-=2;
	}
}

void chuli(int x,char c,long long qj,long long qc)
{
	long long zj=0,zc=0;
	long long temp,zhong,hou;

	for(int i=x;i<len;i+=2)
	{
		if(i==x || s[i-1]=='+')
		{
			zj+=zc;
			zc=s[i]-'0';
		}
		else
			zc*=s[i]-'0';

		if(c=='+')
			if(s[i+1]=='+')
				temp=qj+(zj+zc)+pj[i];
			else
				temp=qj+(zj+zc)*pc[i+2]+pj[i+2];
		else
			if(s[i+1]=='+')
				temp=qj+qc*(zj+zc)+pj[i];
			else
				temp=qj+qc*(zj+zc)*pc[i+2]+pj[i+2];

		ans=max(ans,temp);
	}
}

void getans()
{
	ans=0;
	long long tc=0,tj=0;
	long long hou,temp,zhong;

	for(int i=0;i<len;i+=2)
	{
		if(i==0 || s[i-1]=='+')
		{
			tj+=tc;
			tc=s[i]-'0';
			chuli(i,'+',tj,tc);
		}
		else
		{
			chuli(i,'*',tj,tc);
			tc*=s[i]-'0';
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%s",s);
	len=strlen(s);
	cou=(len+1)/2;
	s[len]='+';

	init();
	getans();

	cout<<ans<<endl;
	
	return 0;
}
