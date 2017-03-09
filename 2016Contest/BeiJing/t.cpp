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
// Created Time  : 2017年03月06日 星期一 00时08分45秒
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

bool vis[100000];

void show(int x,int N) {
	for(int i=N-1;i>=0;--i)
		if(x&(1<<i)) putchar('1');
		else putchar('0');
	puts("");
}

map <int,int> sta;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M=5;
	int a,b,c;

	cin>>M;

	int BASE=(1<<M)-1;
	int maxn=0;
	int cou=0;

	for(int i=0;i<(1<<M);++i) {
		a=0;
		b=i;

		for(int j=1;;++j) {
			cout<<j<<' ';
			show(b,M);

			c=a^b^(b<<1)^(b>>1);
			c&=BASE;
			a=b;
			b=c;

			if(a==0) {
				maxn=max(maxn,j);

				if(maxn%j) cerr<<"NO\n";
				++sta[j];

				if(vis[j]==0) {
					vis[j]=1;
					++cou;
				}
				break;
			}
		}

		cout<<endl;
	}
	//cerr<<cou<<endl;
	//cerr<<maxn<<endl;

	for(auto x:sta) cout<<x.first<<' '<<x.second<<endl;
	cout<<endl;

	return 0;
}
