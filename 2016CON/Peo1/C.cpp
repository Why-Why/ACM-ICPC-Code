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
// Created Time  : 2016年02月20日 星期六 13时21分38秒
// File Name     : C.cpp

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

const int MaxN=1000006;
const int mod=1000000007;

long long p,k;
bool vis[MaxN];

int search(int u) {
	int t=u;
	int ret=0;

	while(!vis[u]) {
		vis[u]=1;
		u=k*u%p;
		++ret;
	}

	return ret;
}

long long cou[MaxN];

long long _pow(long long a,long long b) {
	if(!b) return 1;

	long long base=a,ret=1;
	while(b) {
		if(b&1) (ret*=base)%=mod;
		(base*=base)%=mod;
		b>>=1;
	}
	return ret;
}

long long getnum(int x) {
	long long ret=0;
	for(long long i=1;i<=x;++i)
		if(x%i==0) ret+=i*cou[i];
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>p>>k;
	
	long long ans=1;

	if(!k) ans=_pow(p,p-1);
	else {
		for(int i=0;i<p;++i)
			if(!vis[i])
				++cou[search(i)];

		for(long long i=1;i<=p;++i)
			if(cou[i])
				(ans*=_pow(getnum(i),cou[i]))%=mod;
	}

	cout<<ans<<endl;
	
	return 0;
}
