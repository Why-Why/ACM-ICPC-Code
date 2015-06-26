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
// Created Time  : 2015年06月19日 星期五 01时28分29秒
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

long long pre[20];
long long base[20];

void init()
{
	pre[1]=9;
	base[1]=1;

	for(int i=2;i<=10;++i)
	{
		pre[i]=pre[i-1]*10;
		base[i]=base[i-1]*10;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char s[100];
	
	init();

	scanf("%s",s);
	
	long long num;
	long long ans=0;
	int len=strlen(s);

	num=0;

	for(int i=0;s[i];++i)
		num=num*10LL+s[i]-'0';

	for(int i=1;i<len;++i)
		ans+=i*pre[i];

	ans+=len*(num+1LL-base[len]);

	cout<<ans<<endl;
	
	return 0;
}
