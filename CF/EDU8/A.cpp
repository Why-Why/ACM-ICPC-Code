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
// Created Time  : 2016年02月19日 星期五 23时05分16秒
// File Name     : A.cpp

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

long long n,b,p;

void getans(long long n,long long &a1,long long &a2) {
	if(n==1) {
		a1=a2=0;
		return;
	}

	int cou=0;
	int t=n;
	while(t) ++cou,t>>=1;
	--cou;
	t=1<<cou;
	getans(t/2+n-t,a1,a2);
	a1+=t/2+t*b;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>n>>b>>p;
	long long ans1=0,ans2=0;

	getans(n,ans1,ans2);
	ans2=n*p;
	cout<<ans1<<' '<<ans2<<endl;
	
	return 0;
}
