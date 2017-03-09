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
// Created Time  : 2017年02月21日 星期二 18时52分34秒
// File Name     : t.cpp

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

int len=5;

void change(char s[],int t) {
	for(int i=len-1;i>=0;--i,t>>=1)
		s[i]='0'+(t&1);
	s[len]=0;
}

bool judge1(char s[],int len) {
	for(int i=0;i<len;++i)
		if(s[i]!=s[len-1-i]) return 0;
	return 1;
}

bool judge(char s[]) {
	char ts[100];
	int cou=0;

	for(int i=0;i<len;i+=2) ts[cou++]=s[i];
	if(judge1(ts,cou)) return 1;

	cou=0;
	for(int i=1;i<len;i+=2) ts[cou++]=s[i];
	if(judge1(ts,cou)) return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	for(int i=0;i<(1<<len);++i) {
		char s[20];
		change(s,i);

		if(judge(s)) cout<<s<<endl;
	}

	return 0;
}
