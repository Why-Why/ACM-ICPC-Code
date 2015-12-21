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
// Created Time  : 2015年11月28日 星期六 12时15分50秒
// File Name     : 1006.cpp

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

const int MaxN=10004;

int rem[200];
char s[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	scanf("%d",&T);

	while(T--) {
		scanf("%s",s);
		int ans=0x3f3f3f3f;
		memset(rem,-1,sizeof(rem));
		for(int i=0;s[i];++i) {
			if(rem[s[i]]!=-1) ans=min(ans,i-rem[s[i]]);
			rem[s[i]]=max(rem[s[i]],i);
		}

		if(ans==0x3f3f3f3f) ans=-1;

		printf("Case #%d: %d\n",cas++,ans);
	}
	
	return 0;
}
