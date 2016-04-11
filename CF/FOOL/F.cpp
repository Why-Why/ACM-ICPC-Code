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
// Created Time  : 2016年04月02日 星期六 01时46分11秒
// File Name     : F.cpp

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

char s[1000000];
char tt[1000],ttt[10000];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	bool first=0;

	for(int i=1;i<=4;++i) gets(s);
	while(gets(s) && s) {
		sscanf(s,"%s",tt);
		bool ok=0;
		int cou=0;

		for(int i=0;s[i];++i)
			if(s[i]==',') {
				if(ok==0) {
					ok=1;
				}
				else break;
			}
			else if(ok) ttt[cou++]=s[i];
		ttt[cou]=0;

		if(first) first==0;//cout<<"{";
		else cout<<" ";
		long long a;
		if(ttt[0]==0) a=0;
		else sscanf(ttt,"%lld",&a);
		cout<<a;
	}
	//cout<<"}\n";
	
	return 0;
}
