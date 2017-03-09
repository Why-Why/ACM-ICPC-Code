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
// Created Time  : 2015年09月20日 星期日 21时42分11秒
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

const int MaxN=1000006;

char s[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	scanf("%d",&T);
	bool ok,have;
	int cou;
	int qcou;
	int ans;

	while(T--)
	{
		ans=0;
		scanf("%s",s);
		ok=1;

		qcou=0;
		have=0;
		for(int i=0;s[i];++i)
			if(s[i]=='c')
			{
				have=1;
				++ans;
			}
			else if(s[i]=='f' && have==0)
				++qcou;
			else if(s[i]!='c' && s[i]!='f')
				ok=0;

		cou=0;
		have=0;
		for(int i=strlen(s)-1;i>=0;--i)
			if(s[i]=='c')
			{
				if(cou<2)
					if(have==1 || qcou+cou<2)
					{
						ok=0;
						break;
					}
				have=1;
				cou=0;
			}
			else if(s[i]=='f') ++cou;
			else ok=0;

		if(ans==0) ans=(strlen(s)+1)/2;

		printf("Case #%d: ",cas++);

		if(ok) printf("%d\n",ans);
		else printf("-1\n");
	}
	
	return 0;
}
