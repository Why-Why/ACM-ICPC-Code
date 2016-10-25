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
// Created Time  : 2016年09月18日 星期日 12时14分58秒
// File Name     : 1005.cpp

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

long long ans[100];

long long _pow(int x,int n) {
	long long ret=1;
	for(int i=0;i<n;++i) ret*=x;
	return ret;
}

void cal(int n) {

	ans[n]=0;

	for(int i=0;i<(1<<(n-1));++i) {
		int cou=0,t=i;
		while(t) {
			if(t&1) ++cou;
			t>>=1;
		}

		ans[n]+=ans[n-1-cou]*_pow(cou+1,cou-1);
	}

}

//bool map1[100][100];
int rem1[100],rem2[100],rcou=0;
int fa[100];

int find(int x) {
	if(fa[x]==-1) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

bool hasH(int n,int sta) {
	int a,b;
	memset(fa,-1,sizeof(fa));

	for(int i=0;i<rcou;++i)
		if(sta&(1<<i)) {

			a=find(rem1[i]);
			b=find(rem2[i]);
			if(a==b) return 1;
			fa[a]=b;
		}

	return 0;
}

void _cal(int n) {
	int cou=0;
	rcou=0;

	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j) {
			rem1[rcou]=i;
			rem2[rcou++]=j;
		}

	for(int i=0;i<(1<<rcou);++i) {
		//memset(map1,0,sizeof(map1));
		//for(int j=0;j<rcou;++j)
			//if(i&(1<<j))
				//map1[rem1[j]][rem2[j]]=map1[rem2[j]][rem1[j]]=1;

		if(hasH(n,i)) ++cou;
	}

	ans[n]=cou;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ans[0]=1;
	ans[1]=1;
	ans[2]=2;

	for(int i=3;i<15;++i) {
		_cal(i);
		cerr<<ans[i]<<endl;
	}

	for(int i=1;i<15;++i) cout<<ans[i]<<' ';
	cout<<endl;

	return 0;
}
