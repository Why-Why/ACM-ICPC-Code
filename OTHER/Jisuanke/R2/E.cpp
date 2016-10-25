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
// Created Time  : 2016年07月03日 星期日 13时44分31秒
// File Name     : E.cpp

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

char s[10004];
char ans[10004];
int cou;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%s",s);
	if(s[0]=='0' && s[1]==0) {
		puts("0 0 0");
		return 0;
	}
	int t=0;
	for(int i=0;s[i];++i) t+=(s[i]-'0');
	if(t%3) puts("-1");
	else {
		int r=0;
		bool b=0;
		for(int i=0;s[i];++i) {
			t=s[i]-'0'+r*10;
			if(t/3) b=1;
			if(b) ans[cou++]=t/3+'0';
			r=t%3;
		}
		printf("%s %s %s\n",ans,ans,ans);
	}
	
	return 0;
}
