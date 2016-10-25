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
// Created Time  : 2016年09月22日 星期四 23时27分58秒
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

const int MaxN=(1<<18)+5;

int cou[MaxN];

inline int getnum(char s[]) {
	int ret=0,base=1;
	for(int i=strlen(s)-1;i>=0;--i,base<<=1)
		if((s[i]-'0')&1)
			ret+=base;
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	char s[10],num[22];
	int t;

	scanf("%d",&T);

	while(T--) {
		scanf("%s %s",s,num);
		t=getnum(num);

		if(s[0]=='+') ++cou[t];
		else if(s[0]=='-') --cou[t];
		else printf("%d\n",cou[t]);
	}

	return 0;
}
