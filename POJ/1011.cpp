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
// Created Time  : 2015年05月10日 星期日 11时11分25秒
// File Name     : 1011.cpp

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

int N;
int num[100];
bool vis[100];
int len,bian;

bool dfs(int duan,int chang,int kai)
{
	if(duan==bian)
		return 1;

	for(int i=kai;i<=N;++i)
	{
		if(vis[i])
			continue;

		if(vis[i-1]==0 && num[i]==num[i-1])
			continue;

		if(chang<num[i])
			continue;
		else if(chang==num[i])
		{
			vis[i]=1;
			
			if(dfs(duan+1,len,1))
				return 1;
			else if(chang==len)
			{
				vis[i]=0;
				return 0;
			}

			vis[i]=0;
		}
		else
		{
			vis[i]=1;

			if(dfs(duan,chang-num[i],i))
				return 1;
			else if(chang==len)
			{
				vis[i]=0;
				return 0;
			}

			vis[i]=0;
		}
	}

	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int sum;

	while(~scanf("%d",&N) && N)
	{
		sum=0;

		for(int i=1;i<=N;++i)
		{
			scanf("%d",&num[i]);
			sum+=num[i];
		}

		len=sum;

		sort(num+1,num+N+1,greater<int>());

		for(int i=num[1];i<=sum;++i)
			if(sum % i==0)
			{
				memset(vis,0,sizeof(vis));
				vis[0]=1;
				len=i;
				bian=sum/i;
				
				if(dfs(1,len,1))
				{
					printf("%d\n",i);
					break;
				}
			}
	}
	
	return 0;
}
