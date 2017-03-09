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
// Created Time  : 2017年02月24日 星期五 12时00分23秒
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

const int MaxN=100005;
typedef pair<int,int> pii;

int N,M;
pii range[MaxN];
int pos[MaxN];
priority_queue <int> que;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&M);
		for(int i=1;i<=N;++i) scanf("%d %d",&range[i].first,&range[i].second);
		for(int i=1;i<=M;++i) scanf("%d",pos+i);
		sort(range+1,range+N+1);
		sort(pos+1,pos+M+1);
		while(!que.empty()) que.pop();

		int ans=0;
		for(int i=1,p=1;i<=M;++i) {
			while(p<=N && range[p].first<=pos[i]) {
				que.push(-range[p].second);
				++p;
			}
			while(!que.empty() && -que.top()<pos[i]) que.pop();			// !!!

			ans=max(ans,int(N-que.size()+1));
			if(!que.empty()) que.pop();
		}

		printf("Case #%d: ",cas++);
		if(ans>N) puts("IMPOSSIBLE!");
		else printf("%d\n",ans);
	}

	return 0;
}
