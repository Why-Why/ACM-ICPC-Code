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
// Created Time  : 2016年09月23日 星期五 00时14分35秒
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

int map1[10][10];
int N=5;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	map1[2][2]=1;
	map1[3][4]=map1[3][5]=1;

	int a,b,c,d;

	while(cin>>a>>b>>c>>d) {
		int cou=0;
		if(a<=2 && c>=2 && b<=2 && d>=2) ++cou;
		if(a<=3 && c>=3 && b<=4 && d>=5) ++cou;
		cout<<cou<<endl;
	}

	return 0;
}
