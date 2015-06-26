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
// Created Time  : 2015年06月15日 星期一 22时07分01秒
// File Name     : 3096.cpp

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

char s[200];
set <int> sta;

bool judge()
{
	int temp;
	int len=strlen(s);

	for(int i=0;i<len-1;++i)
	{
		sta.clear();

		for(int j=0;j+i+1<len;++j)
		{
			temp=s[j]*1000+s[j+i+1];

			if(sta.count(temp))
				return 0;

			sta.insert(temp);
		}
	}

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	while(~scanf("%s",s) && s[0]!='*')
	{
		printf("%s",s);

		if(judge())
			puts(" is surprising.");
		else
			puts(" is NOT surprising.");
	}

	return 0;
}
