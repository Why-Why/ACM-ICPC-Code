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
// Created Time  : 2015年10月05日 星期一 11时12分00秒
// File Name     : ttt.cpp

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

char rem[10][5]={"AB","AC","BC","BA","CA","CB"};
int ans[10];

void change()
{
	for(int i=0;i<6;++i)
		ans[i]=i;

	for(int i=5;i>=0;--i)
		swap(ans[i],ans[rand()%(i+1)]);
}

int main()
{
	//freopen("in.txt","r",stdin);
freopen("in.txt","w",stdout);

	for(int i=0;i<30;++i)
	{
		cout<<3<<endl;
		change();
		for(int i=0;i<6;++i)
			cout<<rem[ans[i]]<<' ';
		cout<<endl;
	}
	
	return 0;
}
