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
// Created Time  : 2017年03月01日 星期三 18时36分36秒
// File Name     : J.cpp

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int MaxL=1700000;

queue <int> que;
int inque[MaxL];

struct State {
	bool num[MaxL];
	int size;

	void clear() {
		size=0;
		while(!que.empty()) que.pop();
		memset(num,0,sizeof(num));
		memset(inque,0,sizeof(inque));
	}

	void insert(int x) {
		if(num[x]) return;
		if(!inque[x]) {
			que.push(x);
			inque[x]=1;
		}
		num[x]=1;
		++size;
	}

	void erase(int x) {
		if(!num[x]) return;
		num[x]=0;
		--size;
	}

	int get() {
		while(!que.empty() && num[que.front()]==0) {
			inque[que.front()]=0;
			que.pop();
		}
		return que.front();
	}

}rem;

int map1[30000];
int ans;
int N;

inline bool judge(int a,int b,int c) {
	if(a>b) swap(a,b);
	if(a>c) swap(a,c);
	if(b>c) swap(b,c);
	return map1[(a<<7)+b]+map1[(b<<7)+c]+map1[(a<<7)+c]==2;
}

inline int change(int a,int b,int c) {
	if(a>b) swap(a,b);
	if(a>c) swap(a,c);
	if(b>c) swap(b,c);
	return (a<<14)+(b<<7)+c;
}

void dfs(int dep) {
	if(dep>=ans) return;
	if(rem.size==0) {
		ans=dep;
		return;
	}
	if(dep>=10) return;

	int t=rem.get();
	int a,b,c;

	a=t>>14;
	b=(t>>7) & 127;
	c=t & 127;

	rem.erase(t);

	/////////////////////

	map1[(a<<7)+b]=!map1[(a<<7)+b];
	for(int i=1;i<=N;++i)
		if(i!=a && i!=b && i!=c)
			if(judge(i,a,b)) rem.insert(change(i,a,b));
			else rem.erase(change(i,a,b));

	dfs(dep+1);

	map1[(a<<7)+b]=!map1[(a<<7)+b];
	for(int i=1;i<=N;++i)
		if(i!=a && i!=b && i!=c)
			if(judge(i,a,b)) rem.insert(change(i,a,b));
			else rem.erase(change(i,a,b));

	map1[(a<<7)+c]=!map1[(a<<7)+c];
	for(int i=1;i<=N;++i)
		if(i!=a && i!=b && i!=c)
			if(judge(i,a,c)) rem.insert(change(i,a,c));
			else rem.erase(change(i,a,c));

	dfs(dep+1);

	map1[(a<<7)+c]=!map1[(a<<7)+c];
	for(int i=1;i<=N;++i)
		if(i!=a && i!=b && i!=c)
			if(judge(i,a,c)) rem.insert(change(i,a,c));
			else rem.erase(change(i,a,c));

	map1[(b<<7)+c]=!map1[(b<<7)+c];
	for(int i=1;i<=N;++i)
		if(i!=a && i!=b && i!=c)
			if(judge(i,b,c)) rem.insert(change(i,b,c));
			else rem.erase(change(i,b,c));

	dfs(dep+1);

	map1[(b<<7)+c]=!map1[(b<<7)+c];
	for(int i=1;i<=N;++i)
		if(i!=a && i!=b && i!=c)
			if(judge(i,b,c)) rem.insert(change(i,b,c));
			else rem.erase(change(i,b,c));

	rem.insert(t);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int t,a,b,c;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		rem.clear();

		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				scanf("%d",&map1[(i<<7)+j]);

		for(int i=1;i<=N;++i)
			for(int j=i+1;j<=N;++j)
				for(int k=j+1;k<=N;++k)
					if(judge(i,j,k))
						rem.insert((i<<14)+(j<<7)+k);

		ans=100;

		if(rem.size<=20*N) dfs(0);

		if(ans>10) ans=-1;
		printf("Case #%d: %d\n",cas++,ans);
	}

	return 0;
}
