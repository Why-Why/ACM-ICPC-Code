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
// Created Time  : 2016年09月23日 星期五 21时12分58秒
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

char s[200005],ts[200005];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,t;

	scanf("%d %d",&N,&t);
	scanf("%s",s);

	if(s[0]=='.') {
		ts[0]='0';
		strcpy(ts+1,s);
		strcpy(s,ts);
	}

	bool ok=0;
	int pos=-1;

	for(int i=0;s[i];++i) {
		if(ok) {
			if(s[i]>='5') {
				pos=i;
				break;
			}
		}

		if(s[i]=='.') ok=1;
	}

	if(pos==-1) {
		puts(s);
		return 0;
	}

	int end=-1;

	for(int i=pos-1;;--i) {
		if(s[i]=='.') {
			++s[i-1];
			end=i;
			break;
		}

		--t;
		++s[i];
		end=i;

		if(t==0) break;
		if(s[i]<'5') break;
	}

	if(s[end]=='.') {
		for(int i=end-1;i>=1;--i)
			if(s[i]>'9') s[i]='0',++s[i-1];

		if(s[0]>'9') s[0]='0',putchar('1');
		--end;
	}

	for(int i=0;i<=end;++i) putchar(s[i]);
	puts("");

	return 0;
}
