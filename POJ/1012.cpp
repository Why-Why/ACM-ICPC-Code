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
// Created Time  : 2015年05月13日 星期三 14时59分35秒
// File Name     : 1012.cpp

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

int f[100];

bool judge(int k,int m)
{
	for(int i=0;i<k;++i)
	{
		f[i]=0;

		for(int j=i+1;j<=k+k;++j)
			f[j]=(f[j-1]+m-1)%j+1;

		if(f[k+k]>k)
			return 0;
	}

	return 1;
}

int ans[20]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
/*
	int k;

	while(~scanf("%d",&k) && k)
	{
		printf("%d\n",ans[k]);
	}*/

	int t,k;

	while(~scanf("%d",&k))
	{
		for(int i=1;;++i)
		{
			t=0;

			for(int j=1;j<=k+k;++j)
			{
				t=(t+i-1)%(k+k-j+1);

				cout<<t<<' ';
			}

			cout<<endl;
			getchar();
		}
	}
	
	return 0;
}
