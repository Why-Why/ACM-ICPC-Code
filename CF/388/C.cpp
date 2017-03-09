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
// Created Time  : 2017年01月15日 星期日 12时16分04秒
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

int N;
char s[MaxN];

bool vis[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	scanf("%s",s+1);

	int couD=0,couR=0;

	for(int i=1;i<=N;++i)
		if(s[i]=='D') ++couD;
		else ++couR;

	while(couR && couD) {
		int pR=0,pD=0;
		for(int i=1;i<=N;++i)
			if(!vis[i]) {
				if(s[i]=='D') {
					for(++pR;pR<=N;++pR)
						if(!vis[pR] && s[pR]=='R')
							break;
					if(pR<=N) vis[pR]=1,--couR;
				}
				else {
					for(++pD;pD<=N;++pD)
						if(!vis[pD] && s[pD]=='D')
							break;
					if(pD<=N) vis[pD]=1,--couD;
				}
			}
	}

	if(couR) puts("R");
	else puts("D");

	return 0;
}
