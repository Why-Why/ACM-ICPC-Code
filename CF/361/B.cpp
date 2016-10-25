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
// Created Time  : 2016年07月13日 星期三 21时41分35秒
// File Name     : B.cpp

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

const int MaxN=200005;
const int INF=0x3f3f3f3f;

typedef pair<int,int> pii;

pii rem[MaxN];
int N;
priority_queue<int,vector<int>,greater<int> > que;

int ans[MaxN];

bool judge() {
	while(!que.empty()) que.pop();

	que.push(-1);
	ans[1]=0;

	int p=1;
	int minn;
	bool flag=0;
	sort(rem+1,rem+N+1);

	for(int i=2;i<=N;++i) {
		minn=ans[i];
		while(p<=N && rem[p].first<=i) {
			if(rem[p].second!=rem[p].first) minn=min(minn,ans[rem[p].second]+1);
			++p;
		}

		minn=min(minn,que.top()+i);
		que.push(minn-i);
		if(ans[i]>minn) flag=1;
		ans[i]=minn;
	}

	while(!que.empty()) que.pop();
	que.push(ans[N]+N);
	for(int i=N-1;i>=1;--i) {
		if(ans[i]>que.top()-i) flag=1;
		ans[i]=min(ans[i],que.top()-i);
		que.push(ans[i]+i);
	}

	return flag;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<=N;++i) {
		scanf("%d",&rem[i].first);
		rem[i].second=i;
	}
	memset(ans,0x3f,sizeof(ans));
	while(judge());

	for(int i=1;i<=N;++i) printf("%d ",ans[i]);

	puts("");
	
	return 0;
}
