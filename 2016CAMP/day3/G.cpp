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
// Created Time  : 2017年02月14日 星期二 10时17分40秒
// File Name     : G.cpp

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

inline void change(int p[],int N) {
	int t[40];
	for(int i=2;i<=p[1]+1;++i) t[i-1]=p[i];
	int base=p[1];
	t[p[1]+1]=p[1];

	for(int i=1;i<=base+1;++i)
		p[i]=t[i];
}

int _main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;
	int p[40];

	scanf("%d",&N);
	for(int i=1;i<=N;++i) scanf("%d",p+i);

	int ans=0;
	int tmp;
	bool ok=0;
	for(;p[1];++ans) {
		int flag=-1;
		for(int i=1;i<=N;++i) {
			if(p[i]!=i) {
				flag=i;
				break;
			}
		}

		ans+=(1LL<<(flag-1))-1;
		tmp=p[flag];
		for(int i=flag;i>1;--i)
			p[i]=p[i-1];
		p[1]=tmp;

		if(!tmp) --ans;

		/*
		if(ok) {
			ans+=(1LL<<(flag-1))-1;
			break;
		}
		*/

		change(p,N);

		//for(int i=1;i<=N;++i) cout<<p[i]<<' ';
		//cout<<endl;
	}
	printf("%d\n",ans);

	return 0;
}

int main() {
		_main();
}
