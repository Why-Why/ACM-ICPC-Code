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
// Created Time  : 2015年05月08日 星期五 20时00分12秒
// File Name     : 1321.cpp

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

int n,k;
char s[20];
int map1[10][10];
int ans[10];

bool judge(int d,int x)
{
	for(int i=1;i<=d;++i)
		if(ans[i]==x)
			return 0;

	return 1;
}

long long dfs(int d,int k,int cou)
{
	if(k==0)
		return 1;

	if(d>n)
		return 0;

	long long ret=0;

	for(int i=1;i<=n;++i)
		if(!map1[d][i] && judge(cou,i))
		{
			ans[cou+1]=i;
			ret+=dfs(d+1,k-1,cou+1);
		}

	ret+=dfs(d+1,k,cou);

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&n,&k) && (n!=-1 || k!=-1))
	{
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s+1);

			for(int j=1;j<=n;++j)
				if(s[j]=='#')
					map1[i][j]=0;
				else
					map1[i][j]=1;
		}

		printf("%lld\n",dfs(1,k,0));
	}
	
	return 0;
}
