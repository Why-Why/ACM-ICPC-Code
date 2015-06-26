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
// Created Time  : 2015年05月23日 星期六 21时42分26秒
// File Name     : 1002.cpp

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

char s[100005];
int k;
char ans[100005];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int len;
	int t,d;

	scanf("%d",&T);

	while(T--)
	{
		getchar();
		gets(s+1);
		scanf("%d",&k);

		len=strlen(s+1);
		t=len%k;
		d=len/k;

		for(int i=1;i<=len;++i)
		{
			if(i>t*(d+1))
				ans[((i-t*(d+1)-1)%d)*k+t+((i-t*(d+1))-1)/d+1]=s[i];
			else
				ans[((i-1)/(d+1))+1+((i-1)%(d+1))*k]=s[i];
		}

		ans[len+1]=0;
		printf("Case #%d:\n",cas++);
		puts(ans+1);
	}
	
	return 0;
}
