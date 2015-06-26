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
// Created Time  : 2015年06月03日 星期三 20时13分19秒
// File Name     : B.cpp

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

char s[100005],ts[100005];
int rem[20];
int len;

void getans1()
{
	int maxn=0;

	for(int i=1;i<len;++i)
	{
		++rem[s[i]-'0'];
		maxn=max(maxn,s[i]-'0');
	}

	int i;

	for(i=1;i<len;++i)
	{
		if(s[i]-'0'!=maxn)
			break;

		--rem[s[i]-'0'];

		while(rem[maxn]==0)
			--maxn;
	}

	if(i<=len)
	{
		for(int j=i+1;j<=len;++j)
			if(maxn==s[j]-'0')
			{
				swap(s[j],s[i]);
				return;
			}
	}
}

void getans2()
{
	for(int i=1;i<len;++i)
		if(((ts[i]-'0')&1)==0 && ts[i]<ts[len])
		{
			swap(ts[i],ts[len]);

			return;
		}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int temp;
	int maxn;

	scanf("%s",s+1);
	strcpy(ts,s);

	len=strlen(s+1);

	if((s[len]-'0')&1)
	{
		temp=-1;

		for(int i=1;i<len;++i)
			if(((s[i]-'0')&1)==0 && s[i]-'0'<s[len]-'0')
			{
				temp=i;
				break;
			}

		if(temp!=-1)
			swap(s[temp],s[len]);
		else
		{
			for(int i=len-1;i>=1;--i)
				if(((s[i]-'0')&1)==0)
				{
					temp=i;
					break;
				}

			if(temp==-1)
			{
				puts("-1");
				return 0;
			}

			swap(s[temp],s[len]);
		}

		puts(s+1);
	}
	else
	{
		getans1();
		getans2();

		if(strcmp(s+1,ts+1)>0)
			puts(s+1);
		else
			puts(ts+1);
	}

	return 0;
}
