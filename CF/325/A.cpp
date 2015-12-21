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
// Created Time  : 2015年10月12日 星期一 17时18分50秒
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

int num[110];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",num+i);

	int p=-1;
	for(int i=1;i<=n;++i)
		if(num[i])
		{
			p=i;
			break;
		}

	if(p==-1)
	{
		puts("0");
		return 0;
	}

	int d;
	for(int i=n;i>=1;--i)
		if(num[i])
		{
			d=i;
			break;
		}

	int ans=0;

	for(int i=p;i<=d;++i)
	{
		if(num[i]) ++ans;
		else
		{
			if(num[i-1] && num[i+1]) ++ans;
		}
	}

	printf("%d\n",ans);
	
	return 0;
}
