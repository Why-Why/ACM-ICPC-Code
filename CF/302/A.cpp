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
// Created Time  : 2015年06月04日 星期四 23时03分29秒
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

char s[1000];
int k;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int rem[30]={0};

	scanf("%d %s",&k,s);

	for(int i=0;s[i];++i)
		++rem[s[i]-'a'];

	int cou=0;

	for(int i=0;i<26;++i)
		if(rem[i])
			++cou;

	if(cou<k)
	{
		puts("NO");
		return 0;
	}

	printf("YES");

	for(int i=0;s[i];++i)
	{
		if(k && rem[s[i]-'a'])
		{
			--k;
			printf("\n%c",s[i]);
			rem[s[i]-'a']=0;
		}
		else
			printf("%c",s[i]);
	}

	puts("");
	
	return 0;
}
