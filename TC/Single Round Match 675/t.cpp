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
// Created Time  : 2015年12月10日 星期四 20时30分41秒
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

void hhh(int s) {
		int t,d,n;
		int k=-1;
		for(int i=1;i<=500;++i) {
			d=13-4*i+4*s;
			if(d<0) continue;
			t=(int)sqrt((double)d);
			if(t*t!=d) continue;
			if(t!=1 && (3+t)%2) continue;
			if(t==1 && i>=3) { k=1; n=i; break; }
			if((3+t)>i-1) continue;
			k=(3+t)/2;
			n=i;
			break;
		}
		if(k==-1) printf("NO %d\n",s);
		cout<<k<<endl;
    }

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	for(int i=1;i<=10000;++i)
		hhh(i);
	
	return 0;
}
