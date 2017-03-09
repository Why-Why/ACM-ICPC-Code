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
// Created Time  : 2017年02月14日 星期二 10时32分56秒
// File Name     : G_1.cpp

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

/*
long long getans(int N,int p[]) {
	cout<<N<<endl;
	for(int i=1;i<=N;++i) cout<<p[i]<<' ';
	cout<<endl;

	if(p[1]==0) return 0;
	if(p[N]==0) {
		bool ok=1;
		for(int i=1;i<N;++i)
			if(p[i]!=i) ok=0;
		if(ok) return (1LL<<(N-1))-1;
	}

	int flag0=-1;
	for(int i=1;i<=N;++i) if(p[i]==0) flag0=i;

	int t[40],flag=-1;
	int vis[40]={};

	for(int i=1;i<=N;++i)
		if(p[i]+1>=flag0) {
			flag=i;
			break;
		}
		else vis[p[i]]=i;

	int tp=1;

	for(int i=1;i<=N;++i)
		if(vis[i])
			t[vis[i]]=i;
	t[flag]=0;

	long long ret=getans(flag,t)+1;

	for(int i=1;i<=N;++i) t[i]=-1;
	for(int i=1;i<flag;++i)
		t[p[i]]=p[i];

	tp=1;
	for(int i=flag+1;i<N;++i) {
		while(t[tp]!=-1) ++tp;
		t[tp]=p[i];
	}

	t[N-1]=0;
	return ret+getans(N-1,t);

	int t[40];
	int rem[40],rcou=0;
	int flag=-1;

	for(int i=1;i<=N;++i)
		if(p[i]==0) flag=i;
		else if(flag!=-1) rem[rcou++]=p[i];

	sort(rem,rem+rcou);
	int tp=0;

	t[flag]=0;
	for(int i=flag-1;i>=1;--i)
		if(p[i]>=flag) t[i]=rem[tp++];
		else t[i]=p[i];

	return getans(flag,t);

}
*/

long long getans(int N,int p[]) {
	cout<<N<<endl;
	for(int i=1;i<N;++i) cout<<p[i]<<' ';
	cout<<endl;
	if(p[1]==0) return 0;


	int ok=1;
	for(int i=1;i<N;++i)
		if(p[i]!=i) {
			ok=0;
			break;
		}
	if(ok) return (1LL<<(N-1))-1;

	int t[40],flag=-1;
	long long ret=0;

	for(int i=1;i<N;++i)
		if(p[i]+1>=N) {
			ret+=getans(i,t)+1;
			flag=i;
			break;
		}
		else t[i]=p[i];

	for(int i=1;i<=N;++i) t[i]=-1;
	for(int i=1;i<flag;++i)
		t[p[i]]=p[i];

	int tp=1;
	for(int i=flag+1;i<N;++i) {
		while(t[tp]!=-1) ++tp;
		t[tp]=p[i];
	}

	return ret+getans(N-1,t);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,p[40];

	while(~scanf("%d",&N)) {
		int flag=-1;
		for(int i=1;i<=N;++i) {
			scanf("%d",p+i);
			if(p[i]==0) flag=i;
		}
		printf("%lld\n",getans(flag,p));
	}

	return 0;
}
