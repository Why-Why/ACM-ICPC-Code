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
// Created Time  : 2016年04月20日 星期三 23时01分39秒
// File Name     : C.cpp

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

const int MaxN=200005;

char s[MaxN],ans[MaxN];

inline char nn(int p) {
	for(char c='a';c<='z';++c)
		if(c!=s[p-1] && c!=s[p+1]) return c;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cou=1,last=0;
	int begin;
	scanf("%s",s);
	int len=strlen(s);

	for(int i=1;i<=len;++i) {
		if(s[i]==s[i-1]) ++cou;
		else {
			if(cou&1) begin=1;
			else begin=0;

			for(int j=last;j<i;++j) {
				if((j-last)%2==begin) ans[j]=nn(j);
				else ans[j]=s[j];
			}

			cou=1;
			last=i;
		}
	}

	printf("%s\n",ans);
	
	return 0;
}
