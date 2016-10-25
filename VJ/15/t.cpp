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
// Created Time  : 2016年09月21日 星期三 13时01分31秒
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

bool judge(long long x) {
	if(x%7==0) return 0;
	int sum=0;
	for(;x;x/=10) {
		if(x%10==7) return 0;
		sum+=x%10;
	}

	if(sum%7==0) return 0;
	return 1;
}

long long getans(long long x) {
	long long ret=0;
	for(int i=1;i<=x;++i) if(judge(i)) ret+=i*i;
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long x;

	while(cin>>x) {
		x=getans(x);
		cout<<x<<' '<<x%1000000007<<endl;
	}

	return 0;
}
