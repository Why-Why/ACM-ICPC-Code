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
// Created Time  : 2017年03月01日 星期三 20时13分31秒
// File Name     : tt.cpp

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

int map1[103][103];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	for(int i=1;i<100;++i)
		map1[i][i+1]=map1[i+1][i]=1;

	cout<<1<<endl;
	cout<<100<<endl;
	for(int i=1;i<=100;++i,cout<<endl)
		for(int j=1;j<=100;++j)
			cout<<map1[i][j]<<' ';

	return 0;
}
