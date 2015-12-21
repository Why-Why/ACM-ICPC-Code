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
// Created Time  : 2015年10月05日 星期一 12时46分45秒
// File Name     : I_1.cpp

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
#include <ctype.h>

using namespace std;

char s[1000];
char word[90000][40];
int wcou=0;
char ts[40];

int map1[30000];

int cou;

bool judge(char s[])
{
	for(int i=0;s[i];++i)
		if(isdigit(s[i]))
			return 0;
	return 1;
}

int suo(char s[],int len)
{
	char t1=tolower(s[0]),t2=tolower(s[len-1]);
	return (len-2)*26*26+(t1-'a')*26+(t2-'a');
}

int zhan(char s[],int len)
{
	int x=0;
	char t1=tolower(s[0]),t2=tolower(s[len-1]);

	for(int i=1;i<len-1;++i)
		x=x*10+s[i]-'0';

	return x*26*26+(t1-'a')*26+(t2-'a');
}

void show(char s[],char t1,char t2)
{
	if(isupper(t1))
	{
		if(isupper(t2))
			for(int i=0;s[i];++i)
				printf("%c",toupper(s[i]));
		else
		{
			printf("%c",toupper(s[0]));
			for(int i=1;s[i];++i)
				printf("%c",tolower(s[i]));
		}
	}
	else
	{
		for(int i=0;s[i];++i)
			printf("%c",tolower(s[i]));
	}
}

bool cmp111(char s1[],char s2[])
{
	int i;
	for(i=0;s1[i];++i)
		if(s2[i]==0 || tolower(s1[i])!=tolower(s2[i])) return 1;
	if(s2[i]) return 1;

	return 0;
}

void getans(char c)
{
	if(isalnum(c))
	{
		if(cou==-1) ts[0]=c,cou=1;
		else ts[cou++]=c;

		return;
	}

	if(cou==-1)
	{
		if(c) printf("%c",c);
		return;
	}

	ts[cou]=0;
	if(judge(ts))
	{
		int t=suo(ts,cou);
		if(map1[t]==-1 || (map1[t] && cmp111(word[map1[t]],ts))) map1[t]=-1;
		else
		{
			++wcou;
			strcpy(word[wcou],ts);
			map1[t]=wcou;
		}
		printf("%s",ts);
	}
	else
	{
		int t=zhan(ts,cou);

		if(t>0 && map1[t]>0) show(word[map1[t]],ts[0],ts[cou-1]);
		else printf("%s",ts);
	}

	cou=-1;
	if(c) printf("%c",c);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cou=-1;

	while(gets(s))
	{
		for(int i=0;s[i];++i)
			getans(s[i]);
		getans(0);
		puts("");
	}
	
	return 0;
}
