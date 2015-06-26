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
// Created Time  : 2015年05月21日 星期四 19时54分44秒
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

char s[100005],t[100005];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%s %s",s,t);

	int cou=0;

	for(int i=0;s[i];++i)
		if(s[i]!=t[i])
			++cou;

	if(cou&1)
	{
		puts("impossible");
		return 0;
	}

	cou>>=1;

	for(int i=0;s[i];++i)
		if(s[i]!=t[i])
		{
			if(cou>0)
				printf("%c",s[i]);
			else
				printf("%c",t[i]);

			--cou;
		}
		else
			printf("%c",s[i]);
	puts("");
	
	return 0;
}
