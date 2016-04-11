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
// Created Time  : 2016年04月09日 星期六 22时27分37秒
// File Name     : jjj.cpp

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

const int wei=32;
const int TTT=500;

char s[1000];

bool judge(__int128 p,__int128 x) {
	__int128 t=0,base=1;
	for(int i=strlen(s)-1;i>=0;--i) {
		if(s[i]=='1') t+=base;
		(base*=p)%=x;
		t%=x;
	}

	if(t%x) { return 0; }
	return 1;
}

bool jjj(char s[]) {
	if(strlen(s)!=wei) return 0;
	return 1;
}

__int128 input() {
	char s[100];
	scanf("%s",s);
	__int128 ret=0;
	for(int i=0;s[i];++i)
		ret=ret*10+s[i]-'0';
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	__int128 x;

	gets(s);
	for(int i=1;i<=TTT;++i) {
		do {
			scanf("%s",s);
		}while(jjj(s)==0);
		for(int j=2;j<=10;++j) {
			//scanf("%lld",&x);
			x=input();
			if(judge(j,x)==0) cout<<i<<' '<<s<<' '<<j<<endl;
		}
		cout<<"YES\n";
	}
	
	return 0;
}
