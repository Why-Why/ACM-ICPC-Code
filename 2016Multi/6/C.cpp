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
// Created Time  : 2016年09月16日 星期五 21时35分30秒
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

int sg[10000];

int getSG(int p) {
	set <int> rem;

	for(int i=0;i<p;++i) rem.insert(sg[i]);
	for(int i=1;i<=p;++i)
		for(int j=1;j<=p;++j)
			if(i+j<p) {
				rem.insert(sg[i]^sg[j]^sg[p-i-j]);
			}

	for(int i=0;;++i)
		if(rem.count(i)==0) return i;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T=100;

	sg[0]=0;
	sg[1]=1;
	sg[2]=2;

	for(int i=3;i<T;++i)
		sg[i]=getSG(i);

	for(int i=0;i<T;++i)
		if(i!=sg[i]) cout<<i<<' '<<sg[i]<<endl;

	return 0;
}
