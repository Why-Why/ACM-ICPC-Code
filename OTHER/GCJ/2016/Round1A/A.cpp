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
// Created Time  : 2016年04月16日 星期六 09时06分02秒
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

const int MaxN=1005;

char s[MaxN];
char maxn[MaxN];
bool vis[MaxN];
char ans[MaxN];
int acou;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	scanf("%d",&T);

	while(T--) {
		scanf("%s",s+1);
		memset(vis,0,sizeof(vis));
		maxn[0]=0;
		int len=strlen(s+1);
		for(int i=1;i<=len;++i) maxn[i]=max(maxn[i-1],s[i]);
		acou=0;
		for(int i=len;i>=1;--i)
			if(maxn[i]==s[i])
				ans[acou++]=s[i],vis[i]=1;
		for(int i=1;i<=len;++i)
			if(vis[i]==0) ans[acou++]=s[i];
		ans[acou++]=0;

		printf("Case #%d: %s\n",cas++,ans);
	}
	
	return 0;
}
