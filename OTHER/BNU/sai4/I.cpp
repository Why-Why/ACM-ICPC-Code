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
// Created Time  : 2015年10月05日 星期一 12时01分25秒
// File Name     : I.cpp

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

char s[1000000];
char rem[100000][35];
int map1[30000];
int cou=1;
char ts[40];

inline bool in(char c)
{
	return (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9');
}

char bian(char t1)
{
	if(t1>='A' && t1<='Z') t1+=('a'-'A');
	return t1;
}

inline bool isnum(char c)
{
	return c>='0' && c<='9';
}

int find(char s[],int L)
{
	if(L<=2) return 0;
	if(isnum(s[0]) || isnum(s[L-1])) return 0;
	int x=0;
	for(int i=1;i<L-1;++i)
	{
		if(isnum(s[i])==0) return 0;
		x=x*10+s[i]-'0';
		if(x>30) return 0;
	}

	if(x<2) return 0;

	char t1=bian(s[0]),t2=bian(s[L-1]);
	int t=(t1-'a')*26+(t2-'a')+x*27*27;

	if(t<30000)
		if(map1[t]<=0) return 0;
		else return map1[t];
}

void show(int t,char t1,char t2)
{
	if(t1>='A' && t1<='Z')
	{
		if(t2>='A' && t2<'Z')
			for(int i=0;rem[t][i];++i)
				printf("%c",bian(rem[t][i])-32);
		else
		{
			printf("%c",bian(rem[t][0])-32);

			for(int i=1;rem[t][i];++i)
				printf("%c",bian(rem[t][i]));
		}
	}
	else
	{
		for(int i=0;rem[t][i];++i)
			printf("%c",bian(rem[t][i]));
	}
}

int zhuan(char s[],int L)
{
	if(L<2) return 0;
	for(int i=0;s[i];++i)
		if(isnum(s[i])) return 0;
	char t1=s[0],t2=s[L+1];
	t1=bian(t1),t2=bian(t2);

	return (t1-'a')*26+(t2-'a')+L*27*27;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int L=-1;
	int t;
	int tcou=0;

	while(gets(s))
	{
		for(int i=0;i==0 || s[i-1];++i)
			if(in(s[i]))
			{
				if(L==-1) L=i;
				ts[tcou++]=s[i];
			}
			else
			{
				if(L!=-1)
				{
					ts[tcou]=0;
					if(t=find(ts,i-L))
					{
						show(t,ts[0],ts[tcou-1]);
					}
					else
					{
						t=zhuan(ts,i-L-2);
						if(map1[t]) map1[t]=-1;
						else map1[t]=cou;
						strcpy(rem[cou],ts);
						++cou;
						printf("%s",ts);
					}
					L=-1;
				}
				if(s[i])
					printf("%c",s[i]);
				tcou=0;
			}
		puts("");
	}
	
	return 0;
}
