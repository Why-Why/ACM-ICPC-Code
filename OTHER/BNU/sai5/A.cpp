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
// Created Time  : 2015年10月07日 星期三 10时54分20秒
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

string num[10];
char ts[10];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int a,b,c;

	scanf("%d",&T);
	while(T--)
	{
		ts[3]=0;
		scanf("%d %d %d",&a,&b,&c);
		ts[0]=a,ts[1]=b,ts[2]=c;
		num[0]=ts;
		ts[0]=a,ts[1]=c,ts[2]=b;
		num[1]=ts;
		ts[0]=b,ts[1]=a,ts[2]=c;
		num[2]=ts;
		ts[0]=b,ts[1]=c,ts[2]=a;
		num[3]=ts;
		ts[0]=c,ts[1]=a,ts[2]=b;
		num[4]=ts;
		ts[0]=c,ts[1]=b,ts[2]=a;
		num[5]=ts;

		sort(num,num+6);
		int t=unique(num,num+6)-num;
		printf("Case #%d:\n",cas++);
		for(int i=0;i<t;++i)
			printf("%d %d %d\n",(int)num[i][0],(int)num[i][1],(int)num[i][2]);
	}
	
	return 0;
}
