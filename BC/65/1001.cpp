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
// Created Time  : 2015年12月05日 星期六 19时01分25秒
// File Name     : 1001.cpp

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

int N,T;
char s1[200],s2[200];
char pei[300];

bool getans() {
	for(int i=0;i<N;++i)
		if(pei[s1[i]]!=s2[i]) return 0;
	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	pei['A']='U';
	pei['T']='A';
	pei['C']='G';
	pei['G']='C';

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		scanf("%s %s",s1,s2);
		if(getans()) puts("YES");
		else puts("NO");
	}
	
	return 0;
}
