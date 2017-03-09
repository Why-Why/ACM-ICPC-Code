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
// Created Time  : 2016年11月12日 星期六 10时54分17秒
// File Name     : F_1.cpp

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

const int mod=1000000007;

vector <int> num;

long long cal() {
	long long ret=1;
	for(int i=0;i<num.size();++i)
		(ret*=num[i])%=mod;
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int p=0;

	num.push_back(2);
	for(int i=2;i<=500;++i) {
		cout<<cal()<<endl;

		if(p>=0) {
			++num[p];
			--p;
		}
		else if(p==-1) {
			++num[num.size()-1];
			--p;
		}
		else {
			--num[num.size()-1];
			//num.push_front(2);
			num.insert(num.begin(),2);
			p=num.size()-1;
		}
	}

	return 0;
}
