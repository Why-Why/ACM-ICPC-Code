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
// Created Time  : 2015年07月18日 星期六 13时16分48秒
// File Name     : A.cpp

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

const int MaxN=1000006;

char s[MaxN];
char temp[MaxN];

bool in(char c)
{
	return (c<='9' && c>='0') || (c<='E' && c>='A');
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int flag=0;
	int cou=0;
	int N;

	scanf("%s",s);

	N=strlen(s);

	for(int i=0;i<=N;++i)
	{
		if(flag)
		{
			if(in(s[i]))
				temp[cou++]=s[i];
			else
			{
				temp[cou++]=0;
				printf("0k%s\n",temp);
				cou=flag=0;
			}
		}
		else
		{
			if(s[i]=='0' && s[i+1]=='k')
			{
				if(s[i+2]=='0')
				{
					printf("0k0\n");
					i+=2;
				}
				else if(in(s[i+2]))
				{
					flag=1;
					++i;
				}
			}
		}
	}
	
	return 0;
}
