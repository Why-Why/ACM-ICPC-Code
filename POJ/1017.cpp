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
// Created Time  : 2015年05月26日 星期二 15时16分01秒
// File Name     : 1017.cpp

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

int num[10];

void jian(int x)
{
	if(num[2]>=x)
		num[2]-=x;
	else
	{
		num[1]-=(x-num[2])*4;
		num[2]=0;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t;

	while(~scanf("%d %d %d %d %d %d",num+1,num+2,num+3,num+4,num+5,num+6))
	{
		int sum=0;

		for(int i=1;i<=6;++i)
			sum+=num[i];

		if(!sum)
			break;

		sum=num[5]+num[4]+num[6];

		if(num[3])
			sum+=(num[3]-1)/4+1;

		jian(num[4]*5);

		num[1]-=num[5]*11;

		if(num[3]%4)
		{
			t=num[3]%4;

			if(t==1)
			{
				jian(5);
				num[1]-=7;
			}
			else if(t==2)
			{
				jian(3);
				num[1]-=6;
			}
			else if(t==3)
			{
				jian(1);
				num[1]-=5;
			}
		}

		if(num[2]>0)
		{
			sum+=(num[2]-1)/9+1;
			num[2]%=9;
		}

		if(num[2])
			num[1]-=36-num[2]*4;

		if(num[1]>0)
			sum+=(num[1]-1)/36+1;

		printf("%d\n",sum);
	}
	
	return 0;
}
