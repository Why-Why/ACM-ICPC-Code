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
// Created Time  : 2016年10月03日 星期一 10时05分16秒
// File Name     : E.cpp

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

long long a,b,c;

long long getans() {
	if(a && b) return 3*c+2*b+a;
	if(a==0 && b==0) return c;
	if(a>=2) return 3*c+a;
	if(a==1) return 2*c+1;
	if(b==1) return 2*c+1;

	if(c) return 3*c-1+2*b-1;
	return b;
}

long long ggg() {
	set <long long> rem;

	for(int i=0;i<=a;++i)
		for(int j=0;j<=b;++j)
			for(int k=0;k<=c;++k)
				rem.insert(i+2*j+3*k);

	return rem.size()-1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	/*
	int T=10;

	for(a=0;a<=T;++a)
		for(b=0;b<=T;++b)
			for(c=0;c<=T;++c)
				if(getans()!=ggg())
					cout<<a<<' '<<b<<' '<<c<<" : "<<getans()<<' '<<ggg()<<endl;

	return 0;
	*/

	scanf("%lld %lld %lld",&a,&b,&c);
	printf("%lld\n",getans());

	return 0;
}
